#include <GL/glut.h>
#include <stdio.h>
float x=250, y=250, z=0, scale=1.0, angle=0.0, oldX, oldY;
int now=1;
void display()
{
    glClearColor(0.8, 0.8, 0.8, 1);///顏色:R,G,B,A A->Alpha值
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glTranslatef((x-250)/250.0, -(y-250)/250.0, z);///m
    glRotatef(angle, 0, 0, 1);///e
    glScalef(scale, scale, scale);///r
    glColor3f(1,1,0);
    glutSolidTeapot(0.3);
    glPopMatrix();
    glutSwapBuffers();
}
void keyboard(unsigned char key, int mouseX, int mouseY) ///像Maya
{
    //printf("現在按下:%c 座標在:%d %d\n",key ,x ,y);
    if(key=='W' || key=='w') now=1; ///移動
    if(key=='E' || key=='e') now=2; ///旋轉
    if(key=='R' || key=='r') now=3; ///縮放

}
void mouse(int button, int state, int mouseX, int mouseY)
{
    oldX=mouseX; oldY=mouseY;
}
void motion(int mouseX, int mouseY)
{
    if(now==1){
        x+=(mouseX-oldX);
        y+=(mouseY-oldY);
    }else if(now==2){
        angle+=(mouseX-oldX);
    }else if(now==3){
        if(mouseX>oldX) scale=scale*1.01;
        if(mouseX<oldX) scale=scale*0.99;
    }

    oldX=mouseX; oldY=mouseY;
    display();
}
int main(int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(500,500);
    glutCreateWindow("week06 keyboard");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutMainLoop();
}
