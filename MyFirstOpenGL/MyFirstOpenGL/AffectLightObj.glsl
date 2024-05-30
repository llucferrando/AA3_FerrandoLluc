#version 440 core
struct Light{
    
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;

    float constant;
    float linear;
    float quadratic;

};

uniform vec2 windowSize;
uniform sampler2D textureSampler;

in vec2 uvsFragmentShader;
in vec3 normalsFragmentShader;
in vec4 primitivePosition;

out vec4 fragColor;

uniform float opacity;
uniform vec3 ambient;
uniform vec3 diffuse;
uniform vec3 sunPosition;
uniform vec3 moonPosition;
uniform vec3 camPosition;
uniform vec3 camDirection;
uniform float cutOff;
uniform float outerCutOff;

void main() {

    Light lanternLight;    
    
    vec2 adjustedTexCoord = vec2(uvsFragmentShader.x, 1.0 - uvsFragmentShader.y);
    vec4 baseColor = texture(textureSampler, adjustedTexCoord);

     //CAM LIGHT
    /*vec3 lightDirectionCam = normalize(camPosition - normalsFragmentShader);
    vec3 lightPosToFragment = normalize(primitivePosition.xyz - camPosition);
    vec3 lanternIntensity = vec3(0.0f);
    float camLightAngle = dot(lightDirectionCam, normalize(-camDirection));
    if(camLightAngle > outerCutOff){
        float epsilon = (cutOff - outerCutOff);
        float intensity = clamp((camLightAngle-outerCutOff)/epsilon,0.0,1.0);
        lanternIntensity = effectiveAmbient + (diffuse * intensity * attenuation);
    }*/

    //SUN LIGHT
    vec3 sourceLight = vec3(0.0, 25.0, 0);
    vec3 lightDirection = normalize(sunPosition - primitivePosition.xyz);
    float sourceLightAngle = dot(lightDirection,normalsFragmentShader);
    float distance = length(sunPosition - primitivePosition.xyz);
    float constant = 1.0;
    float linear = 0.00000000007;  // Reduced linear attenuation
    float quadratic = 0.0000002;  // Reduced quadratic attenuation
    float attenuation = 1.0 / (constant + linear * distance + quadratic);
    vec3 lightIntensity = vec3(0.f);

    //MOON LIGHT
    vec3 lightDirection2 = normalize(moonPosition - primitivePosition.xyz);
    float sourceLightAngle2 = dot(lightDirection2,normalsFragmentShader);
    float distance2 = length(moonPosition - primitivePosition.xyz);
    float constant2 = 1.0;
     float linear2 = 0.00000000007;  // Reduced linear attenuation
    float quadratic2 = 0.0000002; // Reduced quadratic attenuation
    float attenuation2 = 1.0 / (constant2 + linear2 * distance2 + quadratic2 * distance2 * distance2);
    vec3 ambienceDark = ambient*0.15f;
    vec3 lightIntensity2 = vec3(0.f);

    if(lightDirection.y > 0.0){
        lightIntensity = (diffuse * sourceLightAngle * attenuation * ambient);
    }
    else{
        lightIntensity2 = (diffuse * sourceLightAngle2 * attenuation2 * ambienceDark);
    }

   vec3 finalColor = lightIntensity + lightIntensity2;

    fragColor = vec4(baseColor.rgb * finalColor, opacity);
}