#version 440 core

uniform vec2 windowSize;
uniform sampler2D textureSampler;
uniform float opacity;
uniform vec3 ambient;
uniform vec3 diffuse;
uniform vec3 lightPositions[2];  
uniform vec3 camPosition;
uniform vec3 camDirection;
uniform vec3 ambientLandscape;
uniform float innerCutOff; 
uniform float outerCutOff; 
uniform bool lanternOn;

in vec2 uvsFragmentShader;
in vec3 normalsFragmentShader;
in vec4 primitivePosition;

out vec4 fragColor;

void main() {

    vec2 adjustedTexCoord = vec2(uvsFragmentShader.x, 1.0 - uvsFragmentShader.y);
    vec4 baseColor = texture(textureSampler, adjustedTexCoord);

    vec3 lanternIntensity = vec3(0.0f);
    vec3 lightDir = normalize(camPosition - primitivePosition.xyz); 
    float theta = dot(lightDir, normalize(-camDirection));
    float constantAtt = 1.0;
    float linearAtt = 0.00000000009;
    float quadraticAtt = 0.0000032;
    if(lanternOn) {
        if(theta > outerCutOff) {
            float epsilon = innerCutOff - outerCutOff;
            float intensity = smoothstep(outerCutOff, innerCutOff, theta);
            float distance = length(camPosition - primitivePosition.xyz);
            float attenuation = 1.0 / (constantAtt + linearAtt * distance + quadraticAtt * distance * distance);
            lanternIntensity = (diffuse * intensity * ambient) * attenuation;
        }
    }

    vec3 lightIntensities[2] = vec3[2](vec3(0.0f), vec3(0.0f));
    float linearAttenuations[2] = float[2](0.00007, 0.0000007);
    float quadraticAttenuations[2] = float[2](0.000002, 0.000002);
    vec3 ambienceDark = ambient * 0.15f;

    for(int i = 0; i < 2; i++) {
        vec3 lightDirection = normalize(lightPositions[i] - primitivePosition.xyz);
        float sourceLightAngle = max(dot(normalsFragmentShader, lightDirection), 0.0);
        float distance = length(lightPositions[i] - primitivePosition.xyz);
        float constant = 1.0;
        float linear = linearAttenuations[i];
        float quadratic = quadraticAttenuations[i];
        float attenuation = 1.0 / (constant + linear * distance + quadratic * distance * distance);
        
        if(lightDirection.y > 0.0) {
            vec3 currentAmbient = (i == 0) ? ambient : ambienceDark;
            lightIntensities[i] = attenuation + (diffuse * sourceLightAngle * currentAmbient) + ambientLandscape;
        }
    }

    vec3 finalColor = lightIntensities[0] + lightIntensities[1] + lanternIntensity;
    fragColor = vec4(baseColor.rgb * finalColor, opacity);
}