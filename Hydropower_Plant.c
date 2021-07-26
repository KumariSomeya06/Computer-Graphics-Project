#include<stdio.h>
#include<GL/glut.h>
#include <math.h>
#define PI 3.1415927
#define PI_2 3.1415927

float current_angle = 0.0f;
float step_angle = 4.5f;
float center_x = -40.0f;
float center_y = -45.0f;
float center_z=215.0f;

float xt=0,yt=0,zt=0,anglet=0;
float xt1=0,yt1=0,yt2=0,zt2=0,zt1=0;
float xe,ye,ue=0,ze,blend;
float angle_e;
int angle1=1;
int count_e=0;
int count=1;
int slide=1;
int i,j;
float xpos=0.0;
float ypos=0.5;
float tt=0;
float x=0;
float a=0,c=0,d=0,e=0,y=0,z=0,g;
float arrow=1;

int state=1;

float angle=50.0;

void timer(int v);

void init()
{
	
	//glClearColor(0.0,0.5,0.5,1.0);
	glClearColor(0.8,1.0,1.0,0.0);
	glEnable(GL_DEPTH_TEST);
	
}

void reshape(int w,int h)
{
	
	glViewport(0,0,(GLsizei)w,(GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0,1,2.0,1000.0);
	glMatrixMode(GL_MODELVIEW);
	
	
}


void output1(char a[])
{
	glScalef(0.1,0.2,0.0);
	glColor3f(0.1,0.1,0.0);
	int j,i=0;
	for(i=0;i<strlen(a);i++)
	{
		glutStrokeCharacter(GLUT_STROKE_ROMAN,a[i]);
		glFlush();
	//for(j=0;j<99999099;j++);
	}
}

void timer1(int v)
{
	angle1=angle1+0.5;
	glRotatef(40.0+angle,0.0,1.0,0.0);
	glutPostRedisplay();
	glutTimerFunc(300,timer1,0);
}

void title1()
{
	glPushMatrix();
	glLineWidth(2);
	glTranslatef(-200.0,260.0,-550.0);
	output1("MAGALORE INSTITUTE OF TECHNOLOGY AND ENGINEERING ");
	glPopMatrix();
	glPushMatrix();
	glScalef(0.3,0.2,0.3);
	glLineWidth(2);
	glTranslatef(-190.0,320.0,-550.0);
	output1("DEPARTMENT OF COMPUTER SCIENCE & ENGINEERING");
	glPopMatrix();
	glPushMatrix();
	glScalef(0.3,0.2,0.3);
	glLineWidth(2);
	glTranslatef(-190.0,200.0,-550.0);
	output1("Graphics project on :");
	glPopMatrix();
	glPushMatrix();
	glScalef(0.3,0.1,0.2);
	glLineWidth(3);
	glTranslatef(-120.0,160.0,-550.0);
	output1("HYDROPOWER PLANT PROJECT");
	glPopMatrix();
	
	glPushMatrix();
	glScalef(0.3,0.1,0.2);
	glLineWidth(3);
	glTranslatef(-180.0,0.0,-550.0);
	output1("BUILT BY :");
	glPopMatrix();
	
	glPushMatrix();
	glScalef(0.3,0.1,0.25);
	glLineWidth(3);
	glTranslatef(-140.0,-100.0,-550.0);
	output1("SOMEYA KUMARI  4MT18CS100");
	glPopMatrix();
	
	glPushMatrix();
	glScalef(0.3,0.1,0.25);
	glLineWidth(3);
	glTranslatef(-140.0,-150.0,-550.0);
	output1("VAISHAKH B  4MT18CS109");
	glPopMatrix();
	
	glPushMatrix();
	glScalef(0.3,0.1,0.2);
	glLineWidth(3);
	glTranslatef(-180.0,-250.0,-550.0);
	output1("GUIDED BY :");
	glPopMatrix();
	
	glPushMatrix();
	glScalef(0.3,0.1,0.25);
	glLineWidth(3);
	glTranslatef(-140.0,-400.0,-550.0);
	output1("Ms. AISHWARYA BHAT");
	glPopMatrix();
	
	glPushMatrix();
	glScalef(0.3,0.1,0.25);
	glLineWidth(3);
	glTranslatef(-140.0,-450.0,-550.0);
	output1("Ms. SUNITHA N V");
	glPopMatrix();
	
	glPushMatrix();
	glScalef(0.3,0.1,0.25);
	glLineWidth(2);
	glTranslatef(10.0,-650.0,-550.0);
	output1("PRESS B OR b FOR NEXT SLIDE ");
	glPopMatrix();
	
}

void title2()
{
	glPushMatrix();
	glScalef(0.15,0.1,0.25);
	glLineWidth(2);
	glTranslatef(300.0,750.0,-550.0);
	output1("PRESS C OR c FOR NEXT SLIDE ");
	glPopMatrix();
}

void title3()
{
	glPushMatrix();
	glScalef(0.15,0.1,0.25);
	glLineWidth(2);
	glTranslatef(300.0,750.0,-550.0);
	output1("PRESS D OR d FOR NEXT SLIDE ");
	glPopMatrix();
}

void title4()
{
	glPushMatrix();
	glScalef(0.15,0.1,0.25);
	glLineWidth(2);
	glTranslatef(300.0,750.0,-550.0);
	output1("PRESS E OR e FOR NEXT SLIDE ");
	glPopMatrix();
}

void title5()
{
	glPushMatrix();
	glScalef(0.15,0.1,0.25);
	glLineWidth(2);
	glTranslatef(300.0,750.0,-550.0);
	output1("PRESS F OR f FOR FINAL SLIDE ");
	glPopMatrix();
}

void title6()
{
	glPushMatrix();
	glScalef(0.15,0.1,0.035);
	glLineWidth(5);
	glTranslatef(-40,0,-500);
	output1("THANK YOU!!");
	glPopMatrix();
}

void draw_cylinder1(GLfloat radius,GLfloat height,GLubyte R,GLubyte G,GLubyte B)
{
    GLfloat x              = 0.0;
    GLfloat y              = 0.0;
    GLfloat angle          = 0.0;
    GLfloat angle_stepsize = 0.1;

    /** Draw the tube */
    //glColor3ub(R-40,G-40,B-40);
    glColor3f(0.53,0.12,0.47);
    glBegin(GL_QUAD_STRIP);
    angle = 0.0;
        while( angle < 2*PI ) {
            x = radius * cos(angle);
            y = radius * sin(angle);
            glVertex3f(40+x, height,y+170.0 );
            glVertex3f(40+x, 0.0, y+170.);
            angle = angle + angle_stepsize;
        }
        glVertex3f(radius+40,height, 170.0 );
        glVertex3f(radius+40, 0.0, 170.0);
    glEnd();

    /** Draw the circle on top of cylinder */
    glColor3f(1.0,0.0,1.0);
    glBegin(GL_POLYGON);
    angle = 0.0;
        while( angle < 2*PI ) {
            x = radius * cos(angle);
            y = radius * sin(angle);
            glVertex3f(40+x, height, y+170 );
            angle = angle + angle_stepsize;
        }
        glVertex3f(radius+40, 0.0, height);
    glEnd();
    
    
}

void draw_cylinder2(GLfloat radius,GLfloat height,GLubyte R,GLubyte G,GLubyte B)
{
    GLfloat x              = 0.0;
    GLfloat y              = 0.0;
    GLfloat angle          = 0.0;
    GLfloat angle_stepsize = 0.1;

    /** Draw the tube */
    //glColor3ub(R-40,G-40,B-40);
    glColor3f(0.53,0.12,0.47);
    glBegin(GL_QUAD_STRIP);
    angle = 0.0;
        while( angle < 2*PI ) {
            x = radius * cos(angle);
            y = radius * sin(angle);
            glVertex3f(-10+x, height,y+170.0 );
            glVertex3f(-10+x, 0.0, y+170.);
            angle = angle + angle_stepsize;
        }
        glVertex3f(radius-10,height, 170.0 );
        glVertex3f(radius-10, 0.0, 170.0);
    glEnd();

    /** Draw the circle on top of cylinder */
    glColor3f(1.0,0.0,1.0);
    glBegin(GL_POLYGON);
    angle = 0.0;
        while( angle < 2*PI ) {
            x = radius * cos(angle);
            y = radius * sin(angle);
            glVertex3f(-10+x, height, y+170 );
            angle = angle + angle_stepsize;
        }
        glVertex3f(radius-10, 0.0, height);
    glEnd();
    
    
}

void draw_cylinder3(GLfloat radius,GLfloat height,GLubyte R,GLubyte G,GLubyte B)
{
    GLfloat x              = 0.0;
    GLfloat y              = 0.0;
    GLfloat angle          = 0.0;
    GLfloat angle_stepsize = 0.1;

    /** Draw the tube */
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_QUAD_STRIP);
    angle = 0.0;
        while( angle < 2*PI ) {
            x = radius * cos(angle);
            y = radius * sin(angle);
            glVertex3f(-30+x, height,y+40.0 );
            glVertex3f(-30+x, 0.0, y+40.);
            angle = angle + angle_stepsize;
        }
        glVertex3f(radius-30,height, 40.0 );
        glVertex3f(radius-30, 0.0, 40.0);
    glEnd();

    /** Draw the circle on top of cylinder */
    glColor3ub(R,G,B);
    glBegin(GL_POLYGON);
    angle = 0.0;
        while( angle < 2*PI ) {
            x = radius * cos(angle);
            y = radius * sin(angle);
            glVertex3f(-30+x, height, y+40 );
            angle = angle + angle_stepsize;
        }
        glVertex3f(radius-30, -150000.0, height+40);
    glEnd();
    
    
}

void draw_cylinder4(GLfloat radius,GLfloat height,GLubyte R,GLubyte G,GLubyte B)
{
    GLfloat x              = 0.0;
    GLfloat y              = 0.0;
    GLfloat angle          = 0.0;
    GLfloat angle_stepsize = 0.1;

    /** Draw the tube */
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_QUAD_STRIP);
    angle = 0.0;
        while( angle < 2*PI ) {
            x = radius * cos(angle);
            y = radius * sin(angle);
            glVertex3f(50.0+x, height,y+40.0 );
            glVertex3f(50.0+x, 0.0, y+40.);
            angle = angle + angle_stepsize;
        }
        glVertex3f(radius+50.0,height, 40.0 );
        glVertex3f(radius+50.0, 0.0, 40.0);
    glEnd();

    /** Draw the circle on top of cylinder */
    glColor3ub(R,G,B);
    glBegin(GL_POLYGON);
    angle = 0.0;
        while( angle < 2*PI ) {
            x = radius * cos(angle);
            y = radius * sin(angle);
            glVertex3f(50.0+x, height, y+40.0 );
            angle = angle + angle_stepsize;
        }
        glVertex3f(radius+50.0,  -150000.0, height);
    glEnd();
    
    
}

void draw_cylinder5(GLfloat radius,
                   GLfloat height)
{
    GLfloat x              = 0.0;
    GLfloat y              = 0.0;
    GLfloat angle          = 0.0;
    GLfloat angle_stepsize = 0.1;

    /** Draw the tube */
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_QUAD_STRIP);
    angle = 0.0;
        while( angle < 2*PI ) {
            x = radius * cos(angle);
            y = radius * sin(angle);
            glVertex3f( height-52,x+250, y+38 );
            glVertex3f(-52.0,x+250, y+38 );
            angle = angle + angle_stepsize;
        }
        glVertex3f(height-52,radius+250, 38.0);
        glVertex3f( -52.0,radius+250, 38.0);
    glEnd();

    /** Draw the circle on top of cylinder */
    glColor3ub(0.1,0.1,0.1);
    glBegin(GL_POLYGON);
    angle = 0.0;
        while( angle < 2*PI ) {
            x = radius * cos(angle);
            y = radius * sin(angle);
            glVertex3f( height-52,x+250, y+38);
            angle = angle + angle_stepsize;
        }
        glVertex3f(height-52,radius+250, 38.0 );
    glEnd();
}

void draw_cylinder6(GLfloat radius,
                   GLfloat height)
{
    GLfloat x              = 0.0;
    GLfloat y              = 0.0;
    GLfloat angle          = 0.0;
    GLfloat angle_stepsize = 0.1;

    /** Draw the tube */
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_QUAD_STRIP);
    angle = 0.0;
        while( angle < 2*PI ) {
            x = radius * cos(angle);
            y = radius * sin(angle);
            glVertex3f( height-45,x+270, y+38 );
            glVertex3f(-45.0,x+270, y+38  );
            angle = angle + angle_stepsize;
        }
        glVertex3f(height-45,radius+270, 38.0);
        glVertex3f( -45.0,radius+270, 38.0);
    glEnd();

    /** Draw the circle on top of cylinder */
    glColor3ub(0.1,0.1,0.1);
    glBegin(GL_POLYGON);
    angle = 0.0;
        while( angle < 2*PI ) {
            x = radius * cos(angle);
            y = radius * sin(angle);
            glVertex3f( height-45,x+270, y+38);
            angle = angle + angle_stepsize;
        }
        glVertex3f(height-45,radius+270, 38.0 );
    glEnd();
    
    
}
void draw_cylinder7(GLfloat radius,
                   GLfloat height)
{
    GLfloat x              = 0.0;
    GLfloat y              = 0.0;
    GLfloat angle          = 0.0;
    GLfloat angle_stepsize = 0.1;

    /** Draw the tube */
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_QUAD_STRIP);
    angle = 0.0;
        while( angle < 2*PI ) {
            x = radius * cos(angle);
            y = radius * sin(angle);
            glVertex3f( height+25,x+250, y+38 );
            glVertex3f(25.0,x+250, y+38  );
            angle = angle + angle_stepsize;
        }
        glVertex3f(height+25,radius+250, 38.0);
        glVertex3f( 25.0,radius+250, 38.0);
    glEnd();

    /** Draw the circle on top of cylinder */
    glColor3ub(0.1,0.1,0.1);
    glBegin(GL_POLYGON);
    angle = 0.0;
        while( angle < 2*PI ) {
            x = radius * cos(angle);
            y = radius * sin(angle);
            glVertex3f( height+25,x+250, y+38);
            angle = angle + angle_stepsize;
        }
        glVertex3f(height+25,radius+250, 38.0 );
    glEnd();
}

void draw_cylinder8(GLfloat radius,
                   GLfloat height)
{
    GLfloat x              = 0.0;
    GLfloat y              = 0.0;
    GLfloat angle          = 0.0;
    GLfloat angle_stepsize = 0.1;

    /** Draw the tube */
    /** Draw the tube */
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_QUAD_STRIP);
    angle = 0.0;
        while( angle < 2*PI ) {
            x = radius * cos(angle);
            y = radius * sin(angle);
            glVertex3f( height+36,x+270, y+38 );
            glVertex3f(36.0,x+270, y+38  );
            angle = angle + angle_stepsize;
        }
        glVertex3f(height+36,radius+270, 38.0);
        glVertex3f( 36.0,radius+270, 38.0);
    glEnd();

    /** Draw the circle on top of cylinder */
    glColor3ub(0.1,0.1,0.1);
    glBegin(GL_POLYGON);
    angle = 0.0;
        while( angle < 2*PI ) {
            x = radius * cos(angle);
            y = radius * sin(angle);
            glVertex3f( height+36,x+270, y+38);
            angle = angle + angle_stepsize;
        }
        glVertex3f(height+36,radius+270, 38.0 );
    glEnd();
    
}

void draw_cylinder9(GLfloat radius,
                   GLfloat height)
{
    GLfloat x              = 0.0;
    GLfloat y              = 0.0;
    GLfloat angle          = 0.0;
    GLfloat angle_stepsize = 0.1;

    /** Draw the tube */
    glColor3f(0.0,0.5,1.0);
    glBegin(GL_QUAD_STRIP);
    angle = 0.0;
        while( angle < 2*PI ) {
            x = radius * cos(angle);
            y = radius * sin(angle);
            glVertex3f( x-40, y+60 ,height+4);
            glVertex3f(x-40, y+60,4.0 );
            angle = angle + angle_stepsize;
        }
        glVertex3f(radius-40, 60.0,height+4);
        glVertex3f(radius-40, 60.0, 4.0);
    glEnd();

    /** Draw the circle on top of cylinder */
    glColor3ub(0.0,0.5,1.0);
    glBegin(GL_POLYGON);
    angle = 0.0;
        while( angle < 2*PI ) {
            x = radius * cos(angle);
            y = radius * sin(angle);
            glVertex3f( x-40, y+60,height+4);
            angle = angle + angle_stepsize;
        }
        glVertex3f(radius-40, 60.0,height+4 );
    glEnd();
}


void draw_cylinder10(GLfloat radius,
                   GLfloat height)
{
    GLfloat x              = 0.0;
    GLfloat y              = 0.0;
    GLfloat angle          = 0.0;
    GLfloat angle_stepsize = 0.1;

    /** Draw the tube */
    glColor3f(0.0,0.5,1.0);
    glBegin(GL_QUAD_STRIP);
    angle = 0.0;
        while( angle < 2*PI ) {
            x = radius * cos(angle);
            y = radius * sin(angle);
            glVertex3f( x-40, y-20 ,height+54);
            glVertex3f(x-40, y+60,54.0 );
            angle = angle + angle_stepsize;
        }
        glVertex3f(radius-40, -20.0,height+54);
        glVertex3f(radius-40, -20.0, 54.0);
    glEnd();

    /** Draw the circle on top of cylinder */
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    angle = 0.0;
        while( angle < 2*PI ) {
            x = radius * cos(angle);
            y = radius * sin(angle);
            glVertex3f( x-40, y-20,height+54);
            angle = angle + angle_stepsize;
        }
        glVertex3f(radius-40, -20.0,height+54 );
    glEnd();
}

void draw_cylinder101(GLfloat radius,
                   GLfloat height)
{
    GLfloat x              = 0.0;
    GLfloat y              = 0.0;
    GLfloat angle          = 0.0;
    GLfloat angle_stepsize = 0.1;

    /** Draw the tube */
    glColor3f(0.0,0.5,1.0);
    glBegin(GL_QUAD_STRIP);
    angle = 0.0;
        while( angle < 2*PI ) {
            x = radius * cos(angle);
            y = radius * sin(angle);
            glVertex3f( x-40, y-20 ,height+54);
            glVertex3f(x-40, y+60,54.0 );
            angle = angle + angle_stepsize;
        }
        glVertex3f(radius-40, -20.0,height+54);
        glVertex3f(radius-40, -20.0, 54.0);
    glEnd();

    /** Draw the circle on top of cylinder */
    glColor3f(0.0,0.0,1.0);
    glBegin(GL_POLYGON);
    angle = 0.0;
        while( angle < 2*PI ) {
            x = radius * cos(angle);
            y = radius * sin(angle);
            glVertex3f( x-40, y-20,height+54);
            angle = angle + angle_stepsize;
        }
        glVertex3f(radius-40, -20.0,height+54 );
    glEnd();
}

void draw_cylinder11(GLfloat radius,GLfloat height,GLubyte R,GLubyte G,GLubyte B)
{
    GLfloat x              = 0.0;
    GLfloat y              = 0.0;
    GLfloat angle          = 0.0;
    GLfloat angle_stepsize = 0.1;

    /** Draw the tube */
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_QUAD_STRIP);
    angle = 0.0;
        while( angle < 2*PI ) {
            x = radius * cos(angle);
            y = radius * sin(angle);
            glVertex3f(x-40, height+30,y+220.0 );
            glVertex3f(x-40, 30.0, y+220.);
            angle = angle + angle_stepsize;
        }
        glVertex3f(radius-40,height+30, 220.0 );
        glVertex3f(radius-40, 30.0, 220.0);
    glEnd();

    /** Draw the circle on top of cylinder */
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    angle = 0.0;
        while( angle < 2*PI ) {
            x = radius * cos(angle);
            y = radius * sin(angle);
            glVertex3f(x-40, height+30, y+220 );
            angle = angle + angle_stepsize;
        }
        glVertex3f(radius-40, 30.0, height);
    glEnd();
    
    
}

void draw_cylinder12(GLfloat radius,GLfloat height,GLubyte R,GLubyte G,GLubyte B)
{
    GLfloat x              = 0.0;
    GLfloat y              = 0.0;
    GLfloat angle          = 0.0;
    GLfloat angle_stepsize = 0.1;

    /** Draw the tube */
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_QUAD_STRIP);
    angle = 0.0;
        while( angle < 2*PI ) {
            x = radius * cos(angle);
            y = radius * sin(angle);
            glVertex3f(-40+x, height-30,y+220.0 );
            glVertex3f(-40+x, -30.0, y+220.);
            angle = angle + angle_stepsize;
        }
        glVertex3f(radius-40,height-30, 220.0 );
        glVertex3f(radius-40, -30.0, 220.0);
    glEnd();

    /** Draw the circle on top of cylinder */
    glColor3ub(R,G,B);
    glBegin(GL_POLYGON);
    angle = 0.0;
        while( angle < 2*PI ) {
            x = radius * cos(angle);
            y = radius * sin(angle);
            glVertex3f(-40+x, height-30, y+220 );
            angle = angle + angle_stepsize;
        }
        glVertex3f(radius-40, -150000.0, height+220);
    glEnd();
    
    
}

void draw_cylinder13(GLfloat radius,GLfloat height,GLubyte R,GLubyte G,GLubyte B)
{
    GLfloat x              = 0.0;
    GLfloat y              = 0.0;
    GLfloat angle          = 0.0;
    GLfloat angle_stepsize = 0.1;

    /** Draw the tube */
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_QUAD_STRIP);
    angle = 0.0;
        while( angle < 2*PI ) {
            x = radius * cos(angle);
            y = radius * sin(angle);
            glVertex3f(x-40, height-60,y+220.0 );
            glVertex3f(x-40, -60.0, y+220.);
            angle = angle + angle_stepsize;
        }
        glVertex3f(radius-40,height-60, 220.0 );
        glVertex3f(radius-40, -60.0, 220.0);
    glEnd();

    /** Draw the circle on top of cylinder */
    glColor3f(0.8,0.8,0.8);
    glBegin(GL_POLYGON);
    angle = 0.0;
        while( angle < 2*PI ) {
            x = radius * cos(angle);
            y = radius * sin(angle);
            glVertex3f(x-40, height-60, y+220 );
            angle = angle + angle_stepsize;
        }
        glVertex3f(radius-40, -60.0, height);
    glEnd();
    
    
}

void draw_cylinder14(GLfloat radius,
                   GLfloat height)
{
    GLfloat x              = 0.0;
    GLfloat y              = 0.0;
    GLfloat angle          = 0.0;
    GLfloat angle_stepsize = 0.1;

    /** Draw the tube */
    glColor3f(0.0,0.5,1.0);
    glBegin(GL_QUAD_STRIP);
    angle = 0.0;
        while( angle < 2*PI ) {
            x = radius * cos(angle);
            y = radius * sin(angle);
            glVertex3f( x-40, y-140 ,height+220);
            glVertex3f(x-40, y-140,220.0 );
            angle = angle + angle_stepsize;
        }
        glVertex3f(radius-40, -140.0,height+220);
        glVertex3f(radius-40, -140.0, 220.0);
    glEnd();

    /** Draw the circle on top of cylinder */
    glColor3ub(0.0,0.5,1.0);
    glBegin(GL_POLYGON);
    angle = 0.0;
        while( angle < 2*PI ) {
            x = radius * cos(angle);
            y = radius * sin(angle);
            glVertex3f( x-40, y-140,height+220);
            angle = angle + angle_stepsize;
        }
        glVertex3f(radius-40, -140.0,height+220 );
    glEnd();
}

void draw_cylinder15(GLfloat radius,GLfloat height)
{
    GLfloat x              = 0.0;
    GLfloat y              = 0.0;
    GLfloat angle          = 0.0;
    GLfloat angle_stepsize = 0.1;

    /** Draw the tube */
    glColor3f(0.0,0.5,1.0);
    glBegin(GL_QUAD_STRIP);
    angle = 0.0;
        while( angle < 2*PI ) {
            x = radius * cos(angle);
            y = radius * sin(angle);
            glVertex3f(x-40, height-140,y+220.0 );
            glVertex3f(x-40, -140.0, y+220.);
            angle = angle + angle_stepsize;
        }
        glVertex3f(radius-40,height-140, 220.0 );
        glVertex3f(radius-40, -140.0, 220.0);
    glEnd();

    /** Draw the circle on top of cylinder */
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    angle = 0.0;
        while( angle < 2*PI ) {
            x = radius * cos(angle);
            y = radius * sin(angle);
            glVertex3f(x-40, height-140, y+220 );
            angle = angle + angle_stepsize;
        }
        glVertex3f(radius-40, -140.0, height);
    glEnd();
    
    
}

void draw_cylinder141(GLfloat radius,
                   GLfloat height)
{
    GLfloat x              = 0.0;
    GLfloat y              = 0.0;
    GLfloat angle          = 0.0;
    GLfloat angle_stepsize = 0.1;

    /** Draw the tube */
    glColor3f(0.0,0.5,1.0);
    glBegin(GL_QUAD_STRIP);
    angle = 0.0;
        while( angle < 2*PI ) {
            x = radius * cos(angle);
            y = radius * sin(angle);
            glVertex3f( x-40, y-140 ,height+220);
            glVertex3f(x-40, y-140,220.0 );
            angle = angle + angle_stepsize;
        }
        glVertex3f(radius-40, -140.0,height+220);
        glVertex3f(radius-40, -140.0, 220.0);
    glEnd();

    /** Draw the circle on top of cylinder */
    glColor3f(0.0,0.5,1.0);
    glBegin(GL_POLYGON);
    angle = 0.0;
        while( angle < 2*PI ) {
            x = radius * cos(angle);
            y = radius * sin(angle);
            glVertex3f( x-40, y-140,height+220);
            angle = angle + angle_stepsize;
        }
        glVertex3f(radius-40, -140.0,height+220 );
    glEnd();
}

void draw_cylinder151(GLfloat radius,GLfloat height)
{
    GLfloat x              = 0.0;
    GLfloat y              = 0.0;
    GLfloat angle          = 0.0;
    GLfloat angle_stepsize = 0.1;

    /** Draw the tube */
    glColor3f(0.0,0.5,1.0);
    glBegin(GL_QUAD_STRIP);
    angle = 0.0;
        while( angle < 2*PI ) {
            x = radius * cos(angle);
            y = radius * sin(angle);
            glVertex3f(x-40, height-140,y+220.0 );
            glVertex3f(x-40, -140.0, y+220.);
            angle = angle + angle_stepsize;
        }
        glVertex3f(radius-40,height-140, 220.0 );
        glVertex3f(radius-40, -140.0, 220.0);
    glEnd();

    /** Draw the circle on top of cylinder */
    glColor3f(0.0,0.0,1.0);
    glBegin(GL_POLYGON);
    angle = 0.0;
        while( angle < 2*PI ) {
            x = radius * cos(angle);
            y = radius * sin(angle);
            glVertex3f(x-40, height-140, y+220 );
            angle = angle + angle_stepsize;
        }
        glVertex3f(radius-40, -140.0, height);
    glEnd();
    
    
}


void draw_cone1(GLfloat height,GLfloat radius)
{
	// draw the upper part of the cone
	glColor3f(0.53,0.12,0.47);
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(40, height+80,164);
	for (angle = 0; angle < 360; angle++) 
	{
    	glVertex3f(sin(angle) * radius+40, 80, cos(angle) * radius+164);
	}
	glEnd();

	// draw the base of the cone
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(40, 80, 164);
	for (angle = 0; angle < 360; angle++) 
	{
    	// normal is just pointing down
    	glNormal3f(0, -1, 0);
    	glVertex3f(sin(angle) * radius+40, 80, cos(angle) * radius+164);
	}
	glEnd();
}

void draw_cone2(GLfloat height,GLfloat radius)
{
	// draw the upper part of the cone
	glColor3f(0.53,0.12,0.47);
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(40, height+80,178);
	for (angle = 0; angle < 360; angle++) 
	{
    	glVertex3f(sin(angle) * radius+40, 80, cos(angle) * radius+178);
	}
	glEnd();

	// draw the base of the cone
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(40, 80, 178);
	for (angle = 0; angle < 360; angle++) 
	{
    	// normal is just pointing down
    	glNormal3f(0, -1, 0);
    	glVertex3f(sin(angle) * radius+40, 80, cos(angle) * radius+178);
	}
	glEnd();
	
}

void draw_cone3(GLfloat height,GLfloat radius)
{
	// draw the upper part of the cone
	glColor3f(0.53,0.12,0.47);
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(-10, height+80,164);
	for (angle = 0; angle < 360; angle++) 
	{
    	glVertex3f(sin(angle) * radius-10, 80, cos(angle) * radius+164);
	}
	glEnd();

	// draw the base of the cone
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(-10, 80, 164);
	for (angle = 0; angle < 360; angle++) 
	{
    	// normal is just pointing down
    	glNormal3f(0, -1, 0);
    	glVertex3f(sin(angle) * radius-10, 80, cos(angle) * radius+164);
	}
	glEnd();
}

void draw_cone4(GLfloat height,GLfloat radius)
{
	// draw the upper part of the cone
	glColor3f(0.53,0.12,0.47);
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(-10, height+80,178);
	for (angle = 0; angle < 360; angle++) 
	{
    	glVertex3f(sin(angle) * radius-10, 80, cos(angle) * radius+178);
	}
	glEnd();

	// draw the base of the cone
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(-10, 80, 178);
	for (angle = 0; angle < 360; angle++) 
	{
    	// normal is just pointing down
    	glNormal3f(0, -1, 0);
    	glVertex3f(sin(angle) * radius-10, 80, cos(angle) * radius+178);
	}
	glEnd();
}


void bezierCoefficients(int n,int *c)
{
	int k,i;
	for(k=0;k<=n;k++)
	{
		c[k]=1;
		for(i=n;i>=k+1;i--)
		c[k]*=i;
		for(i=n-k;i>=2;i--)
			c[k]/=i;

	}
}

void wire8()
{
	int cp[4][3]={{88,241,15},{88,281,80},{88,141,-100},{88,221,-240}};
	int c[4],k,n=3;
	float x,y,u,z,blend;
	bezierCoefficients(n,c);
	glColor3f(1.0,0.0,0.0);
	glLineWidth(3.0);
	glBegin(GL_LINE_STRIP);

	for(u=0;u<1.0;u+=0.01)
	{
		x=0;y=0;z=0;
		for(k=0;k<4;k++)
		{
			blend=c[k]*pow(u,k)*pow(1-u,n-k);
			x+=cp[k][0]*blend;
			y+=cp[k][1]*blend;
			z+=cp[k][2]*blend;
		}
		glVertex3f(x,y,z);

	}
	glEnd();
}

void wire7()
{
	int cp[4][3]={{30,240,15},{30,281,80},{30,141,-100},{30,221,-240}};
	int c[4],k,n=3;
	float x,y,u,z,blend;
	bezierCoefficients(n,c);
	glColor3f(1.0,0.0,0.0);
	glLineWidth(3.0);
	glBegin(GL_LINE_STRIP);

	for(u=0;u<1.0;u+=0.01)
	{
		x=0;y=0;z=0;
		for(k=0;k<4;k++)
		{
			blend=c[k]*pow(u,k)*pow(1-u,n-k);
			x+=cp[k][0]*blend;
			y+=cp[k][1]*blend;
			z+=cp[k][2]*blend;
		}
		glVertex3f(x,y,z);

	}
	glEnd();
}

void wire6()
{
	int cp[4][3]={{3,241,15},{3,281,80},{3,141,-100},{3,221,-240}};
	int c[4],k,n=3;
	float x,y,u,z,blend;
	bezierCoefficients(n,c);
	glColor3f(1.0,0.0,0.0);
	glLineWidth(3.0);
	glBegin(GL_LINE_STRIP);

	for(u=0;u<1.0;u+=0.01)
	{
		x=0;y=0;z=0;
		for(k=0;k<4;k++)
		{
			blend=c[k]*pow(u,k)*pow(1-u,n-k);
			x+=cp[k][0]*blend;
			y+=cp[k][1]*blend;
			z+=cp[k][2]*blend;
		}
		glVertex3f(x,y,z);

	}
	glEnd();
}

void wire5()
{
	int cp[4][3]={{-40,243,15},{-40,283,80},{-40,143,-100},{-40,223,-240}};
	int c[4],k,n=3;
	float x,y,u,z,blend;
	bezierCoefficients(n,c);
	glColor3f(1.0,0.0,0.0);
	glLineWidth(3.0);
	glBegin(GL_LINE_STRIP);

	for(u=0;u<1.0;u+=0.01)
	{
		x=0;y=0;z=0;
		for(k=0;k<4;k++)
		{
			blend=c[k]*pow(u,k)*pow(1-u,n-k);
			x+=cp[k][0]*blend;
			y+=cp[k][1]*blend;
			z+=cp[k][2]*blend;
		}
		glVertex3f(x,y,z);

	}
	glEnd();
}

void wire4()
{
	
	int cp[4][3]={{45,90,161},{45,170,161},{25,130,11},{65,260,11}};
	int c[4],k,n=3;
	float x,y,u,z,blend;
	bezierCoefficients(n,c);
	glColor3f(1.0,0.0,0.0);
	glLineWidth(3.0);
	glBegin(GL_LINE_STRIP);

	for(u=0;u<1.0;u+=0.01)
	{
		x=0;y=0;z=0;
		for(k=0;k<4;k++)
		{
			blend=c[k]*pow(u,k)*pow(1-u,n-k);
			x+=cp[k][0]*blend;
			y+=cp[k][1]*blend;
			z+=cp[k][2]*blend;
		}
		glVertex3f(x,y,z);

	}
	glEnd();
}

void wire3()
{
	int cp[4][3]={{-5,90,160},{-5,170,160},{-5,150,10},{-18,260,10}};
	int c[4],k,n=3;
	float x,y,u,z,blend;
	bezierCoefficients(n,c);
	glColor3f(1.0,0.0,0.0);
	glLineWidth(3.0);
	glBegin(GL_LINE_STRIP);

	for(u=0;u<1.0;u+=0.01)
	{
		x=0;y=0;z=0;
		for(k=0;k<4;k++)
		{
			blend=c[k]*pow(u,k)*pow(1-u,n-k);
			x+=cp[k][0]*blend;
			y+=cp[k][1]*blend;
			z+=cp[k][2]*blend;
		}
		glVertex3f(x,y,z);

	}
	glEnd();
}

void wire2()
{
	
	int cp[4][3]={{45,70,171},{45,150,171},{45,150,191},{45,70,191}};
	int c[4],k,n=3;
	float x,y,u,z,blend;
	bezierCoefficients(n,c);
	glColor3f(1.0,0.0,0.0);
	glLineWidth(3.0);
	glBegin(GL_LINE_STRIP);

	for(u=0;u<1.0;u+=0.01)
	{
		x=0;y=0;z=0;
		for(k=0;k<4;k++)
		{
			blend=c[k]*pow(u,k)*pow(1-u,n-k);
			x+=cp[k][0]*blend;
			y+=cp[k][1]*blend;
			z+=cp[k][2]*blend;
		}
		glVertex3f(x,y,z);

	}
	glEnd();
}


void wire1()
{
	int cp[4][3]={{-5,70,170},{-5,150,170},{-5,150,190},{-5,70,190}};
	int c[4],k,n=3;
	float x,y,u,z,blend;
	bezierCoefficients(n,c);
	glColor3f(1.0,0.0,0.0);
	glLineWidth(3.0);
	glBegin(GL_LINE_STRIP);

	for(u=0;u<1.0;u+=0.01)
	{
		x=0;y=0;z=0;
		for(k=0;k<4;k++)
		{
			blend=c[k]*pow(u,k)*pow(1-u,n-k);
			x+=cp[k][0]*blend;
			y+=cp[k][1]*blend;
			z+=cp[k][2]*blend;
		}
		glVertex3f(x,y,z);

	}
	glEnd();
}
void electricity()
{
	//filled circle
		
		float x2,y2;
		
		double radius=3;
		
		glColor3f(1.0,1.0,0.0);
		
		glBegin(GL_TRIANGLE_FAN);
		glVertex3f(xe,ye,ze);
		
		for (angle_e=1.0f;angle_e<361.0f;angle_e+=0.2)
		{
		    x2 = xe+sin(angle_e)*radius;
		    y2 = ye+cos(angle_e)*radius;
		    glVertex3f(x2,y2,ze);
		}
		
		glEnd();
		
}

void timer(int v)
{
	
	int cp[4][3]={{-5,70,190},{-5,150,190},{-5,150,170},{-5,70,170}};
	int c[4],k,n=3;
	bezierCoefficients(n,c);
	ue+=0.001;
	
	xe=0;ye=0;ze=0;
	for(k=0;k<4;k++)
	{
		blend=c[k]*pow(ue,k)*pow(1-ue,n-k);
		xe+=cp[k][0]*blend;
		ye+=cp[k][1]*blend;
		ze+=cp[k][2]*blend;
	}
	if(ye<=70)
		{
			//electricity();
			glutPostRedisplay();
			ue=0;
			glutTimerFunc(0,timer,1);
		}
	else
	{
		electricity();
	}
}

void timer2(int v)
{
	int cp[4][3]={{45,70,191},{45,150,191},{45,150,171},{45,70,171}};
	int c[4],k,n=3;
	
	bezierCoefficients(n,c);
	glColor3f(1.0,0.0,0.0);
	
	ue+=0.001;
	
	xe=0;ye=0;ze=0;
	for(k=0;k<4;k++)
	{
		blend=c[k]*pow(ue,k)*pow(1-ue,n-k);
		xe+=cp[k][0]*blend;
		ye+=cp[k][1]*blend;
		ze+=cp[k][2]*blend;
	}
	if(ye<=70)
		{
			//electricity();
			glutPostRedisplay();
			ue=0;
			glutTimerFunc(0,timer,1);
		}
	else
	{
		electricity();
	}
	
}

void timer3(int v)
{
	int cp[4][3]={{-5,90,160},{-5,170,160},{-5,150,10},{-18,260,10}};
	int c[4],k,n=3;
	
	bezierCoefficients(n,c);
	glColor3f(1.0,0.0,0.0);
	
	ue+=0.000001;
	
	xe=0;ye=0;ze=0;
	for(k=0;k<4;k++)
	{
		blend=c[k]*pow(ue,k)*pow(1-ue,n-k);
		xe+=cp[k][0]*blend;
		ye+=cp[k][1]*blend;
		ze+=cp[k][2]*blend;
	}
	if(ye<=70)
		{
			//electricity();
			glutPostRedisplay();
			ue=0;
			glutTimerFunc(0,timer,1);
		}
	else
	{
		electricity();
	}


}

void timer4(int v)
{
	int cp[4][3]={{45,90,161},{45,170,161},{25,130,11},{65,260,11}};
	int c[4],k,n=3;
	
	bezierCoefficients(n,c);
	glColor3f(1.0,0.0,0.0);
	
	ue+=0.000001;
	
	xe=0;ye=0;ze=0;
	for(k=0;k<4;k++)
	{
		blend=c[k]*pow(ue,k)*pow(1-ue,n-k);
		xe+=cp[k][0]*blend;
		ye+=cp[k][1]*blend;
		ze+=cp[k][2]*blend;
	}
	if(ye<=70)
		{
			//electricity();
			glutPostRedisplay();
			ue=0;
			glutTimerFunc(0,timer,1);
		}
	else
	{
		electricity();
	}
	

}

void timer5(int v)
{
	int cp[4][3]={{-40,243,15},{-40,283,80},{-40,143,-100},{-40,223,-240}};
	int c[4],k,n=3;
	
	bezierCoefficients(n,c);
	glColor3f(1.0,0.0,0.0);
	
	ue+=0.000001;
	
	xe=0;ye=0;ze=0;
	for(k=0;k<4;k++)
	{
		blend=c[k]*pow(ue,k)*pow(1-ue,n-k);
		xe+=cp[k][0]*blend;
		ye+=cp[k][1]*blend;
		ze+=cp[k][2]*blend;
	}
	if(ye<=70)
		{
			//electricity();
			glutPostRedisplay();
			ue=0;
			glutTimerFunc(0,timer,1);
		}
	else
	{
		electricity();
	}
	

}

void timer6(int v)
{
	int cp[4][3]={{3,241,15},{3,281,80},{3,141,-100},{3,221,-240}};
	int c[4],k,n=3;
	
	bezierCoefficients(n,c);
	glColor3f(1.0,0.0,0.0);
	
	ue+=0.000001;
	
	xe=0;ye=0;ze=0;
	for(k=0;k<4;k++)
	{
		blend=c[k]*pow(ue,k)*pow(1-ue,n-k);
		xe+=cp[k][0]*blend;
		ye+=cp[k][1]*blend;
		ze+=cp[k][2]*blend;
	}
	if(ye<=70)
		{
			//electricity();
			glutPostRedisplay();
			ue=0;
			glutTimerFunc(0,timer,1);
		}
	else
	{
		electricity();
	}	
}

void timer7(int v)
{
	int cp[4][3]={{30,240,15},{30,281,80},{30,141,-100},{30,221,-240}};
	int c[4],k,n=3;
	
	bezierCoefficients(n,c);
	glColor3f(1.0,0.0,0.0);
	
	ue+=0.000001;
	
	xe=0;ye=0;ze=0;
	for(k=0;k<4;k++)
	{
		blend=c[k]*pow(ue,k)*pow(1-ue,n-k);
		xe+=cp[k][0]*blend;
		ye+=cp[k][1]*blend;
		ze+=cp[k][2]*blend;
	}
	if(ye<=70)
		{
			//electricity();
			glutPostRedisplay();
			ue=0;
			glutTimerFunc(0,timer,1);
		}
	else
	{
		electricity();
	}
}

void timer8(int v)
{
	int cp[4][3]={{88,241,15},{88,281,80},{88,141,-100},{88,221,-240}};
	int c[4],k,n=3;
	
	bezierCoefficients(n,c);
	glColor3f(1.0,0.0,0.0);
	
	ue+=0.000001;
	
	xe=0;ye=0;ze=0;
	for(k=0;k<4;k++)
	{
		blend=c[k]*pow(ue,k)*pow(1-ue,n-k);
		xe+=cp[k][0]*blend;
		ye+=cp[k][1]*blend;
		ze+=cp[k][2]*blend;
	}
	if(ye<=70)
		{
			//electricity();
			glutPostRedisplay();
			ue=0;
			glutTimerFunc(0,timer,1);
		}
	else
	{
		electricity();
	}
	

}


void waterFlow1()
{
    glColor3f(0.0, 0.0, 1.0);
    glPointSize(6);
    glBegin(GL_POINTS);
    glVertex3f(-60.0+xt, yt+69.0,zt+ 0.0);
    glVertex3f(-60.0+xt, yt+64.0,zt+ -10.0);
    glVertex3f(-60.0+xt, yt+66.0,zt+ -30.0);
    glVertex3f(-60.0+xt, yt+66.0,zt+ 10.0);
    glEnd();
    
    
    if(zt<80)
    {
	    zt=zt+0.2;
	    glutTimerFunc(10000,waterFlow1,1);
	}
	else
		{
			zt=0;
			glutTimerFunc(10000,waterFlow1,1);
		}
}
void waterFlow2()
{
    glColor3f(0.0, 0.0, 1.0);
    glPointSize(6);
    glBegin(GL_POINTS);
    glVertex3f(-90.0, 8.0, 254.0+zt1);
    glVertex3f(-88.0, 7.0,260.0+zt1);
    glVertex3f(-90.0, 7.0, 254.0+zt1);
    glVertex3f(-87.0, 8.0, 260.0+zt1);
    glEnd();
    
    if(zt1<6)
    {
	    zt1=zt1+0.2;
	    glutTimerFunc(10000,waterFlow2,1);
	}
	else
		{
			zt1=0;
			glutTimerFunc(10000,waterFlow2,1);
		}
}

void waterFlow3()
{
    glColor3f(0.0, 0.0, 1.0);
    glPointSize(6);
	glBegin(GL_POINTS);
    glVertex3f(-42.0,-52.0-yt2,220.0);
    glVertex3f(-42.0,-54.0-yt2,220.0);
    glVertex3f(-42.0,-58.0-yt2,225.0);
    glVertex3f(-42.0,-55.0-yt2,225.0);
    glEnd();
    if(yt2<40)
    {
    	yt2=yt2+0.2;
    	glutTimerFunc(10000,waterFlow3,1);
	}
	else{
		yt2=0;
		glutTimerFunc(10000,waterFlow3,1);
	}
    
}

void waterFlow4()
{
    glColor3f(0.0, 0.0, 1.0);
    glPointSize(6);
	glBegin(GL_POINTS);
    glVertex3f(-52.0,-122.0,240.0+zt2);
    glVertex3f(-52.0,-124.0,240.0+zt2);
    glVertex3f(-52.0,-128.0,245.0+zt2);
    glVertex3f(-52.0,-125.0,245.0+zt2);
    glEnd();
    if(zt2<40)
    {
    	zt2=zt2+0.2;
    	glutTimerFunc(10000,waterFlow4,1);
	}
	else{
		zt2=0;
		glutTimerFunc(10000,waterFlow4,1);
	}
    
}

void TurbineBlade1()
{
	
	glBegin(GL_QUADS);
	glColor3f(0.5,0.35,0.05);
	glVertex3f(-40.0,-30.0,190.0);
	glVertex3f(-40.0,-60.0,190.0);
	glVertex3f(-40.0,-60.0,240.0);
	glVertex3f(-40.0,-30.0,240.0);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3f(0.5,0.35,0.05);
	glVertex3f(-65.0,-30.0,215.0);
	glVertex3f(-65.0,-60.0,215.0);
	glVertex3f(-15.0,-60.0,215.0);
	glVertex3f(-15.0,-30.0,215.0);
	glEnd();
}

void TurbineBlade2(int a,int b ,int c)
{
	glPushMatrix();
	glTranslatef( center_x, center_y, center_z );
    glRotatef(current_angle, 0, 1, 0);
    current_angle += step_angle;
    glTranslatef(-center_x, -center_y, -center_z );

	 // draw first rotor blade
	glBegin(GL_QUADS);
	glColor3f(0.5,0.35,0.05);
	glVertex3f(-40.0+a,-30.0+b,190.0+c);
	glVertex3f(-40.0+a,-60.0+b,190.0+c);
	glVertex3f(-40.0+a,-60.0+b,215.0+c);
	glVertex3f(-40.0+a,-30.0+b,215.0+c);
	glEnd();
	// draw second rotor blade
	glBegin(GL_QUADS);
	glVertex3f(-40.0+a,-30.0+b,215.0+c);
	glVertex3f(-40.0+a,-60.0+b,215.0+c);
	glVertex3f(-40.0+a,-60.0+b,240.0+c);
	glVertex3f(-40.0+a,-30.0+b,240.0+c);
	glEnd();
	// draw third rotor blade
	glBegin(GL_QUADS);
	glColor3f(0.5,0.35,0.05);
	glVertex3f(-65.0+a,-30.0+b,215.0+c);
	glVertex3f(-65.0+a,-60.0+b,215.0+c);
	glVertex3f(-40.0+a,-60.0+b,215.0+c);
	glVertex3f(-40.0+a,-30.0+b,215.0+c);
	glEnd();
	// draw fourth rotor blade
	glBegin(GL_QUADS);
	glVertex3f(-40.0+a,-30.0+b,215.0+c);
	glVertex3f(-40.0+a,-60.0+b,215.0+c);
	glVertex3f(-15.0+a,-60.0+b,215.0+c);
	glVertex3f(-15.0+a,-30.0+b,215.0+c);
	glEnd();
	
	glColor3f(0.0, 0.0, 1.0);
    glPointSize(8);
    glBegin(GL_POINTS);
    glVertex3f(-40.0+a,-60.0+b,190.0+c);
    glVertex3f(-40.0+a,-50.0+b,190.0+c);
    glVertex3f(-40.0+a,-60.0+b,200.0+c);
    glVertex3f(-50.0+a,-50.0+b,190.0+c);
    glVertex3f(-40.0+a,-60.0+b,190.0+c);
    glVertex3f(-40.0+a,-60.0+b,190.0+c);
    
    glEnd();
	glPopMatrix();
}

void timer9(int v)
{ 
	TurbineBlade2(0,0,0);
}


void display1()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	
    title1();
    
    glutSwapBuffers();
}
	

void display2()
{
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	
	timer(0);
	timer2(0);
	timer3(0);
	timer4(0);
	timer5(0);
	timer6(0);
	timer7(0);
	timer8(0);
	
	
	wire1();
	wire2();
	wire3();
	wire4();
	wire5();
	wire6();
	wire7();
	wire8();
	
	glLoadIdentity();

	title2();

	glTranslatef(-130.0,0.0,-550.0);
	
	glRotatef(40.0,1.0,1.0,0.0);
	glRotatef(60.0,0.0,1.0,0.0);
	glRotatef(20.0,0.0,0.0,1.0);
	glRotatef(-50.0,0.0,1.0,0.0);
	
	
	//glRotatef(10.0,1.0,0.0,0.0);
	
	//timer1(0);
	
	draw_cylinder1(15.0, 80.0, 235, 185, 157); 
	draw_cylinder2(15.0, 80.0, 235, 185, 157); 
	draw_cylinder3(2.50, 280.0, 235, 185, 157); 
	draw_cylinder4(2.50, 280.0, 235, 185, 157); 
	draw_cylinder5(2.50, 50.0); 
	draw_cylinder6(2.50, 30.0); 
	draw_cylinder7(2.50, 55.0); 
	draw_cylinder8(2.50, 30.0); 
	draw_cone1(30.0,5.5);
	draw_cone2(25.0,4.5);
	draw_cone3(30.0,5.5);
	draw_cone4(25.0,4.5);

	//vertical first cube
	
	
	glBegin(GL_QUADS);
	
	//front
	glColor3f(0.0,0.5,0.0);
	glVertex3f(-120.0,180.0,10.0);
	glColor3f(0.0,1.0,0.0);
	glVertex3f(-120.0,-60.0,10.0);
	glVertex3f(-40.0,-60.0,10.0);
	glColor3f(0.0,1.0,0.0);
	glVertex3f(-40.0,180.0,10.0);

	//back
	glColor3f(0.0,0.5,0.0);
	glVertex3f(-120.0,180.0,-30.0);
	glVertex3f(-120.0,-60.0,-30.0);
	glVertex3f(-40.0,-60.0,-30.0);
	glVertex3f(-40.0,180.0,-30.0);
	
	//right
	glColor3f(0.0,0.0,0.0);
	glVertex3f(-40.0,180.0,10.0);
	glVertex3f(-40.0,-60.0,10.0);
	glVertex3f(-40.0,-60.0,-30.0);
	glVertex3f(-40.0,180.0,-30.0);
	
	//left
	glColor3f(0.0,0.0,0.0);
	glVertex3f(-120.0,180.0,-30.0);
	glVertex3f(-120.0,-60.0,-30.0);
	glVertex3f(-120.0,-60.0,10.0);
	glVertex3f(-120.0,180.0,10.0);
	
	//top
	glColor3f(0.0,0.5,0.0);
	glVertex3f(-120.0,180.0,-30.0);
	glVertex3f(-120.0,180.0,10.0);
	glColor3f(0.0,1.0,0.0);
	glVertex3f(-40.0,180.0,10.0);
	glVertex3f(-40.0,180.0,-30.0);
	
	//bottom
	glColor3f(0.0,0.0,0.0);
	glVertex3f(-120.0,-60.0,-30.0);
	glVertex3f(-120.0,-60.0,10.0);
	glVertex3f(-40.0,-60.0,10.0);
	glVertex3f(-40.0,-60.0,-30.0);
	
	glEnd();
	
	//grey1
	glBegin(GL_QUADS);
	
	//front
	glColor3f(0.4,0.4,0.4);
	glVertex3f(-40.0,175.0,20.0);
	glColor3f(0.8,0.8,0.8);
	glVertex3f(-40.0,-60.0,20.0);
	glVertex3f(60.0,-60.0,20.0);
	glVertex3f(60.0,175.0,20.0);
	
	
	//back
	glColor3f(0.4,0.4,0.4);
	glVertex3f(-40.0,175.0,0.0);
	glVertex3f(-40.0,-60.0,0.0);
	glVertex3f(60.0,-60.0,0.0);
	glVertex3f(60.0,175.0,0.0);
	
	//left
	glColor3f(0.4,0.4,0.4);
	glVertex3f(-40.0,175.0,0.0);
	glVertex3f(-40.0,-60.0,0.0);
	glVertex3f(-40.0,-60.0,20.0);
	glVertex3f(-40.0,175.0,20.0);
	
	//top
	glColor3f(0.8,0.8,0.8);
	glVertex3f(-40.0,175.0,0.0);
	glVertex3f(-40.0,175.0,20.0);
	glVertex3f(60.0,175.0,20.0);
	glVertex3f(60.0,175.0,0);
	
	glEnd();
	
	//grey2
	glBegin(GL_QUADS);
	
	//top
	glColor3f(0.8,0.8,0.8);
	glVertex3f(-40.0,145.0,20.0);
	glVertex3f(-40.0,145.0,60.0);
	glVertex3f(60.0,145.0,60.0);
	glVertex3f(60.0,145.0,20.0);
	
	//front
	glColor3f(0.4,0.4,0.4);
	glVertex3f(-40.0,145.0,60.0);
	glColor3f(0.8,0.8,0.8);
	glVertex3f(-40.0,-60.0,60.0);
	glVertex3f(60.0,-60.0,60.0);
	glVertex3f(60.0,145.0,60.0);
	
	//left
	glColor3f(0.4,0.4,0.4);
	glVertex3f(-40.0,145.0,20.0);
	glColor3f(0.8,0.8,0.8);
	glVertex3f(-40.0,-60.0,20.0);
	glVertex3f(-40.0,-60.0,60.0);
	glVertex3f(-40.0,145.0,60.0);
	
	glEnd();
	
	//grey3
	glBegin(GL_QUADS);
	//front
	glColor3f(0.4,0.4,0.4);
	glVertex3f(-40.0,85.0,140.0);
	glColor3f(0.8,0.8,0.8);
	glVertex3f(-40.0,-60.0,140.0);
	glVertex3f(60.0,-60.0,140.0);
	glVertex3f(60.0,85.0,140.0);
	
	//top
	glColor3f(0.4,0.4,0.4);
	glVertex3f(-40.0,135.0,60.0);
	glColor3f(0.8,0.8,0.8);
	glVertex3f(-40.0,85.0,140.0);
	glColor3f(0.8,0.8,0.8);
	glVertex3f(60.0,85.0,140.0);
	glVertex3f(60.0,135.0,60.0);
	
	//left
	glColor3f(0.4,0.4,0.4);
	glVertex3f(-40.0,135.0,60.0);
	glVertex3f(-40.0,-60.0,60.0);
	glVertex3f(-40.0,-60.0,140.0);
	glVertex3f(-40.0,85.0,140.0);
	
	glEnd();
	
	//grey4
	glBegin(GL_QUADS);
	//front
	glColor3f(0.4,0.4,0.4);
	glVertex3f(-40.0,40.0,190.0);
	glColor3f(0.8,0.8,0.8);
	glVertex3f(-40.0,-60.0,190.0);
	glVertex3f(60.0,-60.0,190.0);
	glVertex3f(60.0,40.0,190.0);
	
	//top
	glColor3f(0.4,0.4,0.4);
	glVertex3f(-40.0,40.0,140.0);
	glColor3f(0.8,0.8,0.8);
	glVertex3f(-40.0,40.0,190.0);
	glColor3f(0.8,0.8,0.8);
	glVertex3f(60.0,40.0,190.0);
	glVertex3f(60.0,40.0,140.0);
	
	//left
	glColor3f(0.4,0.4,0.4);
	glVertex3f(-40.0,40.0,140.0);

	glVertex3f(-40.0,-60.0,140.0);
	glColor3f(0.8,0.8,0.8);
	glVertex3f(-40.0,-60.0,190.0);
	glVertex3f(-40.0,40.0,190.0);
	
	glEnd();
	
	//grey5
	glBegin(GL_QUADS);
	//front
	glColor3f(0.4,0.4,0.4);
	glVertex3f(-40.0,70.0,240.0);
	glColor3f(0.8,0.8,0.8);
	glVertex3f(-40.0,-60.0,240.0);
	glVertex3f(60.0,-60.0,240.0);
	glVertex3f(60.0,70.0,240.0);
	
	//top
	glColor3f(0.4,0.4,0.4);
	glVertex3f(-40.0,70.0,190.0);
	glColor3f(0.8,0.8,0.8);
	glVertex3f(-40.0,70.0,240.0);
	glVertex3f(60.0,70.0,240.0);
	glVertex3f(60.0,70.0,190.0);
	
	//left
	glColor3f(0.4,0.4,0.4);
	glVertex3f(-40.0,70.0,190.0);
	glVertex3f(-40.0,-60.0,190.0);
	glColor3f(0.8,0.8,0.8);
	glVertex3f(-40.0,-60.0,240.0);
	glVertex3f(-40.0,70.0,240.0);
	
	//bottom
	glColor3f(0.4,0.4,0.4);
	glVertex3f(-40.0,-60.0,190.0);
	glVertex3f(-40.0,-60.0,240.0);
	glVertex3f(60.0,-60.0,240.0);
	glVertex3f(60.0,-60.0,190.0);
	
	glEnd();	
	
	//horizontal first cube
	
	glBegin(GL_QUADS);
	
	//bottom
	glColor3f(0.0,0.5,0.0);
	glVertex3f(-120.0,-60.0,10.0);
	glVertex3f(-120.0,-60.0,240.0);
	glVertex3f(-40.0,-60.0,240.0);
	glVertex3f(-40.0,-60.0,10.0);
	
	//top
	glColor3f(0.0,0.5,0.0);
	glVertex3f(-120.0,-10.0,10.0);
	glVertex3f(-120.0,-10.0,240.0);
	glVertex3f(-40.0,-10.0,240.0);
	glVertex3f(-40.0,-10.0,10.0);
	
	//left
	glColor3f(0.0,0.0,0.0);
	glVertex3f(-120.0,-60.0,10.0);
	glVertex3f(-120.0,-60.0,240.0);
	glVertex3f(-120.0,-10.0,240.0);
	glVertex3f(-120.0,-10.0,10.0);
	
	//front
	glColor3f(0.0,0.0,0.0);
	glVertex3f(-120.0,-10.0,240.0);
	glVertex3f(-120.0,-60.0,240.0);
	glVertex3f(-40.0,-60.0,240.0);
	glVertex3f(-40.0,-10.0,240.0);
	
	glEnd();

	//water1
	
	glBegin(GL_QUADS);
	
	//front
	glColor3f(0.0,0.5,1.0);
	glVertex3f(-40.0,170.0,0.0);
	glVertex3f(-40.0,-60.0,0.0);
	glVertex3f(60.0,-60.0,0.0);
	glVertex3f(60.0,170.0,0.0);
	
	//back
	glColor3f(0.0,0.5,1.0);
	glVertex3f(-40.0,170.0,-180.0);
	glVertex3f(-40.0,-60.0,-180.0);
	glVertex3f(60.0,-60.0,-180.0);
	glVertex3f(60.0,170.0,-180.0);
	
	//top
	glColor3f(0.0,0.5,1.0);
	glVertex3f(-40.0,170.0,-180.0);
	glColor3f(0.0,0.0,1.0);
	glVertex3f(-40.0,170.0,0.0);
	glVertex3f(60.0,170.0,0.0);
	glVertex3f(60.0,170.0,-180.0);

	//right
	glColor3f(0.0,0.5,1.0);
	glVertex3f(60.0,170.0,0.0);
	glVertex3f(60.0,-60.0,0.0);
	glVertex3f(60.0,-60.0,-180.0);
	glVertex3f(60.0,170.0,-180.0);
	
	//left
	glColor3f(0.0,0.5,1.0);
	glVertex3f(-40.0,170.0,-180.0);
	glVertex3f(-40.0,-60.0,-180.0);
	glVertex3f(-40.0,-60.0,0.0);
	glVertex3f(-40.0,170.0,0.0);
	
	//bottom
	glColor3f(0.0,0.5,1.0);
	glVertex3f(-40.0,-60.0,-180.0);
	glVertex3f(-40.0,-60.0,0.0);
	glVertex3f(60.0,-60.0,0.0);
	glVertex3f(60.0,-60.0,-180.0);
	
	glEnd();
	
	//vertical second cube
	
	glBegin(GL_QUADS);
	
	//front
	glColor3f(0.0,0.5,0.0);
	glVertex3f(60.0,180.0,10.0);
	glColor3f(0.0,1.0,0.0);
	glVertex3f(60.0,-60.0,10.0);
	glVertex3f(450.0,-60.0,10.0);
	glColor3f(0.0,1.0,0.0);
	glVertex3f(450.0,180.0,10.0);
	
	//back
	glColor3f(0.0,0.5,0.0);
	glVertex3f(60.0,180.0,-30.0);
	glVertex3f(60.0,-60.0,-30.0);
	glVertex3f(450.0,-60.0,-30.0);
	glVertex3f(450.0,180.0,-30.0);
	
	//right
	glColor3f(0.0,0.0,0.0);
	glVertex3f(450.0,180.0,10.0);
	glVertex3f(450.0,-60.0,10.0);
	glVertex3f(450.0,-60.0,-30.0);
	glVertex3f(450.0,180.0,-30.0);
	
	//left
	glColor3f(0.0,0.0,0.0);
	glVertex3f(60.0,180.0,-30.0);
	glVertex3f(60.0,-60.0,-30.0);
	glVertex3f(60.0,-60.0,10.0);
	glVertex3f(60.0,180.0,10.0);
	
	//top
	glColor3f(0.0,0.5,0.0);
	glVertex3f(60.0,180.0,-30.0);
	glVertex3f(60.0,180.0,10.0);
	glColor3f(0.0,1.0,0.0);
	glVertex3f(450.0,180.0,10.0);
	glVertex3f(450.0,180.0,-30.0);
	
	//bottom
	glColor3f(0.0,0.0,0.0);
	glVertex3f(60.0,-60.0,-30.0);
	glVertex3f(60.0,-60.0,10.0);
	glVertex3f(450.0,-60.0,10.0);
	glVertex3f(450.0,-60.0,-30.0);
	
	glEnd();
	
	//horizontal second cube
	
	glBegin(GL_QUADS);
	
	//bottom
	glColor3f(0.0,0.5,0.0);
	glVertex3f(60.0,-60.0,10.0);
	glVertex3f(60.0,-60.0,240.0);
	glVertex3f(450.0,-60.0,240.0);
	glVertex3f(450.0,-60.0,10.0);
	
	//top
	glColor3f(0.0,0.5,0.0);
	glVertex3f(60.0,-10.0,10.0);
	glVertex3f(60.0,-10.0,240.0);
	glVertex3f(450.0,-10.0,240.0);
	glVertex3f(450.0,-10.0,10.0);
	
	//left
	glColor3f(0.0,0.0,0.0);
	glVertex3f(60.0,-60.0,10.0);
	glVertex3f(60.0,-60.0,240.0);
	glVertex3f(60.0,-10.0,240.0);
	glVertex3f(60.0,-10.0,10.0);
	
	//front
	glColor3f(0.0,0.0,0.0);
	glVertex3f(60.0,-10.0,240.0);
	glVertex3f(60.0,-60.0,240.0);
	glVertex3f(450.0,-60.0,240.0);
	glVertex3f(450.0,-10.0,240.0);
	
	glEnd();
	
	//water2
	
	glBegin(GL_QUADS);
	
	//front
	glColor3f(0.0,0.0,1.0);
	glVertex3f(-40.0,-20.0,350.0);
	glColor3f(0.0,0.5,1.0);
	glVertex3f(-40.0,-180.0,350.0);
	glVertex3f(60.0,-180.0,350.0);
	glVertex3f(60.0,-20.0,350.0);
	
	//back
	glColor3f(0.0,0.5,1.0);
	glVertex3f(-40.0,-20.0,240.0);
	glVertex3f(-40.0,-180.0,240.0);
	glVertex3f(60.0,-180.0,240.0);
	glVertex3f(60.0,-20.0,240.0);
	
	//top
	glColor3f(0.0,0.5,1.0);
	
	glVertex3f(-40.0,-20.0,240.0);
	glVertex3f(-40.0,-20.0,350.0);
	glVertex3f(60.0,-20.0,350.0);
	glVertex3f(60.0,-20.0,240.0);

	//left
	glColor3f(0.0,0.5,1.0);
	glVertex3f(-40.0,-20.0,240.0);
	glVertex3f(-40.0,-180.0,240.0);
	glColor3f(0.0,0.0,1.0);
	glVertex3f(-40.0,-180.0,350.0);
	glVertex3f(-40.0,-20.0,350.0);
	

	
	glEnd();
	
	//slope1
	
	glBegin(GL_QUAD_STRIP);
	
	glColor3f(0.0,0.5,0.0);
	glVertex3f(-40.0,180.0,10.0);
	glVertex3f(-40.0,120.0,50.0);
	glVertex3f(-120.0,180.0,10.0);
	glVertex3f(-120.0,120.0,50.0);

	glVertex3f(-40.0,120.0,50.0);
	glVertex3f(-40.0,70.0,65.0);
	glVertex3f(-120.0,120.0,50.0);
	glVertex3f(-120.0,70.0,65.0);
	
	glVertex3f(-40.0,70.0,65.0);
	glVertex3f(-40.0,30.0,75.0);
	glVertex3f(-120.0,70.0,65.0);
	glVertex3f(-120.0,30.0,75.0);	
	
	
	glVertex3f(-40.0,30.0,75.0);
	glVertex3f(-40.0,20,125);
	glVertex3f(-120.0,30.0,75.0);	
	glVertex3f(-120,20,125);
	
	glVertex3f(-40.0,20,125);
	glVertex3f(-40,-10,240);
	glVertex3f(-120,20,125);
	glVertex3f(-120,-10,240);
	
	
	glEnd();
	
	//left slope1
	glBegin(GL_QUADS);
	
	glColor3f(0.0,0.0,0.0);
	glVertex3f(-120.0,180.0,10.0);
	glVertex3f(-120.0,-60.0,10.0);
	glVertex3f(-120.0,-60.0,50.0);
	glVertex3f(-120.0,120.0,50.0);
	
	glVertex3f(-120.0,120.0,50.0);
	glVertex3f(-120.0,-60.0,50.0);
	glVertex3f(-120.0,120.0,65.0);
	glVertex3f(-120.0,-60.0,65.0);
	
	glVertex3f(-120.0,-60.0,65.0);
	glVertex3f(-120.0,120.0,65.0);
	glVertex3f(-120,-120.0,75.0);
	glVertex3f(-120.0,-60.0,75.0);	
	
	glEnd();
	
	//slope2
	
	glBegin(GL_QUAD_STRIP);
	
	glColor3f(0.0,0.5,0.0);
	glVertex3f(450.0,180.0,10.0);
	glVertex3f(450.0,120.0,50.0);
	glVertex3f(60.0,180.0,10.0);
	glVertex3f(60.0,120.0,50.0);

	glVertex3f(450.0,120.0,50.0);
	glVertex3f(450.0,70.0,65.0);
	glVertex3f(60.0,120.0,50.0);
	glVertex3f(60.0,70.0,65.0);
	
	glVertex3f(450.0,70.0,65.0);
	glVertex3f(450.0,30.0,75.0);
	glVertex3f(60.0,70.0,65.0);
	glVertex3f(60.0,30.0,75.0);	
	
	
	glVertex3f(450.0,30.0,75.0);
	glVertex3f(450.0,20,125);
	glVertex3f(60.0,30.0,75.0);	
	glVertex3f(60,20,125);
	
	glVertex3f(450.0,20,125);
	glVertex3f(450,-10,240);
	glVertex3f(60,20,125);
	glVertex3f(60,-10,240);
	
	glEnd();
	
	glutSwapBuffers();
	
}



void display3()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	
	TurbineBlade1();
	
	wire1();
	wire2();
	wire3();
	wire4();
	wire5();
	wire6();
	wire7();
	wire8();
	
	glLoadIdentity();
	
	title3();
	glTranslatef(-130.0,50.0,-600.0);
	
	
	glRotatef(40.0,1.0,1.0,0.0);
	glRotatef(60.0,0.0,1.0,0.0);
	glRotatef(20.0,0.0,0.0,1.0);
	glRotatef(-50.0,0.0,1.0,0.0);
	glRotatef(-30.0,1.0,0.0,1.0);
	
	glutPostRedisplay();
	
	draw_cylinder1(15.0, 80.0, 235, 185, 157); 
	draw_cylinder2(15.0, 80.0, 235, 185, 157); 
	draw_cylinder3(2.50, 280.0, 235, 185, 157); 
	draw_cylinder4(2.50, 280.0, 235, 185, 157); 
	draw_cylinder5(2.50, 55.0); 
	draw_cylinder6(2.50, 30.0); 
	draw_cylinder7(2.50, 55.0); 
	draw_cylinder8(2.50, 30.0); 
	
	draw_cylinder9(10.0,50.0); 
	draw_cylinder10(10.0,140.0); 
	
	draw_cylinder11(6.0, 10.0, 235, 185, 157); 
	draw_cylinder12(1.50, 70.0, 235, 185, 157); 
	draw_cylinder13(8.0, 30.0, 235, 185, 157); 
	
	draw_cylinder14(10.0,50.0); 
	draw_cylinder15(10.0,50.0); 
	
	draw_cone1(30.0,5.5);
	draw_cone2(25.0,4.5);
	draw_cone3(30.0,5.5);
	draw_cone4(25.0,4.5);
	
	
	//grey1
	glBegin(GL_QUADS);
	
	//front
	glColor3f(0.4,0.4,0.4);
	glVertex3f(-40.0,175.0,20.0);
	glColor3f(0.8,0.8,0.8);
	glVertex3f(-40.0,-180.0,20.0);
	glVertex3f(60.0,-180.0,20.0);
	glVertex3f(60.0,175.0,20.0);
	
	
	//back
	glColor3f(0.4,0.4,0.4);
	glVertex3f(-40.0,175.0,0.0);
	glVertex3f(-40.0,-180.0,0.0);
	glVertex3f(60.0,-180.0,0.0);
	glVertex3f(60.0,175.0,0.0);
	
	//left
	glColor3f(0.4,0.4,0.4);
	glVertex3f(-40.0,175.0,0.0);
	glVertex3f(-40.0,-180.0,0.0);
	glVertex3f(-40.0,-180.0,20.0);
	glVertex3f(-40.0,175.0,20.0);
	
	//top
	glColor3f(0.8,0.8,0.8);
	glVertex3f(-40.0,175.0,0.0);
	glVertex3f(-40.0,175.0,20.0);
	glVertex3f(60.0,175.0,20.0);
	glVertex3f(60.0,175.0,0);
	
	glEnd();
	
	//grey2
	glBegin(GL_QUADS);
	
	//top
	glColor3f(0.8,0.8,0.8);
	glVertex3f(-40.0,145.0,20.0);
	glVertex3f(-40.0,145.0,60.0);
	glVertex3f(60.0,145.0,60.0);
	glVertex3f(60.0,145.0,20.0);
	
	//front
	glColor3f(0.4,0.4,0.4);
	glVertex3f(-40.0,145.0,60.0);
	glColor3f(0.8,0.8,0.8);
	glVertex3f(-40.0,-180.0,60.0);
	glVertex3f(60.0,-180.0,60.0);
	glVertex3f(60.0,145.0,60.0);
	
	//left
	glColor3f(0.4,0.4,0.4);
	glVertex3f(-40.0,145.0,20.0);
	glColor3f(0.8,0.8,0.8);
	glVertex3f(-40.0,-180.0,20.0);
	glVertex3f(-40.0,-180.0,60.0);
	glVertex3f(-40.0,145.0,60.0);
	
	glEnd();
	
	//grey3
	glBegin(GL_QUADS);
	//front
	glColor3f(0.4,0.4,0.4);
	glVertex3f(-40.0,85.0,140.0);
	glColor3f(0.8,0.8,0.8);
	glVertex3f(-40.0,-180.0,140.0);
	glVertex3f(60.0,-180.0,140.0);
	glVertex3f(60.0,85.0,140.0);
	
	//top
	glColor3f(0.4,0.4,0.4);
	glVertex3f(-40.0,135.0,60.0);
	glColor3f(0.8,0.8,0.8);
	glVertex3f(-40.0,85.0,140.0);
	glColor3f(0.8,0.8,0.8);
	glVertex3f(60.0,85.0,140.0);
	glVertex3f(60.0,135.0,60.0);
	
	//left
	glColor3f(0.4,0.4,0.4);
	glVertex3f(-40.0,135.0,60.0);
	glVertex3f(-40.0,-180.0,60.0);
	glVertex3f(-40.0,-180.0,140.0);
	glVertex3f(-40.0,85.0,140.0);
	
	glEnd();
	
	//grey4
	glBegin(GL_QUADS);
	//front
	glColor3f(0.4,0.4,0.4);
	glVertex3f(-40.0,40.0,190.0);
	glColor3f(0.8,0.8,0.8);
	glVertex3f(-40.0,-180.0,190.0);
	glVertex3f(60.0,-180.0,190.0);
	glVertex3f(60.0,40.0,190.0);
	
	//top
	glColor3f(0.4,0.4,0.4);
	glVertex3f(-40.0,40.0,140.0);
	glColor3f(0.8,0.8,0.8);
	glVertex3f(-40.0,40.0,190.0);
	glColor3f(0.8,0.8,0.8);
	glVertex3f(60.0,40.0,190.0);
	glVertex3f(60.0,40.0,140.0);
	
	//left
	glColor3f(0.4,0.4,0.4);
	glVertex3f(-40.0,40.0,140.0);

	glVertex3f(-40.0,-180.0,140.0);
	glColor3f(0.8,0.8,0.8);
	glVertex3f(-40.0,-180.0,190.0);
	glVertex3f(-40.0,40.0,190.0);
	
	glEnd();
	
	//grey5
	glBegin(GL_QUADS);
	//front
	glColor3f(0.4,0.4,0.4);
	glVertex3f(-40.0,70.0,240.0);
	glColor3f(0.8,0.8,0.8);
	glVertex3f(-40.0,-180.0,240.0);
	glVertex3f(60.0,-180.0,240.0);
	glVertex3f(60.0,70.0,240.0);
	
	//top
	glColor3f(0.4,0.4,0.4);
	glVertex3f(-40.0,70.0,190.0);
	glColor3f(0.8,0.8,0.8);
	glVertex3f(-40.0,70.0,240.0);
	glVertex3f(60.0,70.0,240.0);
	glVertex3f(60.0,70.0,190.0);
	
	//back
	glColor3f(0.4,0.4,0.4);
	glVertex3f(-40.0,70.0,190.0);
	glVertex3f(-40.0,-180.0,190.0);
	glVertex3f(60.0,-180.0,190.0);
	glVertex3f(60.0,70.0,190.0);
	
	//right
	glColor3f(0.4,0.4,0.4);
	glVertex3f(60.0,70.0,190.0);
	glVertex3f(60.0,-180.0,190.0);
	glVertex3f(60.0,-180.0,240.0);
	glVertex3f(60.0,70.0,240.0);
	
	
	//inside
	glColor3f(0.4,0.4,0.4);
	glVertex3f(-60.0,30.0,190.0);
	glVertex3f(-60.0,30.0,240.0);
	glVertex3f(60.0,30.0,240.0);
	glVertex3f(60.0,30.0,190.0);
	
	
	
	//bottom
	glColor3f(0.4,0.4,0.4);
	glVertex3f(-40.0,-180.0,190.0);
	glColor3f(0.8,0.8,0.8);
	glVertex3f(-40.0,-180.0,240.0);
	glVertex3f(60.0,-180.0,240.0);
	glVertex3f(60.0,-180.0,190.0);
	
	glEnd();	
	
	glBegin(GL_QUADS);
	//left
	glColor3f(0.4,0.4,0.4);
	glVertex3f(-40.0,-70.0,190.0);
	glVertex3f(-40.0,-180.0,190.0);
	glVertex3f(-40.0,-180.0,240.0);
	glVertex3f(-40.0,-70.0,240.0);
	glEnd();
	
	//water1
	
	glBegin(GL_QUADS);
	
	//front
	glColor3f(0.0,0.5,1.0);
	glVertex3f(-40.0,170.0,0.0);
	glVertex3f(-40.0,-180.0,0.0);
	glVertex3f(60.0,-180.0,0.0);
	glVertex3f(60.0,170.0,0.0);
	
	//back
	glColor3f(0.0,0.5,1.0);
	glVertex3f(-40.0,170.0,-180.0);
	glVertex3f(-40.0,-180.0,-180.0);
	glVertex3f(60.0,-180.0,-180.0);
	glVertex3f(60.0,170.0,-180.0);
	
	//top
	glColor3f(0.0,0.5,1.0);
	glVertex3f(-40.0,170.0,-180.0);
	glColor3f(0.0,0.0,1.0);
	glVertex3f(-40.0,170.0,0.0);
	glVertex3f(60.0,170.0,0.0);
	glVertex3f(60.0,170.0,-180.0);

	//right
	glColor3f(0.0,0.5,1.0);
	glVertex3f(60.0,170.0,0.0);
	glVertex3f(60.0,-180.0,0.0);
	glVertex3f(60.0,-180.0,-180.0);
	glVertex3f(60.0,170.0,-180.0);
	
	//left
	glColor3f(0.0,0.5,1.0);
	glVertex3f(-40.0,170.0,-180.0);
	glVertex3f(-40.0,-180.0,-180.0);
	glVertex3f(-40.0,-180.0,0.0);
	glVertex3f(-40.0,170.0,0.0);
	
	//bottom
	glColor3f(0.0,0.5,1.0);
	glVertex3f(-40.0,-180.0,-180.0);
	glVertex3f(-40.0,-180.0,0.0);
	glVertex3f(60.0,-180.0,0.0);
	glVertex3f(60.0,-180.0,-180.0);
	
	glEnd();
	
	//vertical second cube
	
	glBegin(GL_QUADS);
	
	//front
	glColor3f(0.0,0.5,0.0);
	glVertex3f(60.0,180.0,10.0);
	glColor3f(0.0,1.0,0.0);
	glVertex3f(60.0,-60.0,10.0);
	glVertex3f(450.0,-60.0,10.0);
	glColor3f(0.0,1.0,0.0);
	glVertex3f(450.0,180.0,10.0);
	
	//back
	glColor3f(0.0,0.5,0.0);
	glVertex3f(60.0,180.0,-30.0);
	glVertex3f(60.0,-60.0,-30.0);
	glVertex3f(450.0,-60.0,-30.0);
	glVertex3f(450.0,180.0,-30.0);
	
	//right
	glColor3f(0.0,0.0,0.0);
	glVertex3f(450.0,180.0,10.0);
	glVertex3f(450.0,-60.0,10.0);
	glVertex3f(450.0,-60.0,-30.0);
	glVertex3f(450.0,180.0,-30.0);
	
	//left
	glColor3f(0.0,0.0,0.0);
	glVertex3f(60.0,180.0,-30.0);
	glVertex3f(60.0,-60.0,-30.0);
	glVertex3f(60.0,-60.0,10.0);
	glVertex3f(60.0,180.0,10.0);
	
	//top
	glColor3f(0.0,0.5,0.0);
	glVertex3f(60.0,180.0,-30.0);
	glVertex3f(60.0,180.0,10.0);
	glVertex3f(450.0,180.0,10.0);
	glVertex3f(450.0,180.0,-30.0);
	
	//bottom
	glColor3f(0.0,0.0,0.0);
	glVertex3f(60.0,-60.0,-30.0);
	glVertex3f(60.0,-60.0,10.0);
	glVertex3f(450.0,-60.0,10.0);
	glVertex3f(450.0,-60.0,-30.0);
	
	glEnd();
	
	//horizontal second cube
	
	glBegin(GL_QUADS);
	
	//bottom
	glColor3f(0.0,0.5,0.0);
	glVertex3f(60.0,-60.0,10.0);
	glVertex3f(60.0,-60.0,240.0);
	glVertex3f(450.0,-60.0,240.0);
	glVertex3f(450.0,-60.0,10.0);
	
	//top
	glColor3f(0.0,0.5,0.0);
	glVertex3f(60.0,-10.0,10.0);
	glVertex3f(60.0,-10.0,240.0);
	glVertex3f(450.0,-10.0,240.0);
	glVertex3f(450.0,-10.0,10.0);
	
	//left
	glColor3f(0.0,0.0,0.0);
	glVertex3f(60.0,-60.0,10.0);
	glVertex3f(60.0,-60.0,240.0);
	glVertex3f(60.0,-10.0,240.0);
	glVertex3f(60.0,-10.0,10.0);
	
	//front
	glColor3f(0.0,0.0,0.0);
	glVertex3f(60.0,-10.0,240.0);
	glVertex3f(60.0,-60.0,240.0);
	glVertex3f(450.0,-60.0,240.0);
	glVertex3f(450.0,-10.0,240.0);
	
	glEnd();
	
	//water2
	
	glBegin(GL_QUADS);
	
	//front
	glColor3f(0.0,0.0,1.0);
	glVertex3f(-40.0,-20.0,350.0);
	glColor3f(0.0,0.5,1.0);
	glVertex3f(-40.0,-180.0,350.0);
	glVertex3f(60.0,-180.0,350.0);
	glVertex3f(60.0,-20.0,350.0);
	
	//back
	glColor3f(0.0,0.0,1.0);
	glVertex3f(-40.0,-20.0,240.0);
	glColor3f(0.0,0.5,1.0);
	glVertex3f(-40.0,-180.0,240.0);
	glVertex3f(60.0,-180.0,240.0);
	glVertex3f(60.0,-20.0,240.0);
	
	//top
	glColor3f(0.0,0.0,1.0);
	glVertex3f(-40.0,-20.0,240.0);
	glColor3f(0.0,0.5,1.0);
	glVertex3f(-40.0,-20.0,350.0);
	glVertex3f(60.0,-20.0,350.0);
	glVertex3f(60.0,-20.0,240.0);

	//left
	glColor3f(0.0,0.0,1.0);
	glVertex3f(-40.0,-20.0,240.0);
	glColor3f(0.0,0.5,1.0);
	glVertex3f(-40.0,-180.0,240.0);
	glVertex3f(-40.0,-180.0,350.0);
	glVertex3f(-40.0,-20.0,350.0);
	

	
	glEnd();
	
	//slope2
	
	glBegin(GL_QUAD_STRIP);
	
	glColor3f(0.0,0.5,0.0);
	glVertex3f(450.0,180.0,10.0);
	glVertex3f(450.0,120.0,50.0);
	glVertex3f(60.0,180.0,10.0);
	glVertex3f(60.0,120.0,50.0);

	glVertex3f(450.0,120.0,50.0);
	glVertex3f(450.0,70.0,65.0);
	glVertex3f(60.0,120.0,50.0);
	glVertex3f(60.0,70.0,65.0);
	
	glVertex3f(450.0,70.0,65.0);
	glVertex3f(450.0,30.0,75.0);
	glVertex3f(60.0,70.0,65.0);
	glVertex3f(60.0,30.0,75.0);	
	
	
	glVertex3f(450.0,30.0,75.0);
	glVertex3f(450.0,20,125);
	glVertex3f(60.0,30.0,75.0);	
	glVertex3f(60,20,125);
	
	glVertex3f(450.0,20,125);
	glVertex3f(450,-10,240);
	glVertex3f(60,20,125);
	glVertex3f(60,-10,240);
	
	glEnd();
	
	glutSwapBuffers();
	
}


void display4()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	waterFlow1();


	TurbineBlade1();
	
	wire1();
	wire2();
	wire3();
	wire4();
	wire5();
	wire6();
	wire7();
	wire8();
	
	glLoadIdentity();
	
	title4();
	glTranslatef(-130.0,50.0,-600.0);
	
	
	glRotatef(40.0,1.0,1.0,0.0);
	glRotatef(60.0,0.0,1.0,0.0);
	glRotatef(20.0,0.0,0.0,1.0);
	glRotatef(-50.0,0.0,1.0,0.0);
	glRotatef(-30.0,1.0,0.0,1.0);
	
	glutPostRedisplay();
	
	draw_cylinder1(15.0, 80.0, 235, 185, 157); 
	draw_cylinder2(15.0, 80.0, 235, 185, 157); 
	draw_cylinder3(2.50, 280.0, 235, 185, 157); 
	draw_cylinder4(2.50, 280.0, 235, 185, 157); 
	draw_cylinder5(2.50, 55.0); 
	draw_cylinder6(2.50, 30.0); 
	draw_cylinder7(2.50, 55.0); 
	draw_cylinder8(2.50, 30.0); 
	
	draw_cylinder9(10.0,50.0); 
	draw_cylinder10(10.0,140.0); 
	
	draw_cylinder11(6.0, 10.0, 235, 185, 157); 
	draw_cylinder12(1.50, 70.0, 235, 185, 157); 
	draw_cylinder13(8.0, 30.0, 235, 185, 157); 
	
	draw_cylinder14(10.0,50.0); 
	draw_cylinder15(10.0,50.0); 
	
	draw_cone1(30.0,5.5);
	draw_cone2(25.0,4.5);
	draw_cone3(30.0,5.5);
	draw_cone4(25.0,4.5);
	
	
	//grey1
	glBegin(GL_QUADS);
	
	//front
	glColor3f(0.4,0.4,0.4);
	glVertex3f(-40.0,175.0,20.0);
	glColor3f(0.8,0.8,0.8);
	glVertex3f(-40.0,-180.0,20.0);
	glVertex3f(60.0,-180.0,20.0);
	glVertex3f(60.0,175.0,20.0);
	
	
	//back
	glColor3f(0.4,0.4,0.4);
	glVertex3f(-40.0,175.0,0.0);
	glVertex3f(-40.0,-180.0,0.0);
	glVertex3f(60.0,-180.0,0.0);
	glVertex3f(60.0,175.0,0.0);
	
	//left
	glColor3f(0.4,0.4,0.4);
	glVertex3f(-40.0,175.0,0.0);
	glVertex3f(-40.0,-180.0,0.0);
	glVertex3f(-40.0,-180.0,20.0);
	glVertex3f(-40.0,175.0,20.0);
	
	//top
	glColor3f(0.8,0.8,0.8);
	glVertex3f(-40.0,175.0,0.0);
	glVertex3f(-40.0,175.0,20.0);
	glVertex3f(60.0,175.0,20.0);
	glVertex3f(60.0,175.0,0);
	
	glEnd();
	
	//grey2
	glBegin(GL_QUADS);
	
	//top
	glColor3f(0.8,0.8,0.8);
	glVertex3f(-40.0,145.0,20.0);
	glVertex3f(-40.0,145.0,60.0);
	glVertex3f(60.0,145.0,60.0);
	glVertex3f(60.0,145.0,20.0);
	
	//front
	glColor3f(0.4,0.4,0.4);
	glVertex3f(-40.0,145.0,60.0);
	glColor3f(0.8,0.8,0.8);
	glVertex3f(-40.0,-180.0,60.0);
	glVertex3f(60.0,-180.0,60.0);
	glVertex3f(60.0,145.0,60.0);
	
	//left
	glColor3f(0.4,0.4,0.4);
	glVertex3f(-40.0,145.0,20.0);
	glColor3f(0.8,0.8,0.8);
	glVertex3f(-40.0,-180.0,20.0);
	glVertex3f(-40.0,-180.0,60.0);
	glVertex3f(-40.0,145.0,60.0);
	
	glEnd();
	
	//grey3
	glBegin(GL_QUADS);
	//front
	glColor3f(0.4,0.4,0.4);
	glVertex3f(-40.0,85.0,140.0);
	glColor3f(0.8,0.8,0.8);
	glVertex3f(-40.0,-180.0,140.0);
	glVertex3f(60.0,-180.0,140.0);
	glVertex3f(60.0,85.0,140.0);
	
	//top
	glColor3f(0.4,0.4,0.4);
	glVertex3f(-40.0,135.0,60.0);
	glColor3f(0.8,0.8,0.8);
	glVertex3f(-40.0,85.0,140.0);
	glColor3f(0.8,0.8,0.8);
	glVertex3f(60.0,85.0,140.0);
	glVertex3f(60.0,135.0,60.0);
	
	//left
	glColor3f(0.4,0.4,0.4);
	glVertex3f(-40.0,135.0,60.0);
	glVertex3f(-40.0,-180.0,60.0);
	glVertex3f(-40.0,-180.0,140.0);
	glVertex3f(-40.0,85.0,140.0);
	
	glEnd();
	
	//grey4
	glBegin(GL_QUADS);
	//front
	glColor3f(0.4,0.4,0.4);
	glVertex3f(-40.0,40.0,190.0);
	glColor3f(0.8,0.8,0.8);
	glVertex3f(-40.0,-180.0,190.0);
	glVertex3f(60.0,-180.0,190.0);
	glVertex3f(60.0,40.0,190.0);
	
	//top
	glColor3f(0.4,0.4,0.4);
	glVertex3f(-40.0,40.0,140.0);
	glColor3f(0.8,0.8,0.8);
	glVertex3f(-40.0,40.0,190.0);
	glColor3f(0.8,0.8,0.8);
	glVertex3f(60.0,40.0,190.0);
	glVertex3f(60.0,40.0,140.0);
	
	//left
	glColor3f(0.4,0.4,0.4);
	glVertex3f(-40.0,40.0,140.0);

	glVertex3f(-40.0,-180.0,140.0);
	glColor3f(0.8,0.8,0.8);
	glVertex3f(-40.0,-180.0,190.0);
	glVertex3f(-40.0,40.0,190.0);
	
	glEnd();
	
	//grey5
	glBegin(GL_QUADS);
	//front
	glColor3f(0.4,0.4,0.4);
	glVertex3f(-40.0,70.0,240.0);
	glColor3f(0.8,0.8,0.8);
	glVertex3f(-40.0,-180.0,240.0);
	glVertex3f(60.0,-180.0,240.0);
	glVertex3f(60.0,70.0,240.0);
	
	//top
	glColor3f(0.4,0.4,0.4);
	glVertex3f(-40.0,70.0,190.0);
	glColor3f(0.8,0.8,0.8);
	glVertex3f(-40.0,70.0,240.0);
	glVertex3f(60.0,70.0,240.0);
	glVertex3f(60.0,70.0,190.0);
	
	//back
	glColor3f(0.4,0.4,0.4);
	glVertex3f(-40.0,70.0,190.0);
	glVertex3f(-40.0,-180.0,190.0);
	glVertex3f(60.0,-180.0,190.0);
	glVertex3f(60.0,70.0,190.0);
	
	//right
	glColor3f(0.4,0.4,0.4);
	glVertex3f(60.0,70.0,190.0);
	glVertex3f(60.0,-180.0,190.0);
	glVertex3f(60.0,-180.0,240.0);
	glVertex3f(60.0,70.0,240.0);
	
	
	//inside
	glColor3f(0.4,0.4,0.4);
	glVertex3f(-60.0,30.0,190.0);
	glVertex3f(-60.0,30.0,240.0);
	glVertex3f(60.0,30.0,240.0);
	glVertex3f(60.0,30.0,190.0);
	
	
	
	//bottom
	glColor3f(0.4,0.4,0.4);
	glVertex3f(-40.0,-180.0,190.0);
	glColor3f(0.8,0.8,0.8);
	glVertex3f(-40.0,-180.0,240.0);
	glVertex3f(60.0,-180.0,240.0);
	glVertex3f(60.0,-180.0,190.0);
	
	glEnd();	
	
	glBegin(GL_QUADS);
	//left
	glColor3f(0.4,0.4,0.4);
	glVertex3f(-40.0,-70.0,190.0);
	glVertex3f(-40.0,-180.0,190.0);
	glVertex3f(-40.0,-180.0,240.0);
	glVertex3f(-40.0,-70.0,240.0);
	glEnd();
	
	//water1
	
	glBegin(GL_QUADS);
	
	//front
	glColor3f(0.0,0.5,1.0);
	glVertex3f(-40.0,170.0,0.0);
	glVertex3f(-40.0,-180.0,0.0);
	glVertex3f(60.0,-180.0,0.0);
	glVertex3f(60.0,170.0,0.0);
	
	//back
	glColor3f(0.0,0.5,1.0);
	glVertex3f(-40.0,170.0,-180.0);
	glVertex3f(-40.0,-180.0,-180.0);
	glVertex3f(60.0,-180.0,-180.0);
	glVertex3f(60.0,170.0,-180.0);
	
	//top
	glColor3f(0.0,0.5,1.0);
	glVertex3f(-40.0,170.0,-180.0);
	glColor3f(0.0,0.0,1.0);
	glVertex3f(-40.0,170.0,0.0);
	glVertex3f(60.0,170.0,0.0);
	glVertex3f(60.0,170.0,-180.0);

	//right
	glColor3f(0.0,0.5,1.0);
	glVertex3f(60.0,170.0,0.0);
	glVertex3f(60.0,-180.0,0.0);
	glVertex3f(60.0,-180.0,-180.0);
	glVertex3f(60.0,170.0,-180.0);
	
	//left
	glColor3f(0.0,0.5,1.0);
	glVertex3f(-40.0,170.0,-180.0);
	glVertex3f(-40.0,-180.0,-180.0);
	glVertex3f(-40.0,-180.0,0.0);
	glVertex3f(-40.0,170.0,0.0);
	
	//bottom
	glColor3f(0.0,0.5,1.0);
	glVertex3f(-40.0,-180.0,-180.0);
	glVertex3f(-40.0,-180.0,0.0);
	glVertex3f(60.0,-180.0,0.0);
	glVertex3f(60.0,-180.0,-180.0);
	
	glEnd();
	
	//vertical second cube
	
	glBegin(GL_QUADS);
	
	//front
	glColor3f(0.0,0.5,0.0);
	glVertex3f(60.0,180.0,10.0);
	glColor3f(0.0,1.0,0.0);
	glVertex3f(60.0,-60.0,10.0);
	glVertex3f(450.0,-60.0,10.0);
	glColor3f(0.0,1.0,0.0);
	glVertex3f(450.0,180.0,10.0);
	
	//back
	glColor3f(0.0,0.5,0.0);
	glVertex3f(60.0,180.0,-30.0);
	glVertex3f(60.0,-60.0,-30.0);
	glVertex3f(450.0,-60.0,-30.0);
	glVertex3f(450.0,180.0,-30.0);
	
	//right
	glColor3f(0.0,0.0,0.0);
	glVertex3f(450.0,180.0,10.0);
	glVertex3f(450.0,-60.0,10.0);
	glVertex3f(450.0,-60.0,-30.0);
	glVertex3f(450.0,180.0,-30.0);
	
	//left
	glColor3f(0.0,0.0,0.0);
	glVertex3f(60.0,180.0,-30.0);
	glVertex3f(60.0,-60.0,-30.0);
	glVertex3f(60.0,-60.0,10.0);
	glVertex3f(60.0,180.0,10.0);
	
	//top
	glColor3f(0.0,0.5,0.0);
	glVertex3f(60.0,180.0,-30.0);
	glVertex3f(60.0,180.0,10.0);
	glVertex3f(450.0,180.0,10.0);
	glVertex3f(450.0,180.0,-30.0);
	
	//bottom
	glColor3f(0.0,0.0,0.0);
	glVertex3f(60.0,-60.0,-30.0);
	glVertex3f(60.0,-60.0,10.0);
	glVertex3f(450.0,-60.0,10.0);
	glVertex3f(450.0,-60.0,-30.0);
	
	glEnd();
	
	//horizontal second cube
	
	glBegin(GL_QUADS);
	
	//bottom
	glColor3f(0.0,0.5,0.0);
	glVertex3f(60.0,-60.0,10.0);
	glVertex3f(60.0,-60.0,240.0);
	glVertex3f(450.0,-60.0,240.0);
	glVertex3f(450.0,-60.0,10.0);
	
	//top
	glColor3f(0.0,0.5,0.0);
	glVertex3f(60.0,-10.0,10.0);
	glVertex3f(60.0,-10.0,240.0);
	glVertex3f(450.0,-10.0,240.0);
	glVertex3f(450.0,-10.0,10.0);
	
	//left
	glColor3f(0.0,0.0,0.0);
	glVertex3f(60.0,-60.0,10.0);
	glVertex3f(60.0,-60.0,240.0);
	glVertex3f(60.0,-10.0,240.0);
	glVertex3f(60.0,-10.0,10.0);
	
	//front
	glColor3f(0.0,0.0,0.0);
	glVertex3f(60.0,-10.0,240.0);
	glVertex3f(60.0,-60.0,240.0);
	glVertex3f(450.0,-60.0,240.0);
	glVertex3f(450.0,-10.0,240.0);
	
	glEnd();
	
	//water2
	
	glBegin(GL_QUADS);
	
	//front
	glColor3f(0.0,0.0,1.0);
	glVertex3f(-40.0,-20.0,350.0);
	glColor3f(0.0,0.5,1.0);
	glVertex3f(-40.0,-180.0,350.0);
	glVertex3f(60.0,-180.0,350.0);
	glVertex3f(60.0,-20.0,350.0);
	
	//back
	glColor3f(0.0,0.0,1.0);
	glVertex3f(-40.0,-20.0,240.0);
	glColor3f(0.0,0.5,1.0);
	glVertex3f(-40.0,-180.0,240.0);
	glVertex3f(60.0,-180.0,240.0);
	glVertex3f(60.0,-20.0,240.0);
	
	//top
	glColor3f(0.0,0.0,1.0);
	glVertex3f(-40.0,-20.0,240.0);
	glColor3f(0.0,0.5,1.0);
	glVertex3f(-40.0,-20.0,350.0);
	glVertex3f(60.0,-20.0,350.0);
	glVertex3f(60.0,-20.0,240.0);

	//left
	glColor3f(0.0,0.0,1.0);
	glVertex3f(-40.0,-20.0,240.0);
	glColor3f(0.0,0.5,1.0);
	glVertex3f(-40.0,-180.0,240.0);
	glVertex3f(-40.0,-180.0,350.0);
	glVertex3f(-40.0,-20.0,350.0);
	

	
	glEnd();
	
	//slope2
	
	glBegin(GL_QUAD_STRIP);
	
	glColor3f(0.0,0.5,0.0);
	glVertex3f(450.0,180.0,10.0);
	glVertex3f(450.0,120.0,50.0);
	glVertex3f(60.0,180.0,10.0);
	glVertex3f(60.0,120.0,50.0);

	glVertex3f(450.0,120.0,50.0);
	glVertex3f(450.0,70.0,65.0);
	glVertex3f(60.0,120.0,50.0);
	glVertex3f(60.0,70.0,65.0);
	
	glVertex3f(450.0,70.0,65.0);
	glVertex3f(450.0,30.0,75.0);
	glVertex3f(60.0,70.0,65.0);
	glVertex3f(60.0,30.0,75.0);	
	
	
	glVertex3f(450.0,30.0,75.0);
	glVertex3f(450.0,20,125);
	glVertex3f(60.0,30.0,75.0);	
	glVertex3f(60,20,125);
	
	glVertex3f(450.0,20,125);
	glVertex3f(450,-10,240);
	glVertex3f(60,20,125);
	glVertex3f(60,-10,240);
	
	glEnd();
	
	glutSwapBuffers();
	
}


void display5()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	
	
	waterFlow1();

	waterFlow2();
	
	waterFlow3();
	
	waterFlow4();
	
	timer9(0);
		
	timer(0);
	timer2(0);
	timer3(0);
	timer4(0);
	timer5(0);
	timer6(0);
	timer7(0);
	timer8(0);
	
	
	wire1();
	wire2();
	wire3();
	wire4();
	wire5();
	wire6();
	wire7();
	wire8();
	glLoadIdentity();
	title5();
	glTranslatef(-130.0,50.0,-600.0);
	
	glRotatef(40.0,1.0,1.0,0.0);
	glRotatef(60.0,0.0,1.0,0.0);
	glRotatef(20.0,0.0,0.0,1.0);
	glRotatef(-50.0,0.0,1.0,0.0);
	glRotatef(-30.0,1.0,0.0,1.0);
	
	
	//timer1(0);
	glutPostRedisplay();
	
	draw_cylinder1(15.0, 80.0, 235, 185, 157); 
	draw_cylinder2(15.0, 80.0, 235, 185, 157); 
	draw_cylinder3(2.50, 280.0, 235, 185, 157); 
	draw_cylinder4(2.50, 280.0, 235, 185, 157); 
	draw_cylinder5(2.50, 55.0); 
	draw_cylinder6(2.50, 30.0); 
	draw_cylinder7(2.50, 55.0); 
	draw_cylinder8(2.50, 30.0); 
	
	draw_cylinder9(10.0,50.0); 
	draw_cylinder101(10.0,140.0); 
	
	draw_cylinder11(6.0, 10.0, 235, 185, 157); 
	draw_cylinder12(1.50, 70.0, 235, 185, 157); 
	draw_cylinder13(8.0, 30.0, 235, 185, 157); 
	
	draw_cylinder141(10.0,50.0); 
	draw_cylinder151(10.0,50.0); 
	
	draw_cone1(30.0,5.5);
	draw_cone2(25.0,4.5);
	draw_cone3(30.0,5.5);
	draw_cone4(25.0,4.5);
	
	
	
	//grey1
	glBegin(GL_QUADS);
	
	//front
	glColor3f(0.4,0.4,0.4);
	glVertex3f(-40.0,175.0,20.0);
	glColor3f(0.8,0.8,0.8);
	glVertex3f(-40.0,-180.0,20.0);
	glVertex3f(60.0,-180.0,20.0);
	glVertex3f(60.0,175.0,20.0);
	
	
	//back
	glColor3f(0.4,0.4,0.4);
	glVertex3f(-40.0,175.0,0.0);
	glVertex3f(-40.0,-180.0,0.0);
	glVertex3f(60.0,-180.0,0.0);
	glVertex3f(60.0,175.0,0.0);
	
	//left
	glColor3f(0.4,0.4,0.4);
	glVertex3f(-40.0,175.0,0.0);
	glVertex3f(-40.0,-180.0,0.0);
	glVertex3f(-40.0,-180.0,20.0);
	glVertex3f(-40.0,175.0,20.0);
	
	//top
	glColor3f(0.8,0.8,0.8);
	glVertex3f(-40.0,175.0,0.0);
	glVertex3f(-40.0,175.0,20.0);
	glVertex3f(60.0,175.0,20.0);
	glVertex3f(60.0,175.0,0);
	
	glEnd();
	
	//grey2
	glBegin(GL_QUADS);
	
	//top
	glColor3f(0.8,0.8,0.8);
	glVertex3f(-40.0,145.0,20.0);
	glVertex3f(-40.0,145.0,60.0);
	glVertex3f(60.0,145.0,60.0);
	glVertex3f(60.0,145.0,20.0);
	
	//front
	glColor3f(0.4,0.4,0.4);
	glVertex3f(-40.0,145.0,60.0);
	glColor3f(0.8,0.8,0.8);
	glVertex3f(-40.0,-180.0,60.0);
	glVertex3f(60.0,-180.0,60.0);
	glVertex3f(60.0,145.0,60.0);
	
	//left
	glColor3f(0.4,0.4,0.4);
	glVertex3f(-40.0,145.0,20.0);
	glColor3f(0.8,0.8,0.8);
	glVertex3f(-40.0,-180.0,20.0);
	glVertex3f(-40.0,-180.0,60.0);
	glVertex3f(-40.0,145.0,60.0);
	
	glEnd();
	
	//grey3
	glBegin(GL_QUADS);
	//front
	glColor3f(0.4,0.4,0.4);
	glVertex3f(-40.0,85.0,140.0);
	glColor3f(0.8,0.8,0.8);
	glVertex3f(-40.0,-180.0,140.0);
	glVertex3f(60.0,-180.0,140.0);
	glVertex3f(60.0,85.0,140.0);
	
	//top
	glColor3f(0.4,0.4,0.4);
	glVertex3f(-40.0,135.0,60.0);
	glColor3f(0.8,0.8,0.8);
	glVertex3f(-40.0,85.0,140.0);
	glColor3f(0.8,0.8,0.8);
	glVertex3f(60.0,85.0,140.0);
	glVertex3f(60.0,135.0,60.0);
	
	//left
	glColor3f(0.4,0.4,0.4);
	glVertex3f(-40.0,135.0,60.0);
	glVertex3f(-40.0,-180.0,60.0);
	glVertex3f(-40.0,-180.0,140.0);
	glVertex3f(-40.0,85.0,140.0);
	
	glEnd();
	
	//grey4
	glBegin(GL_QUADS);
	//front
	glColor3f(0.4,0.4,0.4);
	glVertex3f(-40.0,40.0,190.0);
	glColor3f(0.8,0.8,0.8);
	glVertex3f(-40.0,-180.0,190.0);
	glVertex3f(60.0,-180.0,190.0);
	glVertex3f(60.0,40.0,190.0);
	
	//top
	glColor3f(0.4,0.4,0.4);
	glVertex3f(-40.0,40.0,140.0);
	glColor3f(0.8,0.8,0.8);
	glVertex3f(-40.0,40.0,190.0);
	glColor3f(0.8,0.8,0.8);
	glVertex3f(60.0,40.0,190.0);
	glVertex3f(60.0,40.0,140.0);
	
	//left
	glColor3f(0.4,0.4,0.4);
	glVertex3f(-40.0,40.0,140.0);

	glVertex3f(-40.0,-180.0,140.0);
	glColor3f(0.8,0.8,0.8);
	glVertex3f(-40.0,-180.0,190.0);
	glVertex3f(-40.0,40.0,190.0);
	
	glEnd();
	
	//grey5
	glBegin(GL_QUADS);
	//front
	glColor3f(0.4,0.4,0.4);
	glVertex3f(-40.0,70.0,240.0);
	glColor3f(0.8,0.8,0.8);
	glVertex3f(-40.0,-180.0,240.0);
	glVertex3f(60.0,-180.0,240.0);
	glVertex3f(60.0,70.0,240.0);
	
	//top
	glColor3f(0.4,0.4,0.4);
	glVertex3f(-40.0,70.0,190.0);
	glColor3f(0.8,0.8,0.8);
	glVertex3f(-40.0,70.0,240.0);
	glVertex3f(60.0,70.0,240.0);
	glVertex3f(60.0,70.0,190.0);
	
	//back
	glColor3f(0.4,0.4,0.4);
	glVertex3f(-40.0,70.0,190.0);
	glVertex3f(-40.0,-180.0,190.0);
	glVertex3f(60.0,-180.0,190.0);
	glVertex3f(60.0,70.0,190.0);
	
	//right
	glColor3f(0.4,0.4,0.4);
	glVertex3f(60.0,70.0,190.0);
	glVertex3f(60.0,-180.0,190.0);
	glVertex3f(60.0,-180.0,240.0);
	glVertex3f(60.0,70.0,240.0);
	
	
	//inside
	glColor3f(0.4,0.4,0.4);
	glVertex3f(-60.0,30.0,190.0);
	glVertex3f(-60.0,30.0,240.0);
	glVertex3f(60.0,30.0,240.0);
	glVertex3f(60.0,30.0,190.0);
	
	//bottom
	glColor3f(0.4,0.4,0.4);
	glVertex3f(-40.0,-180.0,190.0);
	glColor3f(0.8,0.8,0.8);
	glVertex3f(-40.0,-180.0,240.0);
	glVertex3f(60.0,-180.0,240.0);
	glVertex3f(60.0,-180.0,190.0);
	
	glEnd();
	
	glBegin(GL_QUADS);
	//left
	glColor3f(0.4,0.4,0.4);
	glVertex3f(-40.0,-70.0,190.0);
	glVertex3f(-40.0,-180.0,190.0);
	glVertex3f(-40.0,-180.0,240.0);
	glVertex3f(-40.0,-70.0,240.0);
	glEnd();	
	
	
	//water1
	
	glBegin(GL_QUADS);
	
	//front
	glColor3f(0.0,0.5,1.0);
	glVertex3f(-40.0,170.0,0.0);
	glVertex3f(-40.0,-180.0,0.0);
	glVertex3f(60.0,-180.0,0.0);
	glVertex3f(60.0,170.0,0.0);
	
	//back
	glColor3f(0.0,0.5,1.0);
	glVertex3f(-40.0,170.0,-180.0);
	glVertex3f(-40.0,-180.0,-180.0);
	glVertex3f(60.0,-180.0,-180.0);
	glVertex3f(60.0,170.0,-180.0);
	
	//top
	glColor3f(0.0,0.5,1.0);
	glVertex3f(-40.0,170.0,-180.0);
	glColor3f(0.0,0.0,1.0);
	glVertex3f(-40.0,170.0,0.0);
	glVertex3f(60.0,170.0,0.0);
	glVertex3f(60.0,170.0,-180.0);

	//right
	glColor3f(0.0,0.5,1.0);
	glVertex3f(60.0,170.0,0.0);
	glVertex3f(60.0,-180.0,0.0);
	glVertex3f(60.0,-180.0,-180.0);
	glVertex3f(60.0,170.0,-180.0);
	
	//left
	glColor3f(0.0,0.5,1.0);
	glVertex3f(-40.0,170.0,-180.0);
	glVertex3f(-40.0,-180.0,-180.0);
	glVertex3f(-40.0,-180.0,0.0);
	glVertex3f(-40.0,170.0,0.0);
	
	//bottom
	glColor3f(0.0,0.5,1.0);
	glVertex3f(-40.0,-180.0,-180.0);
	glVertex3f(-40.0,-180.0,0.0);
	glVertex3f(60.0,-180.0,0.0);
	glVertex3f(60.0,-180.0,-180.0);
	
	glEnd();
	
	//vertical second cube
	
	glBegin(GL_QUADS);
	
	//front
	glColor3f(0.0,0.5,0.0);
	glVertex3f(60.0,180.0,10.0);
	glColor3f(0.0,1.0,0.0);
	glVertex3f(60.0,-60.0,10.0);
	glVertex3f(450.0,-60.0,10.0);
	glColor3f(0.0,1.0,0.0);
	glVertex3f(450.0,180.0,10.0);
	
	//back
	glColor3f(0.0,0.5,0.0);
	glVertex3f(60.0,180.0,-30.0);
	glVertex3f(60.0,-60.0,-30.0);
	glVertex3f(450.0,-60.0,-30.0);
	glVertex3f(450.0,180.0,-30.0);
	
	//right
	glColor3f(0.0,0.0,0.0);
	glVertex3f(450.0,180.0,10.0);
	glVertex3f(450.0,-60.0,10.0);
	glVertex3f(450.0,-60.0,-30.0);
	glVertex3f(450.0,180.0,-30.0);
	
	//left
	glColor3f(0.0,0.0,0.0);
	glVertex3f(60.0,180.0,-30.0);
	glVertex3f(60.0,-60.0,-30.0);
	glVertex3f(60.0,-60.0,10.0);
	glVertex3f(60.0,180.0,10.0);
	
	//top
	glColor3f(0.0,0.5,0.0);
	glVertex3f(60.0,180.0,-30.0);
	glVertex3f(60.0,180.0,10.0);
	glVertex3f(450.0,180.0,10.0);
	glVertex3f(450.0,180.0,-30.0);
	
	//bottom
	glColor3f(0.0,0.0,0.0);
	glVertex3f(60.0,-60.0,-30.0);
	glVertex3f(60.0,-60.0,10.0);
	glVertex3f(450.0,-60.0,10.0);
	glVertex3f(450.0,-60.0,-30.0);
	
	glEnd();
	
	//horizontal second cube
	
	glBegin(GL_QUADS);
	
	//bottom
	glColor3f(0.0,0.5,0.0);
	glVertex3f(60.0,-60.0,10.0);
	glVertex3f(60.0,-60.0,240.0);
	glVertex3f(450.0,-60.0,240.0);
	glVertex3f(450.0,-60.0,10.0);
	
	//top
	glColor3f(0.0,0.5,0.0);
	glVertex3f(60.0,-10.0,10.0);
	glVertex3f(60.0,-10.0,240.0);
	glVertex3f(450.0,-10.0,240.0);
	glVertex3f(450.0,-10.0,10.0);
	
	//left
	glColor3f(0.0,0.0,0.0);
	glVertex3f(60.0,-60.0,10.0);
	glVertex3f(60.0,-60.0,240.0);
	glVertex3f(60.0,-10.0,240.0);
	glVertex3f(60.0,-10.0,10.0);
	
	//front
	glColor3f(0.0,0.0,0.0);
	glVertex3f(60.0,-10.0,240.0);
	glVertex3f(60.0,-60.0,240.0);
	glVertex3f(450.0,-60.0,240.0);
	glVertex3f(450.0,-10.0,240.0);
	
	glEnd();
	
	//water2
	
	glBegin(GL_QUADS);
	
	//front
	glColor3f(0.0,0.0,1.0);
	glVertex3f(-40.0,-20.0,350.0);
	glColor3f(0.0,0.5,1.0);
	glVertex3f(-40.0,-180.0,350.0);
	glVertex3f(60.0,-180.0,350.0);
	glVertex3f(60.0,-20.0,350.0);
	
	//back
	glColor3f(0.0,0.0,1.0);
	glVertex3f(-40.0,-20.0,240.0);
	glColor3f(0.0,0.5,1.0);
	glVertex3f(-40.0,-180.0,240.0);
	glVertex3f(60.0,-180.0,240.0);
	glVertex3f(60.0,-20.0,240.0);
	
	//top
	glColor3f(0.0,0.0,1.0);
	glVertex3f(-40.0,-20.0,240.0);
	glColor3f(0.0,0.5,1.0);
	glVertex3f(-40.0,-20.0,350.0);
	glVertex3f(60.0,-20.0,350.0);
	glVertex3f(60.0,-20.0,240.0);

	//left
	glColor3f(0.0,0.0,1.0);
	glVertex3f(-40.0,-20.0,240.0);
	glColor3f(0.0,0.5,1.0);
	glVertex3f(-40.0,-180.0,240.0);
	glVertex3f(-40.0,-180.0,350.0);
	glVertex3f(-40.0,-20.0,350.0);
	

	
	glEnd();
	
	//slope2
	
	glBegin(GL_QUAD_STRIP);
	
	glColor3f(0.0,0.5,0.0);
	glVertex3f(450.0,180.0,10.0);
	glVertex3f(450.0,120.0,50.0);
	glVertex3f(60.0,180.0,10.0);
	glVertex3f(60.0,120.0,50.0);

	glVertex3f(450.0,120.0,50.0);
	glVertex3f(450.0,70.0,65.0);
	glVertex3f(60.0,120.0,50.0);
	glVertex3f(60.0,70.0,65.0);
	
	glVertex3f(450.0,70.0,65.0);
	glVertex3f(450.0,30.0,75.0);
	glVertex3f(60.0,70.0,65.0);
	glVertex3f(60.0,30.0,75.0);	
	
	
	glVertex3f(450.0,30.0,75.0);
	glVertex3f(450.0,20,125);
	glVertex3f(60.0,30.0,75.0);	
	glVertex3f(60,20,125);
	
	glVertex3f(450.0,20,125);
	glVertex3f(450,-10,240);
	glVertex3f(60,20,125);
	glVertex3f(60,-10,240);
	
	
	glEnd();
	
	
	
	glutSwapBuffers();
	
}


void display6()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	
    title6();
    
    glutSwapBuffers();
}


void display()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	if(slide==1)
	{
		display1();
		glutPostRedisplay();
	}
	if(slide==2)
	{
		display2();
		
		glutPostRedisplay();
	}
	if(slide==3)
	{
		display3();
		glutPostRedisplay();
	}
	if(slide==4)
	{
		display4();
		glutPostRedisplay();
	}
	if(slide==5)
	{
		display5();
		glutPostRedisplay();
	}
	if(slide==6)
	{
		display6();
		glutPostRedisplay();
	}

}

void mykey(unsigned char key, int a, int b)
{
	if(key=='A'||key=='a')
	{
		slide=1;
		glutPostRedisplay();
	}
	if(key=='B'||key=='b')
	{
		slide=2;
		glutPostRedisplay();
	}
	if(key=='C'||key=='c')
	{
		slide=3;//water flowing
	
		glutPostRedisplay();
	}
	if(key=='D'||key=='d')
	{
		slide=4;//curent generation
		
		glutPostRedisplay();
	}
	
	if(key=='E'|| key=='e')
	{
		slide=5;//electricity supply
		glutPostRedisplay();
	}
	if(key=='F'||key=='f')
	{
		slide=6;//thank you
		glutPostRedisplay();
	}
}

int main(int argc, char**argv) 
{
   glutInit(&argc, argv);            
   glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); 
   glutInitWindowSize(1000,800);   
   glutInitWindowPosition(100,0); 
   glutCreateWindow("Hydropower Plant");  
         
   glutDisplayFunc(display);
   glutKeyboardFunc(mykey);
   glutReshapeFunc(reshape);
   	
   init();
   
   glutMainLoop();                 
}

