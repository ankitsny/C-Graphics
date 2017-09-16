#include<stdio.h>
#include<dos.h>
#include<graphics.h>
#include<conio.h>
void main()
{
	char a;
	int gd=DETECT,gm,i,c=0;
	initgraph(&gd,&gm,"");
	 settextstyle(4,0,5);
	 outtextxy(230,100,"PIANO");
	 settextstyle(1,0,1);
	 rectangle(100,200,504,300);
	 for(i=0;i<8;i++)
	 {
	 rectangle(102+c,202,152+c,298);
	 c+=50;
	 }
	 outtextxy(120,242,"SA");
	 outtextxy(120,262,"Q");
	 outtextxy(170,242,"RE");
	 outtextxy(170,262,"W");
	 outtextxy(220,242,"GA");
	 outtextxy(220,262,"E");
	 outtextxy(270,242,"MA");
	 outtextxy(270,262,"R");
	 outtextxy(320,242,"PA");
	 outtextxy(320,262,"T");
	 outtextxy(362,242,"DHA");
	 outtextxy(362,262,"Y");
	 outtextxy(420,242,"NI");
	 outtextxy(420,262,"U");
	 outtextxy(470,242,"SA");
	 outtextxy(470,262,"I");
	 setfillstyle(1,1);

	 while(1)
{
	setfillstyle(1,1);
     a=getch();
     if(a!='x')
     {
     if(a=='q')//sa
     {
     floodfill(118,260,15);
     sound(240);
     delay(400);
     nosound();
     setfillstyle(1,0);
      floodfill(123,255,15);
     }
     else if(a=='w')//re
     {
     floodfill(168,260,15);

     sound(270);
     delay(400);
     nosound();
     setfillstyle(1,0);
     floodfill(168,260,15);
     }
     else if(a=='e')//ga
     {
     floodfill(218,260,15);
     sound(300);
     delay(400);
     nosound();
     setfillstyle(1,0);
     floodfill(218,260,15);
     }
     else if(a=='r')//ma
     {
     floodfill(268,260,15);
     sound(320);
     delay(400);
     nosound();
     setfillstyle(1,0);
     floodfill(268,260,15);

     }
     else if(a=='t')//pa
     {
     floodfill(318,260,15);
     sound(360);
     delay(400);
     nosound();
     setfillstyle(1,0);
     floodfill(318,260,15);
     }
     else if(a=='y')//dha
     {
     floodfill(368,245,15);
     sound(400);
     delay(400);
     nosound();
     setfillstyle(1,0);
     floodfill(368,245,15);
     }
     else if(a=='u')//ni
     {
      floodfill(418,260,15);
     sound(450);
     delay(400);
     nosound();
     setfillstyle(1,0);
     floodfill(418,260,15);
     }
     else if(a=='i')//sa
     {
     floodfill(468,260,15);
     sound(480);
     delay(400);
     nosound();
     setfillstyle(0,1);
     floodfill(468,260,15);
     }
     else
     {
      continue;
     }
     }
     else
     break;
}


	 getch();
}