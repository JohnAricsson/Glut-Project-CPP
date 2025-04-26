#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include<cmath>
#include <math.h>
#include<iostream>
using namespace std;
bool active=false, night = false,lighthouse=false,speed=false;
int ship=0,window=0, blx=0,bly=0,c1=0,c2=1300,car=0,car1=0,light=0,step=2;


void display() {

            glClear(GL_COLOR_BUFFER_BIT);
            glLoadIdentity();
            gluOrtho2D(0,1500,0,1000);
            glMatrixMode(GL_MODELVIEW);
            glEnable(GL_BLEND);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
              //------------>First scenario<---------------

            glBegin(GL_QUADS);
            if(night) glColor3f(0.05f, 0.05f, 0.2f);
            else glColor3f(0.678f, 0.847f, 0.902f);  //sky
            glVertex2f(0,0);
            glVertex2f(1500,0);
            glVertex2f(1500,1000);
            glVertex2f(0,1000);
            glEnd();
            if(!night){
                glPushMatrix();
                glTranslatef(850, 900.0, 0.0);//sun
                glBegin(GL_POLYGON);
                glColor3f(1.0f, 1.0f, 0.6f);
                for(int j=0;j<360;j++){
                    float pi=3.1416;
                    float A=(j*2*pi)/180;
                    float r=40;
                    float x = r * cos(A);
                    float y = r * sin(A);
                    glVertex2f(x,y);
                }
                glEnd();
                glPopMatrix();
            }
            else{
                glPushMatrix();
                glTranslatef(850, 900.0, 0.0);
                glBegin(GL_POLYGON);
               glColor3f(1.0f, 1.0f, 0.8f);//moon
                for(int j=0;j<360;j++){
                    float pi=3.1416;
                    float A=(j*2*pi)/180;
                    float r=40;
                    float x = r * cos(A);
                    float y = r * sin(A);
                    glVertex2f(x,y);
                }
                glEnd();
                glPopMatrix();
                glPushMatrix();
                glTranslatef(865, 900.0, 0.0);
                glBegin(GL_POLYGON);
                glColor3f(0.05f, 0.05f, 0.2f);//moon
                for(int j=0;j<360;j++){
                    float pi=3.1416;
                    float A=(j*2*pi)/180;
                    float r=35;
                    float x = r * cos(A);
                    float y = r * sin(A);
                    glVertex2f(x,y);
                }
                glEnd();
                glPopMatrix();
            }
            glBegin(GL_POLYGON);//mountains
            glColor3f(0.0f, 0.329f, 0.471f);
            glVertex2f(0,550);
            glVertex2f(0,700);
            glVertex2f(100,760);
            glVertex2f(120,730);
            glVertex2f(180,800);
            glVertex2f(240,700);
            glVertex2f(260,730);
            glVertex2f(300,700);
            glVertex2f(300,550);
            glEnd();

            glBegin(GL_POLYGON);//mountains
            if(night) glColor3f(0.1f, 0.3f, 0.25f);
            else glColor3f(0.2f, 0.6f, 0.5f);
            glVertex2f(150,550);
            glVertex2f(200,650);
            glVertex2f(320,770);
            glVertex2f(380,850);
            glVertex2f(500,650);
            glVertex2f(520,730);
            glVertex2f(600,650);
            glVertex2f(700,550);
            glEnd();
            glBegin(GL_POLYGON);//mountains
            if (night) glColor3f(0.15f, 0.4f, 0.3f);
            else glColor3f(0.3f, 0.75f, 0.6f);
            glVertex2f(220,550);
            glVertex2f(260,600);
            glVertex2f(320,700);
            glVertex2f(400,770);
            glVertex2f(480,650);
            glVertex2f(530,620);
            glVertex2f(590,550);

            glEnd();
            glBegin(GL_QUADS);
            if(night )glColor3f(0.2f, 0.2f, 0.2f);
            else glColor3f(0.94f, 0.87f, 0.73f);//land
            glVertex2f(0, 450);
            glVertex2f(1500, 450);
            glVertex2f(1500, 380);
            glVertex2f(0, 380);
            glEnd();
            glBegin(GL_QUADS);
            if(night)glColor3f(0.2f, 0.1f, 0.1f);
            else glColor3f(0.85f, 0.45f, 0.25f); //stone
            glVertex2f(0, 450);
            glVertex2f(1500, 450);
            glVertex2f(1500, 470);
            glVertex2f(0, 470);
            glEnd();
            glBegin(GL_QUADS);
            if(night) glColor3f(0.0f, 0.2f, 0.2f);
            else glColor3f(0.0f, 0.573f, 0.561f);//grass
            glVertex2f(0, 470);
            glVertex2f(1500, 470);
            glVertex2f(1500, 550);
            glVertex2f(0, 550);
            glEnd();

            int bush=0;
            for(int i=0;i<30;i++){
            glBegin(GL_TRIANGLES);
            if(night) glColor3f(0.1f, 0.3f, 0.1f);
            else glColor3f(0.380f, 0.788f, 0.333f); //bush
            glVertex2f(bush+0, 470);
            glVertex2f(bush+50, 470);
            glVertex2f(bush+25, 490);

            glVertex2f(bush+0, 475);
            glVertex2f(bush+50, 475);
            glVertex2f(bush+25, 495);

            glVertex2f(bush+0, 480);
            glVertex2f(bush+50, 480);
            glVertex2f(bush+25, 500);

            glVertex2f(bush+0, 485);
            glVertex2f(bush+50, 485);
            glVertex2f(bush+25, 500);
            glEnd();
            bush+=50;
            }

            glBegin(GL_QUADS);
            if(night) glColor3f(0.3f, 0.3f, 0.3f);
            else glColor3f(0.75f, 0.75f, 0.75f); //road
            glVertex2f(0, 520);
            glVertex2f(1500, 520);
            glVertex2f(1500, 550);
            glVertex2f(0, 550);
            glEnd();
            glBegin(GL_QUADS);
            if(night) glColor3f(0.1f, 0.1f, 0.1f);
            else glColor3f(0.3f, 0.3f, 0.3f); //road shadow
            glVertex2f(0, 520);
            glVertex2f(1500, 520);
            glVertex2f(1500, 510);
            glVertex2f(0, 510);
            glEnd();
            int road=0;
            for(int i=0;i<5;i++){
            glBegin(GL_QUADS);
            if(night) glColor3f(0.1f, 0.1f, 0.1f);
            else glColor3f(0.3f, 0.3f, 0.3f); //road shadow
            glVertex2f(road+100, 470);
            glVertex2f(road+130, 470);
            glVertex2f(road+130, 510);
            glVertex2f(road+100, 510);
            glEnd();
            road+=300;
            }

            glBegin(GL_QUADS);
            if(night) glColor3f(0.2f, 0.2f, 0.2f);
            else glColor3f(0.6f, 0.6f, 0.6f); //lighthouse
            glVertex2f(1260,650);
            glVertex2f(1340,650);
            glVertex2f(1340,670);
            glVertex2f(1260,670);
            glEnd();
            glBegin(GL_QUADS);
            if(night) glColor3f(0.4f, 0.4f, 0.5f);
            else glColor3f(0.9f, 0.9f, 0.9f); //lighthouse
            glVertex2f(1270,670);
            glVertex2f(1330,670);
            glVertex2f(1330,750);
            glVertex2f(1270,750);
            glEnd();
            glBegin(GL_QUADS);
            if(night) glColor3f(0.4f, 0.4f, 0.5f);
            else glColor3f(0.9f, 0.9f, 0.9f); //lighthouse
            glVertex2f(1270,750);
            glVertex2f(1275,750);
            glVertex2f(1275,780);
            glVertex2f(1270,780);
            glEnd();
            glBegin(GL_QUADS);
            if(night) glColor3f(0.4f, 0.4f, 0.5f);
            else glColor3f(0.9f, 0.9f, 0.9f); //lighthouse
            glVertex2f(1325,750);
            glVertex2f(1330,750);
            glVertex2f(1330,780);
            glVertex2f(1325,780);
            glEnd();
            glBegin(GL_QUADS);
            if(night) glColor3f(0.25f, 0.13f, 0.05f);
            else glColor3f(0.55f, 0.27f, 0.07f);  //lighthouse
            glVertex2f(1290,750);
            glVertex2f(1310,750);
            glVertex2f(1310,755);
            glVertex2f(1290,755);
            glEnd();
            glPushMatrix();
                glTranslatef(1300, 762.0, 0.0);//light
                glBegin(GL_POLYGON);
                glColor3f(1.0f, 0.9f, 0.7f);
                for(int j=0;j<360;j++){
                    float pi=3.1416;
                    float A=(j*2*pi)/180;
                    float r=10;
                    float x = r * cos(A);
                    float y = r * sin(A);
                    glVertex2f(x,y);
                }
                glEnd();
            glPopMatrix();
            glBegin(GL_TRIANGLES);
            glColor3f(0.25f, 0.25f, 0.25f); //lighthouse
            glVertex2f(1260,780);
            glVertex2f(1300,820);
            glVertex2f(1340,780);
            glEnd();

            glBegin(GL_POLYGON);
            if(night)glColor3f(0.2f, 0.1f, 0.1f);
            else glColor3f(0.85f, 0.45f, 0.25f); //stone
            glVertex2f(1080,550);
            glVertex2f(1080,570);
            glVertex2f(1250,650);
            glVertex2f(1350,650);
            glVertex2f(1500,570);
            glVertex2f(1500,550);
            glEnd();
            glBegin(GL_QUADS);
            if(night) glColor3f(0.4f, 0.4f, 0.5f);
            else glColor3f(0.9f, 0.9f, 0.9f); //building
            glVertex2f(620,550);
            glVertex2f(1080,550);
            glVertex2f(1080,680);
            glVertex2f(620,680);
            glEnd();
            glBegin(GL_QUADS);
            if(night) glColor3f(0.2f, 0.3f, 0.4f);
            else glColor3f(0.4f, 0.6f, 0.8f);//building window
            glVertex2f(625,550);
            glVertex2f(825,550);
            glVertex2f(825,670);
            glVertex2f(625,670);
            glEnd();
            bly=0;
            glBegin(GL_QUADS);
            for(int j=0;j<3;j++){
                    blx=0;
                for(int i=0;i<5;i++){
                    if(night)glColor3f(1.0f, 0.9f, 0.6f);
                    else glColor3f(0.678f, 0.847f, 0.902f);//body window
                    glVertex2f(blx+630,bly+555);
                    glVertex2f(blx+655,bly+555);
                    glVertex2f(blx+655,bly+570);
                    glVertex2f(blx+630,bly+570);
                    blx = blx+40;
                }bly+=35;
            }
            glEnd();
            glBegin(GL_QUADS);
            if(night) glColor3f(0.2f, 0.3f, 0.4f);
            else glColor3f(0.4f, 0.6f, 0.8f);//building window
            glVertex2f(875,550);
            glVertex2f(1075,550);
            glVertex2f(1075,670);
            glVertex2f(875,670);
            glEnd();
            bly=0;
            glBegin(GL_QUADS);
            for(int j=0;j<3;j++){
                    blx=0;
                for(int i=0;i<5;i++){
                    if(night)glColor3f(1.0f, 0.9f, 0.6f);
                    else glColor3f(0.678f, 0.847f, 0.902f);//body window
                    glVertex2f(blx+880,bly+555);
                    glVertex2f(blx+905,bly+555);
                    glVertex2f(blx+905,bly+570);
                    glVertex2f(blx+880,bly+570);
                    blx = blx+40;
                }bly+=35;
            }
            glEnd();
            glBegin(GL_QUADS);
            if(night) glColor3f(0.15f, 0.15f, 0.15f);
            else glColor3f(0.3f, 0.3f, 0.3f);//building door
            glVertex2f(830,550);
            glVertex2f(870,550);
            glVertex2f(870,610);
            glVertex2f(830,610);
            glEnd();

            int k=0;
            for(int i=0;i<10;i++){

                glBegin(GL_QUADS);
                if(night) glColor3f(0.2f, 0.125f, 0.05f);
                else glColor3f(0.4f, 0.25f, 0.1f);//light
                glVertex2f(k+100,550);
                glVertex2f(k+110,550);
                glVertex2f(k+110,600);
                glVertex2f(k+100,600);
                glEnd();
                glBegin(GL_QUADS);
                if(night) glColor3f(0.2f, 0.125f, 0.05f);
                else glColor3f(0.4f, 0.25f, 0.1f);//light
                glVertex2f(k+97,600);
                glVertex2f(k+113,600);
                glVertex2f(k+113,620);
                glVertex2f(k+97,620);
                glEnd();
                glPushMatrix();
                glTranslatef(k+105, 610.0, 0.0);
                glBegin(GL_POLYGON);
                glColor3f(1.0f, 1.0f, 0.6f);
                for(int j=0;j<360;j++){
                    float pi=3.1416;
                    float A=(j*2*pi)/180;
                    float r=5;
                    float x = r * cos(A);
                    float y = r * sin(A);
                    glVertex2f(x,y);
                }
                glEnd();
                glPopMatrix();
                k+=215;
            }




            glBegin(GL_QUADS);
            if(night) glColor3f(0.0f, 0.25f, 0.35f);
            else glColor3f(0.0f, 0.5f, 0.7f);//water
            glVertex2f(0, 380);
            glVertex2f(1500, 420);
            glVertex2f(1500, 0);
            glVertex2f(0, 0);
            glEnd();

            glBegin(GL_QUADS);
            if(night) glColor3f(0.05f, 0.1f, 0.15f);
            else glColor3f(0.1f, 0.2f, 0.3f);//boat
            glVertex2f(1250, 380);
            glVertex2f(1400, 380);
            glVertex2f(1380, 360);
            glVertex2f(1270, 360);
            glEnd();

            glBegin(GL_QUADS);
            if(night)glColor3f(0.27f, 0.14f, 0.04f);
            else glColor3f(0.54f, 0.27f, 0.07f);
            glVertex2f(1325, 380);
            glVertex2f(1330, 380);
            glVertex2f(1330, 470);
            glVertex2f(1325, 470);
            glEnd();
            glBegin(GL_TRIANGLES);
            if(night) glColor3f(0.4f, 0.4f, 0.5f);
            else glColor3f(0.9f, 0.9f, 0.9f);
            glVertex2f(1330,470);
            glVertex2f(1330,400);
            glVertex2f(1400,400);
            glEnd();
            glBegin(GL_TRIANGLES);
            if(night) glColor3f(0.4f, 0.4f, 0.5f);
            else glColor3f(0.9f, 0.9f, 0.9f);
            glVertex2f(1325,470);
            glVertex2f(1325,400);
            glVertex2f(1280,400);
            glEnd();


             // Light blue transparent shine
            glBegin(GL_POLYGON);
            glColor4f(0.7f, 0.9f, 1.0f, 0.4f);
            glVertex2f(ship+130, 75);
            glVertex2f(ship+550, 75);
            glVertex2f(ship+250, 55);
            glVertex2f(ship+130, 75);
            glEnd();



            //speedboat
            glBegin(GL_QUADS);
            if(night) glColor3f(0.2f, 0.2f, 0.2f);
            else glColor3f(0.3f, 0.3f, 0.3f);
            glVertex2f(950, 300);
            glVertex2f(900, 350);
            glVertex2f(1200, 350);
            glVertex2f(1100, 300);
            glEnd();

            glBegin(GL_QUADS);
            if(night) glColor3f(0.45f, 0.45f, 0.4f);
            else glColor3f(0.9f, 0.9f, 0.8f);
            glVertex2f(950, 350);
            glVertex2f(1050, 350);
            glVertex2f(1050, 370);
            glVertex2f(950, 370);
            glEnd();
            glBegin(GL_QUADS);
            if(night)glColor3f(1.0f, 0.9f, 0.6f);
            else glColor3f(0.4f, 0.6f, 0.8f);
            glVertex2f(960, 350);
            glVertex2f(1040, 350);
            glVertex2f(1040, 365);
            glVertex2f(960, 365);
            glEnd();
            blx=0;

            for(int i=0;i<6;i++){
            glBegin(GL_QUADS);
            if(night)glColor3f(1.0f, 0.9f, 0.6f);
            else glColor3f(0.75f, 0.75f, 0.75f);
            glVertex2f(blx+950, 320);
            glVertex2f(blx+970, 320);
            glVertex2f(blx+970, 340);
            glVertex2f(blx+950, 340);
            blx+=30;
            glEnd();
            }

            glBegin(GL_QUADS);
            if(night) glColor3f(0.2f, 0.25f, 0.4f);
            else glColor3f(0.4f, 0.5f, 0.8f);
            glVertex2f(1050, 350);
            glVertex2f(1055, 350);
            glVertex2f(1055, 420);
            glVertex2f(1050, 420);
            glEnd();
            glBegin(GL_TRIANGLES);
            if(night) glColor3f(0.3f, 0.3f, 0.3f);
            else glColor3f(0.75f, 0.75f, 0.75f);
            glVertex2f(1055, 420);
            glVertex2f(1120, 350);
            glVertex2f(1190, 350);
            glEnd();


            //---------->SHIP CODE <------------
            glPushMatrix();
            glBegin(GL_POLYGON);
            if(night) glColor3f(0.275f, 0.0f, 0.0f);
            else glColor3f(0.55f, 0.0f, 0.0f);//red
            glVertex2f(ship+150,100);
            glVertex2f(ship+530,100);
            glVertex2f(ship+500,70);
            glVertex2f(ship+170,70);
            glVertex2f(ship+150,80);
            glEnd();
            glBegin(GL_POLYGON);
            if(night) glColor3f(0.4f, 0.4f, 0.5f);
            else glColor3f(0.9f, 0.9f, 0.9f);//white body
            glVertex2f(ship+100,180);
            glVertex2f(ship+100,150);
            glVertex2f(ship+150,100);
            glVertex2f(ship+530,100);
            glVertex2f(ship+610,180);
            glEnd();
            glBegin(GL_QUADS);
            glColor3f(0.0f, 0.0f, 0.5f);//body shadow
            glVertex2f(ship+100,180);
            glVertex2f(ship+100,170);
            glVertex2f(ship+600,170);
            glVertex2f(ship+610,180);
            glEnd();
            glBegin(GL_QUADS);
            if(night) glColor3f(0.2f, 0.3f, 0.4f);
            else glColor3f(0.4f, 0.6f, 0.8f);//body window
            glVertex2f(ship+150,165);
            glVertex2f(ship+540,165);
            glVertex2f(ship+540,150);
            glVertex2f(ship+150,150);
            glEnd();
            glBegin(GL_QUADS);
            window=0;
            for(int i=0;i<20;i++){
                if(night)glColor3f(1.0f, 0.9f, 0.6f);
                    else glColor3f(0.678f, 0.847f, 0.902f);//body window
                glVertex2f(ship+window+160,165);
                glVertex2f(ship+window+170,165);
                glVertex2f(ship+window+170,150);
                glVertex2f(ship+window+160,150);
                window+=20;
            }
            glEnd();
            glBegin(GL_QUADS);
            window=0;
            for(int i=0;i<40;i++){
                glColor3f(0.1f, 0.1f, 0.1f);//body window
                glVertex2f(ship+window+155,140);
                glVertex2f(ship+window+160,140);
                glVertex2f(ship+window+160,130);
                glVertex2f(ship+window+155,130);
                window+=10;
            }
            glEnd();
            glBegin(GL_QUADS);
            if(night) glColor3f(0.4f, 0.4f, 0.5f);
            else glColor3f(0.9f, 0.9f, 0.9f);//first layer
            glVertex2f(ship+150,180);
            glVertex2f(ship+540,180);
            glVertex2f(ship+540,200);
            glVertex2f(ship+150,200);
            glEnd();
            glBegin(GL_QUADS);
            glColor3f(0.0f, 0.0f, 0.5f);//first layer shadow
            glVertex2f(ship+150,200);
            glVertex2f(ship+540,200);
            glVertex2f(ship+540,205);
            glVertex2f(ship+150,205);
            glEnd();
            glBegin(GL_QUADS);
            if(night) glColor3f(0.2f, 0.3f, 0.4f);
            else glColor3f(0.4f, 0.6f, 0.8f);//window
            glVertex2f(ship+150,185);
            glVertex2f(ship+540,185);
            glVertex2f(ship+540,195);
            glVertex2f(ship+150,195);
            glEnd();
            glBegin(GL_QUADS);
            window=0;
            for(int i=0;i<19;i++){
                if(night)glColor3f(1.0f, 0.9f, 0.6f);
                    else glColor3f(0.678f, 0.847f, 0.902f);// window
                glVertex2f(ship+window+160,185);
                glVertex2f(ship+window+170,185);
                glVertex2f(ship+window+170,195);
                glVertex2f(ship+window+160,195);
                window+=20;
            }
            glEnd();
            glBegin(GL_QUADS);
            if(night) glColor3f(0.4f, 0.4f, 0.5f);
            else glColor3f(0.9f, 0.9f, 0.9f);//second layer
            glVertex2f(ship+150,205);
            glVertex2f(ship+540,205);
            glVertex2f(ship+530,225);
            glVertex2f(ship+160,225);
            glEnd();
            glBegin(GL_QUADS);
            glColor3f(0.0f, 0.0f, 0.5f);//second layer shadow
            glVertex2f(ship+160,225);
            glVertex2f(ship+530,225);
            glVertex2f(ship+530,230);
            glVertex2f(ship+160,230);
            glEnd();
            glBegin(GL_QUADS);
            if(night) glColor3f(0.2f, 0.3f, 0.4f);
            else glColor3f(0.4f, 0.6f, 0.8f);//window
            glVertex2f(ship+160,210);
            glVertex2f(ship+530,210);
            glVertex2f(ship+530,220);
            glVertex2f(ship+160,220);
            glEnd();
            glBegin(GL_QUADS);
            window=0;
            for(int i=0;i<18;i++){
                if(night)glColor3f(1.0f, 0.9f, 0.6f);
                    else glColor3f(0.678f, 0.847f, 0.902f);// window
                glVertex2f(ship+window+170,210);
                glVertex2f(ship+window+180,210);
                glVertex2f(ship+window+180,220);
                glVertex2f(ship+window+170,220);
                window+=20;
            }
            glEnd();
            glBegin(GL_QUADS);
            if(night) glColor3f(0.4f, 0.4f, 0.5f);
            else glColor3f(0.9f, 0.9f, 0.9f);//third layer
            glVertex2f(ship+170,230);
            glVertex2f(ship+310,230);
            glVertex2f(ship+300,245);
            glVertex2f(ship+180,245);
            glEnd();
            glBegin(GL_QUADS);
            if(night)glColor3f(1.0f, 0.9f, 0.6f);
            else glColor3f(0.678f, 0.847f, 0.902f);
            glVertex2f(ship+180,232);
            glVertex2f(ship+300,232);
            glVertex2f(ship+293,243);
            glVertex2f(ship+187,243);
            glEnd();
            glBegin(GL_QUADS);
            if(night) glColor3f(0.4f, 0.4f, 0.5f);
            else glColor3f(0.9f, 0.9f, 0.9f);//chimney
            glVertex2f(ship+400,230);
            glVertex2f(ship+450,230);
            glVertex2f(ship+450,280);
            glVertex2f(ship+400,280);
            glEnd();
            glBegin(GL_QUADS);
            if(night) glColor3f(0.2f, 0.2f, 0.2f);
            else glColor3f(0.5f, 0.5f, 0.5f);//chimney shadow
            glVertex2f(ship+400,280);
            glVertex2f(ship+450,280);
            glVertex2f(ship+450,285);
            glVertex2f(ship+400,285);
            glEnd();
            glBegin(GL_QUADS);
            if(night) glColor3f(0.4f, 0.4f, 0.5f);
            else glColor3f(0.9f, 0.9f, 0.9f);//design
            glVertex2f(ship+210,245);
            glVertex2f(ship+210,290);
            glVertex2f(ship+250,290);
            glVertex2f(ship+280,245);
            glEnd();
            glBegin(GL_QUADS);
            glColor3f(0.0f, 0.0f, 0.5f);//design
            glVertex2f(ship+210,245);
            glVertex2f(ship+210,250);
            glVertex2f(ship+278,250);
            glVertex2f(ship+280,245);
            glEnd();

            glPushMatrix();
                glTranslatef(c1, 925.0-50, 0.0);//clouds
                glBegin(GL_POLYGON);
                if(night) glColor3f(0.4f, 0.4f, 0.5f);
                else glColor3f(0.9f, 0.9f, 0.9f);
                for(int j=0;j<360;j++){
                    float pi=3.1416;
                    float A=(j*2*pi)/180;
                    float r=20;
                    float x = r * cos(A);
                    float y = r * sin(A);
                    glVertex2f(x,y);
                }
                glEnd();
            glPopMatrix();
            glPushMatrix();
                glTranslatef(c1+25, 910.0-50, 0.0);//clouds
                glBegin(GL_POLYGON);
                if(night) glColor3f(0.4f, 0.4f, 0.5f);
                else glColor3f(0.9f, 0.9f, 0.9f);
                for(int j=0;j<360;j++){
                    float pi=3.1416;
                    float A=(j*2*pi)/180;
                    float r=20;
                    float x = r * cos(A);
                    float y = r * sin(A);
                    glVertex2f(x,y);
                }
                glEnd();
            glPopMatrix();
            glPushMatrix();
                glTranslatef(c1+25, 940.0-50, 0.0);//clouds
                glBegin(GL_POLYGON);
                if(night) glColor3f(0.4f, 0.4f, 0.5f);
                else glColor3f(0.9f, 0.9f, 0.9f);
                for(int j=0;j<360;j++){
                    float pi=3.1416;
                    float A=(j*2*pi)/180;
                    float r=20;
                    float x = r * cos(A);
                    float y = r * sin(A);
                    glVertex2f(x,y);
                }
                glEnd();
            glPopMatrix();
            glPushMatrix();
                glTranslatef(c1+50, 910-50.0, 0.0);//clouds
                glBegin(GL_POLYGON);
                if(night) glColor3f(0.4f, 0.4f, 0.5f);
                else glColor3f(0.9f, 0.9f, 0.9f);
                for(int j=0;j<360;j++){
                    float pi=3.1416;
                    float A=(j*2*pi)/180;
                    float r=20;
                    float x = r * cos(A);
                    float y = r * sin(A);
                    glVertex2f(x,y);
                }
                glEnd();
            glPopMatrix();
            glPushMatrix();
                glTranslatef(c1+50, 940.0-50, 0.0);//clouds
                glBegin(GL_POLYGON);
                if(night) glColor3f(0.4f, 0.4f, 0.5f);
                else glColor3f(0.9f, 0.9f, 0.9f);
                for(int j=0;j<360;j++){
                    float pi=3.1416;
                    float A=(j*2*pi)/180;
                    float r=20;
                    float x = r * cos(A);
                    float y = r * sin(A);
                    glVertex2f(x,y);
                }
                glEnd();
            glPopMatrix();
            glPushMatrix();
                glTranslatef(c1+75, 925.0-50, 0.0);//clouds
                glBegin(GL_POLYGON);
                if(night) glColor3f(0.4f, 0.4f, 0.5f);
                else glColor3f(0.9f, 0.9f, 0.9f);
                for(int j=0;j<360;j++){
                    float pi=3.1416;
                    float A=(j*2*pi)/180;
                    float r=20;
                    float x = r * cos(A);
                    float y = r * sin(A);
                    glVertex2f(x,y);
                }
                glEnd();
            glPopMatrix();
             glPopMatrix();
            glPushMatrix();
                glTranslatef(c1+200, 960.0-50, 0.0);//clouds
                glBegin(GL_POLYGON);
                if(night) glColor3f(0.4f, 0.4f, 0.5f);
                else glColor3f(0.9f, 0.9f, 0.9f);
                for(int j=0;j<360;j++){
                    float pi=3.1416;
                    float A=(j*2*pi)/180;
                    float r=20;
                    float x = r * cos(A);
                    float y = r * sin(A);
                    glVertex2f(x,y);
                }
                glEnd();
            glPopMatrix();
            glPushMatrix();
                glTranslatef(c1+225, 945.0-50, 0.0);//clouds
                glBegin(GL_POLYGON);
                if(night) glColor3f(0.4f, 0.4f, 0.5f);
                else glColor3f(0.9f, 0.9f, 0.9f);
                for(int j=0;j<360;j++){
                    float pi=3.1416;
                    float A=(j*2*pi)/180;
                    float r=20;
                    float x = r * cos(A);
                    float y = r * sin(A);
                    glVertex2f(x,y);
                }
                glEnd();
            glPopMatrix();
            glPushMatrix();
                glTranslatef(c1+225, 975.0-50, 0.0);//clouds
                glBegin(GL_POLYGON);
                if(night) glColor3f(0.4f, 0.4f, 0.5f);
                else glColor3f(0.9f, 0.9f, 0.9f);
                for(int j=0;j<360;j++){
                    float pi=3.1416;
                    float A=(j*2*pi)/180;
                    float r=20;
                    float x = r * cos(A);
                    float y = r * sin(A);
                    glVertex2f(x,y);
                }
                glEnd();
            glPopMatrix();
            glPushMatrix();
                glTranslatef(c1+250, 945.0-50, 0.0);//clouds
                glBegin(GL_POLYGON);
                if(night) glColor3f(0.4f, 0.4f, 0.5f);
                else glColor3f(0.9f, 0.9f, 0.9f);
                for(int j=0;j<360;j++){
                    float pi=3.1416;
                    float A=(j*2*pi)/180;
                    float r=20;
                    float x = r * cos(A);
                    float y = r * sin(A);
                    glVertex2f(x,y);
                }
                glEnd();
            glPopMatrix();
            glPushMatrix();
                glTranslatef(c1+250, 975.0-50, 0.0);//clouds
                glBegin(GL_POLYGON);
                if(night) glColor3f(0.4f, 0.4f, 0.5f);
                else glColor3f(0.9f, 0.9f, 0.9f);
                for(int j=0;j<360;j++){
                    float pi=3.1416;
                    float A=(j*2*pi)/180;
                    float r=20;
                    float x = r * cos(A);
                    float y = r * sin(A);
                    glVertex2f(x,y);
                }
                glEnd();
            glPopMatrix();
            glPushMatrix();
                glTranslatef(c1+275, 960.0-50, 0.0);//clouds
                glBegin(GL_POLYGON);
                if(night) glColor3f(0.4f, 0.4f, 0.5f);
                else glColor3f(0.9f, 0.9f, 0.9f);
                for(int j=0;j<360;j++){
                    float pi=3.1416;
                    float A=(j*2*pi)/180;
                    float r=20;
                    float x = r * cos(A);
                    float y = r * sin(A);
                    glVertex2f(x,y);
                }
                glEnd();
            glPopMatrix();
            glPushMatrix();
                glTranslatef(c2, 950.0-50, 0.0);//clouds
                glBegin(GL_POLYGON);
                if(night) glColor3f(0.4f, 0.4f, 0.5f);
                else glColor3f(0.9f, 0.9f, 0.9f);
                for(int j=0;j<360;j++){
                    float pi=3.1416;
                    float A=(j*2*pi)/180;
                    float r=20;
                    float x = r * cos(A);
                    float y = r * sin(A);
                    glVertex2f(x,y);
                }
                glEnd();
            glPopMatrix();
            glPushMatrix();
                glTranslatef(c2+25, 935.0-50, 0.0);//clouds
                glBegin(GL_POLYGON);
               if(night) glColor3f(0.4f, 0.4f, 0.5f);
                else glColor3f(0.9f, 0.9f, 0.9f);
                for(int j=0;j<360;j++){
                    float pi=3.1416;
                    float A=(j*2*pi)/180;
                    float r=20;
                    float x = r * cos(A);
                    float y = r * sin(A);
                    glVertex2f(x,y);
                }
                glEnd();
            glPopMatrix();
            glPushMatrix();
                glTranslatef(c2+25, 965.0-50, 0.0);//clouds
                glBegin(GL_POLYGON);
                if(night) glColor3f(0.4f, 0.4f, 0.5f);
                else glColor3f(0.9f, 0.9f, 0.9f);
                for(int j=0;j<360;j++){
                    float pi=3.1416;
                    float A=(j*2*pi)/180;
                    float r=20;
                    float x = r * cos(A);
                    float y = r * sin(A);
                    glVertex2f(x,y);
                }
                glEnd();
            glPopMatrix();
            glPushMatrix();
                glTranslatef(c2+50, 935.0-50, 0.0);//clouds
                glBegin(GL_POLYGON);
                if(night) glColor3f(0.4f, 0.4f, 0.5f);
                else glColor3f(0.9f, 0.9f, 0.9f);
                for(int j=0;j<360;j++){
                    float pi=3.1416;
                    float A=(j*2*pi)/180;
                    float r=20;
                    float x = r * cos(A);
                    float y = r * sin(A);
                    glVertex2f(x,y);
                }
                glEnd();
            glPopMatrix();
            glPushMatrix();
                glTranslatef(c2+50, 965.0-50, 0.0);//clouds
                glBegin(GL_POLYGON);
                if(night) glColor3f(0.4f, 0.4f, 0.5f);
                else glColor3f(0.9f, 0.9f, 0.9f);
                for(int j=0;j<360;j++){
                    float pi=3.1416;
                    float A=(j*2*pi)/180;
                    float r=20;
                    float x = r * cos(A);
                    float y = r * sin(A);
                    glVertex2f(x,y);
                }
                glEnd();
            glPopMatrix();
            glPushMatrix();
                glTranslatef(c2+75, 950.0-50, 0.0);//clouds
                glBegin(GL_POLYGON);
                if(night) glColor3f(0.4f, 0.4f, 0.5f);
                else glColor3f(0.9f, 0.9f, 0.9f);
                for(int j=0;j<360;j++){
                    float pi=3.1416;
                    float A=(j*2*pi)/180;
                    float r=20;
                    float x = r * cos(A);
                    float y = r * sin(A);
                    glVertex2f(x,y);
                }
                glEnd();

            //-------->CAR<---------
            glPopMatrix();
            glBegin(GL_POLYGON);
            if(night) glColor3f(0.3f, 0.3f, 0.0f);
            else glColor3f(1.0f, 0.8f, 0.0f);
            glVertex2f(car+0,550-15);
            glVertex2f(car+150,550-15);
            glVertex2f(car+150,590-15);
            glVertex2f(car+145,585-15);
            glVertex2f(car+0,580-15);
            glEnd();

            glBegin(GL_POLYGON);
            if(night) glColor3f(0.7f, 1.0f, 0.9f);
            else glColor3f(0.4f, 0.5f, 0.8f);
            glVertex2f(car+0,580-15);
            glVertex2f(car+145,580-15);
            glVertex2f(car+150,585-15);
            glVertex2f(car+150,600-15);
            glVertex2f(car+145,595-15);
            glVertex2f(car+140,600-15);
            glVertex2f(car+0,600-15);
            glEnd();
            glBegin(GL_POLYGON);
            if(night) glColor3f(0.3f, 0.3f, 0.0f);
            else glColor3f(1.0f, 0.8f, 0.0f);
            glVertex2f(car+0,600-15);
            glVertex2f(car+140,600-15);
            glVertex2f(car+145,610-15);
            glVertex2f(car+10,610-15);
            glEnd();
            glBegin(GL_POLYGON);
            if(night) glColor3f(0.3f, 0.3f, 0.0f);
            else glColor3f(1.0f, 0.8f, 0.0f);
            glVertex2f(car+140,600-15);
            glVertex2f(car+145,595-15);
            glVertex2f(car+150,600-15);
            glVertex2f(car+145,610-15);
            glEnd();
            // car wheel
            glPushMatrix();
                glTranslatef(car+125, 535.0, 0.0);
                glBegin(GL_POLYGON);
                glColor3f(0.0f, 0.0f, 0.0f);
                for(int j=0;j<360;j++){
                    float pi=3.1416;
                    float A=(j*2*pi)/180;
                    float r=10;
                    float x = r * cos(A);
                    float y = r * sin(A);
                    glVertex2f(x,y);
                }
                glEnd();
            glPopMatrix();
             glPushMatrix();
                glTranslatef(car+25, 535.0, 0.0);
                glBegin(GL_POLYGON);
                glColor3f(0.0f, 0.0f, 0.0f);
                for(int j=0;j<360;j++){
                    float pi=3.1416;
                    float A=(j*2*pi)/180;
                    float r=10;
                    float x = r * cos(A);
                    float y = r * sin(A);
                    glVertex2f(x,y);
                }
                glEnd();
            glPopMatrix();

            glBegin(GL_POLYGON);
            if(night)glColor3f(0.1f, 0.2f, 0.3f);
            else glColor3f(0.2f, 0.4f, 0.5f);//car2
            glVertex2f(car1+1495,535-5);
            glVertex2f(car1+1485,550-5);
            glVertex2f(car1+1400,550-5);
            glVertex2f(car1+1390,535-5);
            glEnd();
            glBegin(GL_POLYGON);
            if(night) glColor3f(0.1f, 0.2f, 0.3f);
            else glColor3f(0.2f, 0.4f, 0.5f);
            glVertex2f(car1+1420,550-5);
            glVertex2f(car1+1430,560-5);
            glVertex2f(car1+1465,560-5);
            glVertex2f(car1+1475,550-5);
            glEnd();
             glBegin(GL_POLYGON);
            if(night) glColor3f(0.7f, 1.0f, 0.9f);
            else glColor3f(0.4f, 0.5f, 0.8f);
            glVertex2f(car1+1422,550-5);
            glVertex2f(car1+1432,558-5);
            glVertex2f(car1+1463,558-5);
            glVertex2f(car1+1473,550-5);
            glEnd();
            glPushMatrix();
                glTranslatef(car1+1420, 535.0-5, 0.0);
                glBegin(GL_POLYGON);
                glColor3f(0.0f, 0.0f, 0.0f);
                for(int j=0;j<360;j++){
                    float pi=3.1416;
                    float A=(j*2*pi)/180;
                    float r=8;
                    float x = r * cos(A);
                    float y = r * sin(A);
                    glVertex2f(x,y);
                }
                glEnd();
            glPopMatrix();
             glPushMatrix();
                glTranslatef(car1+1475, 535.0-5, 0.0);
                glBegin(GL_POLYGON);
                glColor3f(0.0f, 0.0f, 0.0f);
                for(int j=0;j<360;j++){
                    float pi=3.1416;
                    float A=(j*2*pi)/180;
                    float r=8;
                    float x = r * cos(A);
                    float y = r * sin(A);
                    glVertex2f(x,y);
                }
                glEnd();
            glPopMatrix();

            glBegin(GL_POLYGON);
            if(night) glColor3f(0.3f, 0.0f, 0.0f);
            else glColor3f(1.0f, 0.0f, 0.0f);//car3
            glVertex2f(car1+1495+500,535-5);
            glVertex2f(car1+1485+500,550-5);
            glVertex2f(car1+1400+500,550-5);
            glVertex2f(car1+1390+500,535-5);
            glEnd();
            glBegin(GL_POLYGON);
            if(night) glColor3f(0.3f, 0.0f, 0.0f);
            else glColor3f(1.0f, 0.0f, 0.0f);
            glVertex2f(car1+1420+500,550-5);
            glVertex2f(car1+1430+500,560-5);
            glVertex2f(car1+1465+500,560-5);
            glVertex2f(car1+1475+500,550-5);
            glEnd();
             glBegin(GL_POLYGON);
            if(night) glColor3f(0.7f, 1.0f, 0.9f);
            else glColor3f(0.4f, 0.5f, 0.8f);
            glVertex2f(car1+1422+500,550-5);
            glVertex2f(car1+1432+500,558-5);
            glVertex2f(car1+1463+500,558-5);
            glVertex2f(car1+1473+500,550-5);
            glEnd();
            glPushMatrix();
                glTranslatef(car1+1420+500, 535.0-5, 0.0);
                glBegin(GL_POLYGON);
                glColor3f(0.0f, 0.0f, 0.0f);
                for(int j=0;j<360;j++){
                    float pi=3.1416;
                    float A=(j*2*pi)/180;
                    float r=8;
                    float x = r * cos(A);
                    float y = r * sin(A);
                    glVertex2f(x,y);
                }
                glEnd();
            glPopMatrix();
             glPushMatrix();
                glTranslatef(car1+1475+500, 535.0-5, 0.0);
                glBegin(GL_POLYGON);
                glColor3f(0.0f, 0.0f, 0.0f);
                for(int j=0;j<360;j++){
                    float pi=3.1416;
                    float A=(j*2*pi)/180;
                    float r=8;
                    float x = r * cos(A);
                    float y = r * sin(A);
                    glVertex2f(x,y);
                }
                glEnd();
            glPopMatrix();

            //lighthouse light
            if(lighthouse){
                glPopMatrix();
                glBegin(GL_POLYGON);
                glColor4f(1.0f, 0.9f, 0.6f,0.2f);
                glVertex2f(1290,760);
                glVertex2f(1310,760);
                glVertex2f(light+1090,250);
                glVertex2f(light+910,250);
                glEnd();
                glPushMatrix();
                glTranslatef(light+1000, 250, 0.0);
                glBegin(GL_POLYGON);
                glColor4f(1.0f, 0.9f, 0.6f,0.6f);
                for(int j=0;j<360;j++){
                    float pi=3.1416;
                    float A=(j*2*pi)/180;
                    float r=90;
                    float x = r * cos(A);
                    float y = r * sin(A);
                    glVertex2f(x,y);
                }
                glEnd();
            }

    glutSwapBuffers();

}


void updateLightPosition() {
    light += step;
    if (light >= 300) {
        step = -2;
    }
    if (light <= 0) {
       step = 2;
    }
}
void update(int value){

        c1+=3;
        c2-=3;
        car+=5;
        car1-=6;
        if(car>1500) car=-200;
        if(car1<-2100) car1=600;
        if(c1>1500) c1=-275;
        if(c2<0) c2=1500;
        if(lighthouse){
            updateLightPosition();
        }

        if(active){
            ship+=3;
            if(speed){
                ship+=10;
            }
        }
        glutPostRedisplay();
        glutTimerFunc(20,update,0);


    }
    //keyboard
void handleKeyboard(unsigned char key, int x, int y) {

        if (key == 's') { // start
            active = true;
        }
        if (key == 'r') { // reset
            ship = 0;
            active = false;
            speed=false;
        }
        if (key == 'd') { // day
            night = false;
        }
        if (key == 'n') { // night
            night = true;
        }
        if(key=='l'){
            speed=true;
        }
    glutPostRedisplay();
}


//mouse
void mouse(int button, int state, int x, int y) {

        if(night){
            if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
                lighthouse=true;
            }
            else{
                lighthouse=false;
            }
        }

}


int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1500, 1000);
    glutInitWindowPosition(200, 0);
    glutCreateWindow("Maritime World Journey");
    glutDisplayFunc(display);
    glutTimerFunc(20, update, 0);
    glutKeyboardFunc(handleKeyboard);
    glutMouseFunc(mouse);
    cout<<"Start ship - press s"<<endl;
    cout<<"Night - press n"<<endl;
    cout<<"Day - press d"<<endl;
    cout<<"Increase ship speed - press l"<<endl;
    cout<<"To Reset - Press r"<<endl;
    glutMainLoop();

    return 0;
}
