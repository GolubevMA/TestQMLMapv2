#ifdef GL_ES
precision mediump int;
precision mediump float;
#endif

//uniform sampler2D texture;
//varying vec2 v_texcoord;
uniform vec4 color;

void main()
{
    //gl_FragColor = texture2D(texture, v_texcoord);
    gl_FragColor = vec4(1,0,1,0);
}
//! [0]

