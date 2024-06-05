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


void main() {
    vec2 adjustedTexCoord = vec2(uvsFragmentShader.x, 1.0 - uvsFragmentShader.y);
    vec4 baseColor = texture(textureSampler, adjustedTexCoord);
    vec3 increasedAmbient = ambient * 1.0;
    vec3 totalLight = increasedAmbient + diffuse;
    
    fragColor = vec4(baseColor.rgb * totalLight, opacity);
}