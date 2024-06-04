#version 440 core

struct Light{
    vec3 position;
    vec3 direction;
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float constant;
    float linear;
    float quadratic;
};

uniform vec2 windowSize;
uniform sampler2D textureSampler;
uniform float opacity;
uniform vec3 ambient;
uniform vec3 diffuse;
uniform vec3 sunPosition;
uniform vec3 moonPosition;
uniform vec3 camPosition;
uniform vec3 camDirection;
uniform float cutOff;
uniform float outerCutOff;
uniform bool lanternOn;

in vec2 uvsFragmentShader;
in vec3 normalsFragmentShader;
in vec4 primitivePosition;

out vec4 fragColor;

void main() {
    vec2 adjustedTexCoord = vec2(uvsFragmentShader.x, 1.0 - uvsFragmentShader.y);
    vec4 baseColor = texture(textureSampler, adjustedTexCoord);

    // CAM LIGHT (Lantern)
    vec3 lanternIntensity = vec3(0.0f);
    vec3 lightDirectionCam = normalize(camDirection); // Direction the camera is pointing
    vec3 fragmentToCam = normalize(camPosition - primitivePosition.xyz); // Direction from fragment to camera
    float camLightAngle = dot(fragmentToCam, lightDirectionCam);

    if(lanternOn && (camLightAngle > outerCutOff)){
        float epsilon = (cutOff - outerCutOff);
        float intensity = clamp((camLightAngle - outerCutOff) / epsilon, 0.0, 1.0);
        lanternIntensity = diffuse * intensity  * ambient;
    }

    // SUN LIGHT
    vec3 lightDirection = normalize(sunPosition - primitivePosition.xyz);
    float sourceLightAngle = max(dot(normalsFragmentShader, lightDirection), 0.0);
    float distance = length(sunPosition - primitivePosition.xyz);
    float constant = 1.0;
    float linear = 0.00007;  // Reduced linear attenuation
    float quadratic = 0.000002;  // Reduced quadratic attenuation
    float attenuation = 1.0 / (constant + linear * distance + quadratic * distance * distance);
    vec3 lightIntensity = vec3(0.f);

    if(lightDirection.y > 0.0){
        lightIntensity = attenuation + (diffuse * sourceLightAngle * ambient);
    }

    // MOON LIGHT
    vec3 lightDirection2 = normalize(moonPosition - primitivePosition.xyz);
    float sourceLightAngle2 = max(dot(normalsFragmentShader, lightDirection2), 0.0);
    float distance2 = length(moonPosition - primitivePosition.xyz);
    float constant2 = 1.0;
    float linear2 = 0.000000007;  // Reduced linear attenuation
    float quadratic2 = 0.0000002; // Reduced quadratic attenuation
    float attenuation2 = 1.0 / (constant2 + linear2 * distance2 + quadratic2 * distance2 * distance2);
    vec3 ambienceDark = ambient * 0.15f;
    vec3 lightIntensity2 = vec3(0.f);

    if(lightDirection2.y > 0.0){
        lightIntensity2 = diffuse * sourceLightAngle2 * attenuation2 * ambienceDark;
    }
    

    vec3 finalColor = lightIntensity + lightIntensity2 + lanternIntensity;

    fragColor = vec4(baseColor.rgb * finalColor, opacity);
}