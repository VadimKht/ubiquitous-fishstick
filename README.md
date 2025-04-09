In order for makefile to work, the whole project should be as a folder inside raylib build (as in downloaded from releases on github)

I use g++ compiler because otherwise it won't accept include math library

bugs:
1) cant make camera look up and down (the reason i have custom controls instead of raylibs UpdateCamera, is the fact i want to have custom speed, and apparently for this i need to make my own code. i considered making my own vertex and fragment shaders to compute all math, but in this case i'd not have ability to just use DrawCube(), which would make this whole project none better than making opengl-only project)
2) the colision detection is not working right and the code changes text in update