#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<bits/stdc++.h>
float pi=22/7.0;
float rad=1.5;
float f1=0;
float f2=0;
float ang=pi/4;
float fishsize=1.7;
int check=0;
float rot_ang=0.0;
int count1=1;
float tail_ang=0.0;
int check2tail=-1;
void reshape(int w,int h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10,10,-10,10);
    glMatrixMode(GL_MODELVIEW);
}
void sky()
{
    glColor3f(0.5294,0.8078,0.92156);
    glBegin(GL_POLYGON);
    glVertex2f(-10,10);
    glVertex2f(-10,0);
    glColor3f(1,0.8784,0.5686);
    glVertex2f(-7-rad,0);
    glVertex2f(-7,rad);
    glVertex2f(-7+rad,0);
    glColor3f(0.5294,0.8078,0.92156);
    glVertex2f(10,0);
    glVertex2f(10,10);
    glEnd();
}
void sun()
{
    //int triangleAmount=40;
    glColor3f(1,0.34117,0.2);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(-7,0);
    glColor3f(0.9568,0.7686,0.1882);
    for(int i=0;i<=20;i++)
    {
        glVertex2f(-7+rad*cos(2*pi*i/40.0),0+rad*sin(2*pi*i/40.0));
    }
    glEnd();

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    glColor4f(1,0.34117,0.2,0.7);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(-7,0);
    glColor4f(0.9568,0.7686,0.1882,0.2);
    for(int i=20;i<=40;i++)
    {
        glVertex2f(-7+rad*cos(2*pi*i/40.0),0+rad*sin(2*pi*i/40.0));
    }
    glEnd();

}
void land()
{
    glColor3f(0.5922,0.4863,0.3255);
    glBegin(GL_POLYGON);
    glVertex2f(1,0);
    glVertex2f(8,-10);
    glVertex2f(10,-10);
    glVertex2f(10,0);
    glEnd();
}
void water()
{
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    glColor4f(0,0.4118,0.5804,0.5);
    glBegin(GL_POLYGON);
    glVertex2f(-10,0);
    glVertex2f(-10,-10);
    glVertex2f(8,-10);
    glVertex2f(1,0);
    glEnd();
}
void water1()
{
    //glColor3f(0,0.4118,0.5804);
    //glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    //glEnable(GL_BLEND);
    glColor3f(1,0.8784,0.5686);
    glBegin(GL_POLYGON);
    glVertex2f(-7+rad,0);
    glVertex2f(-7,-0);
    glVertex2f(-7-rad,0);
    glVertex2f(-10,0);
    glColor3f(0,0.4118,0.5804);
    glVertex2f(-10,-10);
    glVertex2f(8,-10);
    glVertex2f(1,0);
    glEnd();
}
void fish(float f1,float f2,double rot_ang,float tail_ang)
{
    if(count1%2!=0)
    {
        glTranslatef(1,-6,0);
    }
    else
    {
        glTranslatef(-7,-6,0);
    }
    glRotatef(rot_ang,0.0,1.0,0.0);
;
    //body
    glColor3f(0,0,1);
    glBegin(GL_POLYGON);
    glVertex2f(f1+fishsize*cos(ang)+0.66*fishsize*cos(ang),f2+0.34*fishsize*cos(ang));
    glVertex2f(f1+fishsize*cos(ang),f2+fishsize*cos(ang));
    glColor3f(1,1,0);
    glVertex2f(f1,f2);
    glColor3f(1,0,0);
    glVertex2f(f1+fishsize*cos(ang),f2-fishsize*cos(ang));
    glVertex2f(f1+fishsize*cos(ang)+0.66*fishsize*cos(ang),f2-0.34*fishsize*cos(ang));
    glEnd();
    //head
    glBegin(GL_TRIANGLES);
    glColor3f(1,0,0);
    glVertex2f(f1+2*fishsize*cos(ang),f2);
    glColor3f(1,1,0);
    glVertex2f(f1+fishsize*cos(ang)+0.66*fishsize*cos(ang),f2+0.34*fishsize*cos(ang));
    glColor3f(1,1,0);
    glVertex2f(f1+fishsize*cos(ang)+0.66*fishsize*cos(ang),f2-0.34*fishsize*cos(ang));
    glEnd();
    //eye
    glColor3f(1,1,1);
    float eye1=f1+fishsize*cos(ang)+0.8*fishsize*cos(ang);
    float eye2=f2;
    float eyerad=fishsize/15;
    glColor3f(0,0,0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(eye1,eye2);
    glColor3f(0,0,0);
    glColor3f(1,1,1);
    for(int i=0;i<=40;i++)
    {
        glVertex2f(eye1+eyerad*cos(2*pi*i/40.0),eye2+eyerad*sin(2*pi*i/40.0));
    }
    glEnd();

    if(check==1)
    {

        glTranslatef(f1,0,0);

        glRotatef(tail_ang,0.0,1.0,0.0);
    }
    //tail
    glBegin(GL_TRIANGLES);
    glColor3f(1,1,0);
    glVertex2f(0.0,0.0);
    glColor3f(1,0,0);
    glVertex2f(0.0-(0.4*fishsize)*cos(ang),0.0+(0.3*fishsize));
    glColor3f(0,0,1);
    glVertex2f(0.0-(0.4*fishsize)*cos(ang),0.0-(0.3*fishsize));
    glEnd();

    glLoadIdentity();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    //draw
    sky();
    land();
    water1();
    water();
    sun();
    fish(f1,f2,rot_ang,tail_ang);
    glutSwapBuffers();
}

void update()
{
    switch(check)
    {
        case 0:
        {
            if(rot_ang<count1*180)
            {
                rot_ang+=1.8;
            }
            else
            {
                check=1;
            }
            break;
        }
        case 1:
        {
            switch(check2tail)
            {
                case -1:
                {
                    if(tail_ang>-45.0)
                    {
                        tail_ang-=10.0;
                    }
                    else
                    {
                        check2tail=-2;
                    }
                    break;
                }
                case -2:
                {
                    if(tail_ang<45.0)
                    {
                        tail_ang+=10.0;
                    }
                    else
                    {
                        check2tail=-1;
                    }
                    break;
                }
            }
            if(f1<=8)
            {
                f1=f1+0.05;
            }
            else
            {
                f1=0;
                check=0;
                count1++;
            }
            break;
        }
    }
}
void timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/60,timer,0);
    update();
}
int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(200,200);
    glutCreateWindow("Fish");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0,timer,0);
    glutMainLoop();
}
