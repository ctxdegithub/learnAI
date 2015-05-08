attribute vec4 a_position;
attribute vec2 a_texCoord;
attribute vec4 a_color;

uniform float u_time;

#ifdef GL_ES
varying vec2 lowp vec4 v_fragmentColor;
varying vec2 mediump vec2 v_textCoord;
#else
varying vec2 vec4 v_fragmentColor;
varying vec2 vec2 v_textCoord;

#endif

void main()
{
    gl_Position = CC_MVPMatrix * a_position;
    v_fragmentColor = a_color;
    v_textCoord = a_texCoord;
}