#ifdef GL_ES
// Set default precision to medium
precision mediump int;
precision mediump float;
#endif

//uniform mat4 mvp_matrix;
//attribute vec3 a_position;
//attribute vec2 a_texcoord;
//varying vec2 v_texcoord;

attribute highp vec4 vertices;
varying highp vec2 coords;

void main()
{
    // считаем позицию точки на экране
    //gl_Position = mvp_matrix * vec4(a_position, 1.0);
    // Pass texture coordinate to fragment shader
    // Value will be automatically interpolated to fragments inside polygon faces
    //v_texcoord = a_texcoord;
    gl_Position = vertices;
    coords = vertices.xy;
}
