//#shader vertex
#version 330 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec4 color;

uniform mat4 u_Rotx;
uniform mat4 u_Roty;
uniform mat4 u_Rotz;
uniform mat4 u_Proj;

out vec4 v_Color;

void main(){
    v_Color = color;
    gl_Position = u_Proj * u_Rotx * u_Roty * u_Rotz * position;
};

//#shader fragment
#version 330 core

in vec4 v_Color;

layout(location = 0) out vec4 color;

//uniform vec4 u_Color;

void main(){
    color = v_Color;
//    color = vec4(vec3(gl_FragCoord.z), 1.0);
};