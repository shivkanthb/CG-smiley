/*
 *  untitled.h
 *  Ex3cSmiley
 *
 *  Created by 7cseb60 on 7/26/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#include<iostream.h>
#include<GLUT/glut.h>

int Cx=0,Cy=0,r=0;

void myInit() {
	glClearColor(1.0,1.0,1.0,0.0);
	glColor3f(0.0f,0.0f,0.0f);
	glPointSize(2);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,640.0,0.0,480.0);
}

int nextPk(int curPk, int curX, int curY) {
	if( curPk < 0 ) {
		return (curPk+2*curX+1);
	}
	else {
		return (curPk+2*curX-2*curY+1);
	}
}

void drawCircle(int mode) {
	int P0 = 1 - r;
	int Pk;
	int curX, curY;
	
	curX = 0;
	curY = r;
	
	glVertex2d(Cx+0,Cy-r);
	
	if(mode==0) {
		glVertex2d(Cx+0,Cy+r);
		glVertex2d(Cx+r,Cy+0);
		glVertex2d(Cx-r,Cy+0);
	}
	
	
	Pk = P0;
	
	while( curX < curY ) {
		Pk = nextPk(Pk,curX,curY);
		
		curX = curX + 1;
		if( Pk >= 0 ) {
			curY = curY - 1;
		}
		
		//Plotting point(s)
		glVertex2d(Cx+curX,Cy-curY);
		glVertex2d(Cx-curX,Cy-curY);
		if(mode==0) {
			glVertex2d(Cx-curY,Cy+curX);
			glVertex2d(Cx+curX,Cy+curY);
			glVertex2d(Cx-curX,Cy+curY);
			glVertex2d(Cx+curY,Cy+curX);
			glVertex2d(Cx+curY,Cy-curX);
			glVertex2d(Cx-curY,Cy-curX);
		}
		//cout<<endl<<curX<<" "<<curY;
	}
	
}


void myDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	
	
	glBegin(GL_POINTS);
		//Plot here
		Cx = 320;
		Cy = 240;
		r = 100;
		drawCircle(0);

		Cx = 360;
		Cy = 270;
		r = 10;
		drawCircle(0);
		
		Cx = 280;
		Cy = 270;
		r = 10;
		drawCircle(0);
		
		Cx = 320;
		Cy = 250;
		r = 80;
		drawCircle(1);
		
	glEnd();
	
	glFlush();
}

void getCoords() {
	cout<<"Enter center point: "<<endl<<"X: ";
	cin>>Cx;
	cout<<"Y: ";
	cin>>Cy;	
	cout<<"Enter the radius: ";
	cin>>r;
}

int main(int argc, char* argv[]) {

	//getCoords();
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(640,480);
	glutCreateWindow("Mid Point Circle");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();

	return 1;
}