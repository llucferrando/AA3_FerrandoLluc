#version 440 core

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

void main() {
    vec2 adjustedTexCoord = vec2(uvsFragmentShader.x, 1.0 - uvsFragmentShader.y);
    vec4 baseColor = texture(textureSampler, adjustedTexCoord);

    vec3 sourceLight = vec3(0.0, 505.0, 0);
    vec3 lightDirection = normalize(sourceLight - primitivePosition.xyz);
    float sourceLightAngle = dot(normalsFragmentShader, lightDirection);

    float distance = length(sourceLight - primitivePosition.xyz);

    float constant = 1.0;
    float linear = 0.022;  
    float quadratic = 0.0019;  

    float attenuation = 1.0 / (constant + linear * distance + quadratic * distance * distance);

    // Darken the ambient light based on distance
    vec3 effectiveAmbient = ambient * attenuation;

    // Combine ambient and diffuse light
    vec3 lightIntensity = effectiveAmbient + (diffuse * sourceLightAngle * attenuation);

    fragColor = vec4(baseColor.rgb * lightIntensity, opacity);
}