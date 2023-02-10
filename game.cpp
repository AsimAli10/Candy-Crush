//============================================================================
// Name        : .cpp
// Author      : Sibt ul Hussain
// Version     :   
// Copyright   : (c) Reserved  
// Description : Basic 2D game of Centipede...
//============================================================================  
#ifndef CENTIPEDE_CPP_ 
#define CENTIPEDE_CPP_
#include "util.h"      
#include <iostream> 
#include<string> 
#include<cmath> // for basic math functions such as cos, sin, sqrt  
#include"Control.cpp"     
using namespace std;  

Control game;//My only and only one Global varible which is totally controlling the Game

// seed the random numbers generator by current time (see the documentation of srand for further help)... 
/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and he  ight.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}
  
       
/*      
 * Main Canvas drawing function. 
 * */   

void GameDisplay()/**/{  
if(game.getFlag()==2)
{

	glClearColor(0.5 /*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.5/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1  --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors

	game.load();//it is loading game at evry point 
      
	 
} 
else if (game.getFlag()==1)
{
glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.5/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1  --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors 
	if(game.Menu::choice==2){ 
	game.Menu::Rules();
	}
	else if(game.Menu::choice==3){ 
	game.Menu::Mood(); 
	} 
	else if(game.Menu::choice==0){
	game.Show_Menu();
	}
	else if(game.Menu::choice==4){   
	game.Menu::HighScore();
	} 
 
} 
else if(game.getFlag()==3) 
{
	game.TurnHint();
}
else if(game.getFlag()==4)
{
	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.5/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1  --> White Colour
	DrawRoundRect(340,410,250,0,colors[DARK_OLIVE_GREEN],15);
	DrawString( 350, 400, "Paused. Press'P' ", colors[MISTY_ROSE]);
}	
else if(game.getFlag()==5)
{
glClearColor(0  /*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.5/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1  --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	game.end(); 
}
glutSwapBuffers(); // do not modify this line..	

}    

/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-ar raw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y) {
	if (key
			== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed...

	} else if (key
			== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {

	} else if (key
			== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {

	}

	else if (key
			== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {

	}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
	game.KeyBoardControl(key);//this function is controlling the keyboard buttons
	glutPostRedisplay();
}  

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {

	// implement your functionality here

	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(1000.0, Timer, 0);
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {
	glutPostRedisplay();
}
void MouseMoved(int x, int y) {
	//cout << x << " " << y << endl;
	//glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y) 
{
	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
	{

	game.MouseControl(x,y);//it is controlling mouse

	}
	else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
	{
		cout<<"Right Button Pressed"<<endl;
	}
	glutPostRedisplay();
}           
 /*
 * our gateway main funct     ion  
 * */ 
int main(int argc, char*argv[]){ 
	int width = 840, height = 840; // i have set my window size to be 800 x 600
 
	InitRandomizer(); // seed the random number generator... 
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode  
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window 
	glutCreateWindow("Candy Crush"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

 
	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* AsteroidS_CPP_ */ 
