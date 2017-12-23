#version 410 core

in vec2 passTexture;
out vec4 fragmentColor;

uniform sampler2D diffuseTexture;

void main() 
{   
    fragmentColor = texture(diffuseTexture, passTexture);
}
