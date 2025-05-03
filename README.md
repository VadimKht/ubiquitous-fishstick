In order for makefile to work, the whole project should be as a folder inside raylib build (as in downloaded from releases on github)

I use g++ compiler because otherwise it won't accept include math library

bugs:

1) the colision detection seems to work right, but the code is up to optimization
2) colisions by x and z make weird motion 

general goal: very basic parkour game, the rectnagles disappear soon as player moves very fast from rectnagle to rectangle
steps, in descending order of importance:
-1) change colision detection from per-cube created to logical only and make CheckCollision True (right now these functions have hard coded changed colisions to prevent player falling through cube) 
0) get rid of weird motion during sliding across the cube's side
1) parkour map generation
    challenge: make maps of the intensity/difficulty based on time since start of level. maps meaning file that contains data such as what to do and when
2) Gradient (change objects color over time) code
3) UI such as start game settings
    I) exit button to replace the esc to close window
    II) fullscreen support
    III) ability to change FPS lock (uh oh, some stuff is FPS dependent!)
4) Motion blur but awesome, to be activated during BG Music drop
5) additionally during BG Music drop camera tilt to motions (like in quake) could probably add some feeling