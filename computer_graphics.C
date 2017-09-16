#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<string.h>
#include<stddef.h>
#include<math.h>
//#include "horowork.c"
//#include "firehis.c"



/***********************************************************************
******************GLOBAL_VARIABLES**************************************
***********************************************************************/
int ansrecord[4];	//to store the answer from user;
int index=0;		//loop variable(array)
void *m;
void *sun;
char a[20];

/***********************************************************************
*************************Function_Declaration***************************
***********************************************************************/
void first_page();
void fun_call();
void mainpage();
void question1();
void question2();
void question3(int[],int[],int[]);
void question4();
void check();

void admin_logout();
void getuser();
void mascot();
void mainpage();
void functioncall();
void study_zone();
void music_zone();
void art_zone();
void celestial_zone();
void solar();
void lunar();
//void horomain();
void animation_zone();
void optics();
void convex();
void concave();
void planemirror();
void maths();
void geometry();
void _2D();
void _3D();
void circal();
void ellip();
void parabola();
void series();

void bee();
void physics();
void laser();
void projectwork1();
void projectwork2();
void projectwork3();
void playnum();
void history();
void fire();
void fire_history();


void load_paint();
void paint();
void brush();
void dline();
void freehand();
void dcircle();
void fillcolor();
void eraser();
void setcolour(int,int);
void bubble();
void rectz();
int colorcode=8;
void *e;
void ipaint();


void mname();
void mnum();
void piano();

void ismile();
void icar();
void ibal();
/***************************/
//void input();
//void horo(int ,int);


/*********************************************************************
*************************MOUSE_FUN_DEF*********************************
***********************************************************************/
union REGS i, o;
int initmouse()
{
   i.x.ax = 0;
   int86(0X33,&i,&o);
   return ( o.x.ax );//return mouse availability
}
void hidemouse()
{
	i.x.ax=2;
	int86(0x33,&i,&o);
}
void hidemouseptr()
{
   i.x.ax = 2;
   int86(0X33,&i,&o);//hide mouse pointer
}

void showmouseptr()
{
   i.x.ax = 1;
   int86(0X33,&i,&o);//show mouse pointer
}

void getmousepos(int *button, int *x, int *y)
{
   i.x.ax = 3;
   int86(0X33,&i,&o);

   *button = o.x.bx;//save button status
   *x = o.x.cx;   //save x axis value
   *y = o.x.dx;  //save y axis value
}
void setmousepos(int *x,int *y)
{
	i.x.ax=4;
	i.x.cx=*x;
	i.x.dx=*y;
	int86(0x33,&i,&o);
}
/***************************************************************************
*************************************MOUSE END******************************/
/******************************MAIN FUNC EXECUTION STARTS HERE***************
**************************************************************************/
void main()
{
       //	int gd=DETECT,gm,errorcode;
       //	initgraph(&gd,&gm,"");
	mascot();
	/********draws user page************/
	getuser();
	/*******************draws main page*******/
	mainpage();
	getch();

}



/****************************************************************************
*****************************Admin_logout************************************
****************************************************************************/
void admin_logout()
{
	int i;
	char pass[5],d_pass[5];
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"");

	cleardevice();
	setbkcolor(0);
	settextstyle(0,0,1);
	outtextxy(280,10,"Admin logout");
	outtextxy(10,50,"Enter PIN:-");
	strcpy(d_pass,"1234");	//Set_default_password
	gotoxy(5,5);
	for(i=0;i<4;i++)
	{

		pass[i]=getch();
		printf("*");

	}
	pass[i]=NULL;
	if(strcmp(pass,d_pass)==0)
	{
		printf("\nLogged out");
		printf("\nPress any key...");
		getch();
	}
	else
	{
		printf("\nIncorrect PIN!!!");
		printf("\nPress any key...");
		getch();
		closegraph();
		mainpage();
	}
}


/***************************************************************************
*************DRAWS_AND_SAVES_THE_MASCOT_MUST_CALL_AT_FIRST_AT_MAIN()********
****************************************************************************/
void mascot()
{
	unsigned int size;
	int poly[10]={80,140,45,90,55,90,80,120,80,140};
       int gdriver=DETECT,gmode,errorcode,i;
	initgraph(&gdriver,&gmode,"");
	setfillstyle(1,7);
	circle(100,100,20);
	floodfill(100,100,15);
	rectangle(80,120,120,180);//body    /****DRAWS MASCOT****/
	rectangle(80,180,95,220);//leg1
	rectangle(105,180,120,220);//leg2
	circle(90,95,2);//eye1
	circle(110,95,2);//eye2
	setfillstyle(1,0);//eyestyle
	floodfill(90,95,15);//filleye
	floodfill(110,95,15);
	rectangle(95,110,105,114);
	floodfill(103,112,15);//mouth
	setfillstyle(1,4);
	floodfill(85,140,15);//bodyfill
	setfillstyle(1,7);
	floodfill(90,200,15);
	floodfill(110,200,15);
	fillpoly(5,poly);
	rectangle(120,124,130,180);
	floodfill(125,130,15);
	size=imagesize(30,60,170,230);
	m=malloc(size);
	getimage(30,60,170,230,m);
	cleardevice();
	rectangle(8,8,getmaxx()-8,getmaxy()-8);
	closegraph();

}


/****************************************************************************
***********************GET_USER_START_PAGE_TAKES_USER_NAME*******************
*****************************************************************************/
void getuser()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"");
	cleardevice();
	setbkcolor(0);
	rectangle(200+10,200,400+10,250);
	setfillstyle(1,4);
	putimage(400,300,m,0);
	setfillstyle(1,1);
	fillellipse(520,280,70,30);
	outtextxy(472,265,"Welcome to");         /*******USER INFO******/
	outtextxy(465,275,"the World of");
	outtextxy(468,290,"\"ENTRIMENTO\"");
	floodfill(300,230,15);
	gotoxy(33,15);
	settextstyle(SCRIPT_FONT,0,1);
	outtextxy(100,200,"Enter Your");
	outtextxy(100,220,"Name");
	scanf("%s",&a);
	delay(1000);
	closegraph();
}
/****************************************************************************
************************MAIN PAGE-STUDY,GAME,ANIMATION,ETC*******************
*************************************************************************/
void mainpage()
{
       int gd=DETECT,gm;
	initgraph(&gd,&gm,"");
	cleardevice();
	setbkcolor(0);
	setfillstyle(1,0);             //background colour
	rectangle(3,3,getmaxx()-3,getmaxy()-3);	//border
	floodfill(4,50,15);
	settextstyle(BOLD_FONT,0,1);   //font
	setfillstyle(1,1);              //tile's colour
	rectangle(30,60,200,150);	//Ist tile
	floodfill(140,100,15);
	outtextxy(40,80,"Study Zone");
	rectangle(450,60,620,150);	//IInd tile
	floodfill(500,100,15);
	outtextxy(490,60,"Art");
	outtextxy(490,100,"Zone");
	rectangle(240,182,410,272);	//mid tile
	floodfill(300,200,15);
	outtextxy(247,200,"Music Zone");
	rectangle(30,300,200,390);     //IIIrd tile
	floodfill(140,350,15);
	outtextxy(40,300,"Animation");
	outtextxy(70,340,"Zone");
	rectangle(450,300,620,390);   //IVth tile
	floodfill(500,350,15);
	outtextxy(465,300,"Celestial");
	outtextxy(490,340,"Zone");
	rectangle(610,10,630,25);   //close tab
	rectangle(560,440,635,475); //admin log out
	settextstyle(0,0,1);
	outtextxy(565,445,"Admin");
	setfillstyle(1,4);
	floodfill(610,445,15);
	floodfill(613,20,15);
	line(610,10,630,25);
	line(610,25,630,10);
	putimage(240,300,m,0);
	setfillstyle(1,4);
	fillellipse(392,325,50,30);
	settextstyle(0,0,1);
	outtextxy(370,317,"Hi");
	outtextxy(390,317,a);
	outtextxy(350,330,"Choose Zone");
	showmouseptr();
	functioncall();


}
/****************************************************************************
*********************************MOUSE CALL FUNCTION FOR MAIN PAGE***********
***************************************************************************/
void functioncall()
{
	int button,x,y;
	int a=100,b=100;
	setmousepos(&a,&b);
	while(1)
	{
		getmousepos(&button,&x,&y);
		if(button==1)
		{
			if(((x>30)&&(y>60))&&((x<200)&&(y<150)))
				{
					sound(650);
					delay(300);
					nosound();
					hidemouse();
					closegraph();
					study_zone();
					break;
				}
			else
				if(((x>450)&&(y>60))&&((x<620)&&(y<150)))
				{
					sound(650);
					delay(300);
					nosound();
					hidemouse();
					closegraph();
					art_zone();
					break;
				}
			else
				if(((x>240)&&(y>182))&&((x<410)&&(y<272)))
				{
					sound(650);
					delay(300);
					nosound();
					hidemouse();
					closegraph();
					music_zone();
					break;
				}
			else
				if(((x>30)&&(y>300))&&((x<200)&&(y<390)))
				{
					sound(650);
					delay(300);
					nosound();
					hidemouse();
					closegraph();
					animation_zone();
					break;
				}
			else
				if(((x>450)&&(y>300))&&((x<620)&&(y<390)))
				{
					sound(650);
					delay(300);
					nosound();
					hidemouse();
					closegraph();
					celestial_zone();
					break;
				}
			else
				if(((x>610)&&(y>3))&&((x<630)&&(y<20)))
				{
					button=0;
					cleardevice();
					hidemouse();
					getuser();
					closegraph();
					mainpage();
					break;
				}

			else
				if(((x>560)&&(x<635))&&((y>440)&&(y<475)))
				{
					hidemouse();
					closegraph();
					admin_logout();
					break;
				}

		} //end of click_check;
	 }   //End of while loop;

}  //End of functioncall();

/**************************************************************************
*************STUDY ZONE OF MAIN PAGE****************************************
******************************************************************************/
void study_zone()
{
	int gd=DETECT,gm;
	int button,x,y;
	int a=100,b=100;
	initgraph(&gd,&gm,"");
	cleardevice();
	setbkcolor(12);
	rectangle(8,8,getmaxx()-8,getmaxy()-8);
	rectangle(175,52,450,130);
	setfillstyle(1,1);
	floodfill(200,100,15);
	settextstyle(GOTHIC_FONT,0,5);

	outtextxy(210,60,"Study Zone");
	settextstyle(GOTHIC_FONT,0,5);
	outtextxy(210,60,"Study Zone");
	rectangle(80,170,300,210);
	settextstyle(TRIPLEX_FONT,0,3);
	outtextxy(90,180,"Mathematics");
	rectangle(80,250,300,290);
	outtextxy(90,260,"Optics");
	rectangle(80,330,300,370);
	outtextxy(90,340,"History");
	rectangle(80,410,300,450);
	outtextxy(90,420,"Basic Electrical");
	rectangle(330,170,550,210);
	outtextxy(340,180,"Physics");
	settextstyle(0,0,1);
	rectangle(500,440,550,465);
	outtextxy(510,449,"BACK");
	showmouseptr();
	setmousepos(&a,&b);
	while(1)
	{
		getmousepos(&button,&x,&y);
		if(button==1)
		{
			if((x>80)&&(x<300)&&(y>=250)&&(y<=290))//optics
			{
				sound(650);
				delay(300);
				nosound();
				cleardevice();
				setbkcolor(0);
				hidemouse();
				closegraph();
				optics();
				break;
			}
			else
			if((x>80)&&(x<300)&&(y>=170)&&(y<=210))//maths
			{
				sound(650);
				delay(300);
				nosound();
				hidemouse();
				closegraph();
				maths();
				break;
			}
			else
			if(x>80&&x<300&&y>410&&y<450)//bee
			{
				sound(650);
				delay(300);
				nosound();
				hidemouse();
				closegraph();
				bee();
				break;
			}
			else if(x>500&&x<550&&y>440&&y<465)//mainpage
			{
				sound(650);
				delay(300);
				nosound();
				hidemouse();
				cleardevice();
				setbkcolor(0);
				closegraph();
				mainpage();
				break;
			}
			else if(x>330&&x<550&&y>170&&y<210)//physics
			{
				sound(650);
				delay(300);
				nosound();
				hidemouse();
				cleardevice();
				setbkcolor(0);
				closegraph();
				physics();
				break;
			}
			else if(x>80&&x<300&&y>330&&y<370)
			{
				sound(650);
				delay(300);
				nosound();
				hidemouse();
				cleardevice();
				setbkcolor(0);
				closegraph();
				history();
				break;
			}

		 }//check button close
	}//while end


}

/*********************************************************/

/***********************gamingzone************************/
void art_zone()
{
	//cleardevice();
	int gd=DETECT,gm;
	int x,y,button,loop=1;
	initgraph(&gd,&gm,"");
	cleardevice();
	rectangle(2,2,638,478);
	rectangle(8,8,632,472);
	setfillstyle(1,1);
	floodfill(3,3,15);
	rectangle(250,200,370,240); //continue tab
	floodfill(252,205,15);
	settextstyle(TRIPLEX_FONT,0,4);
	outtextxy(215,50,"Sketch Board");
	settextstyle(TRIPLEX_FONT,0,1);
	outtextxy(270,210,"Continue");
	showmouseptr();
	while(loop)
	{
		getmousepos(&button,&x,&y);
		if(button==1)
		{
			if(x>250&&x<370&&y>200&&y<240)
			{
				hidemouse();
				loop=0;
				closegraph();
				load_paint();
				break;
			}
		}
	}
}

void load_paint()
{
	int loop=1,x,y,i;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"");
	cleardevice();

	rectangle(2,2,638,478);
	rectangle(8,8,632,472);
	setfillstyle(1,1);
	floodfill(3,3,15);
	rectangle(120,200,530,250);
	settextstyle(TRIPLEX_FONT,0,2);
	outtextxy(215,70,"Loading Please Wait!!!");
	for(x=125;x<=515;x+=10)
	{

		rectangle(x,205,x+10,245);
		setfillstyle(1,2);
		floodfill(x+2,207,15);
		x+=5;
		delay(20);
	}
	delay(300);
	cleardevice();
	closegraph();
	ipaint();
}
void ipaint()
{
	int i=1,x,y,flag=0;
	int button,x1,y1;
	int size[4];

	int gd=DETECT,gm;
	unsigned int size1;
       initgraph(&gd,&gm,"");
	setbkcolor(0);
	setcolor(8);
	rectangle(10,10,505,473);	//painting zone
	rectangle(2,2,638,478);		//outer most border
	setfillstyle(1,7);
	floodfill(3,3,8);
	rectangle(512,25,632,115);      //color panel's outline

	rectangle(620,460,635,475);	//close tab
	setfillstyle(1,4);
	floodfill(621,461,8);
       setcolor(1);
       line(620,460,635,475);
       line(635,460,620,475);

	rectangle(510,460,600,475);     //select tool tab
	setcolor(8);
	settextstyle(0,0,1);
	outtextxy(513,465,"Select Tool");
	setcolor(8);

	for(x=512;x<620;x+=30)         //color tabs
	{
		for(y=25;y<100;y+=30)
		{
			rectangle(x,y,x+30,y+30);
		}
	}

	for(x=515;x<620;x+=30)		//color palet
	{
		for(y=27;y<100;y+=30)
		{
			setfillstyle(1,i);
			floodfill(x,y,8);
			i++;
		}
	}
	settextstyle(0,0,1);
	outtextxy(512,15,"color palet");
	outtextxy(512,132,"Drawing Tools");
	for(x=515;x<620;x+=60)
	{
		for(y=145;y<220;y+=30)
		{
			rectangle(x,y,x+60,y+30);
		}
	}

	//**************Magical pattern****************
	outtextxy(515,255,"Magical Pattern");
	rectangle(515,265,575,295);
	outtextxy(518,275,"Rectz");
	rectangle(575,265,635,295);
	outtextxy(578,275,"bubbles");


	line(530,165,560,155); //pencil
	line(533,168,561,158);
	line(560,155,561,158);
	line(530,165,525,170);
	line(533,168,525,170);

	rectangle(595,160,615,170);//brush
	rectangle(603,150,607,160);

	rectangle(540,185,555,200);
	arc(534,190,45,180,7);      //spray
	arc(538,190,45,180,7);

	rectangle(590,180,620,195);
	rectangle(580,185,610,200);
	line(590,180,580,185);
	line(610,185,620,180);
	line(580,200,590,195);
	line(610,200,620,195);

	line(525,228,560,210); //line

	circle(605,220,10);  //circle

	rectangle(545,325,605,355);
	outtextxy(553,335,"Clear");

	setbkcolor(0);
	size1=imagesize(7,7,14,14);
	e=malloc(size1);
	getimage(14,14,28,28,e);
	//getch();
       showmouseptr();
       while(1)
       {
		getmousepos(&button,&x,&y);
		if(button==1)
		{
		       if(x>515&&x<575&&y>145&&y<175)//draw with pencil
		       {
				freehand();

		       }
		      else if(x>575&&x<635&&y>145&&y<175)//paint with brush
		       {
			       brush();

		       }
		       else if(x>515&&x<575&&y>175&&y<205)//fill color
		       {
				fillcolor();
		       }
		       else if(x>575&&x<635&&y>175&&y<205)//eraser
		       {
				 eraser();
		       }
		       else if(x>515&&x<575&&y>205&&y<235)
		       {
				dline();
		       }
		       else if(x>575&&x<635&&y>205&&y<235)
		       {
				dcircle();
		       }
		       else if(x>515&&x<575&&y>265&&y<295)
				rectz();
		       else if(x>575&&x<635&&y>265&&y<295)
				bubble();
		       else if(x>545,x<605&&y>325&&y<355)
		       {
				hidemouse();
				cleardevice();
				closegraph();
				ipaint();
				break;
		       }
		       else if(x>620&&x<635&&y>460&&y<475)
		       {
				 button=0;
				 cleardevice();
				 setbkcolor(0);
				 closegraph();
				 mainpage();
				 break;
		       }
		}
      }
}


/**************************************************************************
***************************************************************************
***************************FREE HAND***************************************
**************************************************************************
***************************************************************************/
void freehand()
{
	int button,x,y,prevx,prevy;
	while(1)
	{
		getmousepos(&button,&x,&y);
		if(button==1)
		{      setcolour(x,y);
		       setcolor(colorcode);
			if(x>10&&x<505&&y>10&&y<473)
			{
				hidemouse();
				prevx=x;
				prevy=y;
				while(button==1)
				{

				    line(prevx,prevy,x,y);
				    prevx=x;
				    prevy=y;

				    getmousepos(&button,&x,&y);
				    if((x<10 || x>510) || (y>473 || y<10))
				    break;
				}
				showmouseptr();
			}
		      else if(x>510&&x<600&&y>460&&y<475)
			{
				/*save*
				break*/
				break;
			}
		  /*	 else if(x>620&&x<635&&y>460&&y<475)
		       {
				 button=0;
				 cleardevice();
				 setbkcolor(0);
				 mainpage();
				 break;
		       }*/
		}//end        of main if
	 }
}//end of freehand
/**************************************************************************
*********************************brush********************************
***********************************************************************/
void brush()
{
     int button,x,y,prevx,prevy;
	while(1)
	{
		getmousepos(&button,&x,&y);
		if(button==1)
		{      setcolour(x,y);
		       setcolor(colorcode);
			if(x>10&&x<505&&y>10&&y<473)
			{
				hidemouse();
				prevx=x;
				prevy=y;
				while(button==1)
				{

				   // rectangle(prevx,prevy,x,y);
				    line(prevx+1,prevy+1,x+1,y+1);
				    line(prevx,prevy,x,y);
				    line(prevx-1,prevy-1,x-1,y-1);
				    line(prevx+2,prevy+2,x+2,y+2);
				    line(prevx-2,prevy-2,x-2,y-2);
				    line(prevx+3,prevy+3,x+2,y+2);
				    line(prevx-3,prevy-3,x-2,y-2);
				    prevx=x;
				    prevy=y;

				    getmousepos(&button,&x,&y);
				    if((x<20 || x>490) || (y>468 || y<15))
				    break;
				}
				showmouseptr();
			}
		      else if(x>510&&x<600&&y>460&&y<475)
			{
				/*save*
				break*/
				break;
			}
		      /*	 else if(x>620&&x<635&&y>460&&y<475)
		       {
				 button=0;
				 cleardevice();
				 setbkcolor(0);
				 mainpage();
				 break;
		       }*/
		}//end        of main if
	 }



}
/**************************************************************************
********************************fillcolor********************************
************************************************************************/
void fillcolor()
{
       int button,x,y,prevx,prevy,j;
	while(1)
	{
		getmousepos(&button,&x,&y);
		if(button==1)
		{      setcolour(x,y);
		       setcolor(colorcode);
			if(x>10&&x<495&&y>15&&y<453)
			{
				hidemouse();
				prevx=x;
				prevy=y;
				while(button==1)
				{
				    setcolor(colorcode);
				    for(j=0;j<10;j+=3)
				    {
				    putpixel(x+j,y-j,colorcode);
				    putpixel(x-j,y+j,colorcode);
				    putpixel(x+j,y+j,colorcode);
				    putpixel(x-j,y-j,colorcode);
				    putpixel(x,y+j,colorcode);
				    putpixel(x,y-j,colorcode);
				    }
				   /* putpixel(2*3.14*(x+2),2*3.14*(y+2),colorcode);
				    putpixel(2*3.14*(x-1),2*3.14*(y-1),colorcode);
				    putpixel(2*3.14*(x-1),2*3.14*(y-2),colorcode);*/


				    prevx=x;
				    prevy=y;

				    getmousepos(&button,&x,&y);
				    if((x<20 || x>480) || (y>460 || y<25))
				    break;
				}
				showmouseptr();
			}
		      else if(x>510&&x<600&&y>460&&y<475)
			{
				/*save*
				break*/
				break;
			}
		  /*	 else if(x>620&&x<635&&y>460&&y<475)
		       {
				 button=0;
				 cleardevice();
				 setbkcolor(0);
				 mainpage();
				 break;
		       }*/
		}//end        of main if
	 }



       //	cleardevice();

}
/***************************************************************************
***************************eraser*******************************************
************************************************************************/
void eraser()
{

	int button,x,y,prevx,prevy;
	while(1)
	{       showmouseptr();
		getmousepos(&button,&x,&y);
		if(button==1)
		{      setcolour(x,y);
		       setcolor(colorcode);
			if(x>25&&x<505&&y>30&&y<473)
			{
				hidemouse();
				prevx=x;
				prevy=y;
				while(button==1)
				{
				    hidemouse();
				    putimage(prevx-15,prevy-15,e,0);
				    showmouseptr();
				    prevx=x;
				    prevy=y;

				    getmousepos(&button,&x,&y);
				    if((prevx<100 || prevy<100))
					break;
				    if(x>480 || y>380)
					break;
				}
				showmouseptr();
			}
		      else if(x>510&&x<600&&y>460&&y<475)
			{
				/*save*
				break*/
				break;
			}
			/* else if(x>620&&x<635&&y>460&&y<475)
		       {
				 button=0;
				 cleardevice();
				 setbkcolor(0);
				 mainpage;
				 break;
		       }  */
		}//end        of main if
	 }




}
/*************************************************************************
**************************DRAW RECTANGLE**********************************
**************************************************************************/
void dline()
{
int button,x,y,prevx,prevy;
	while(1)
	{
		getmousepos(&button,&x,&y);
		if(button==1)
		{      setcolour(x,y);
		       setcolor(colorcode);
			if(x>20&&x<490&&y>20&&y<468)
			{
				hidemouse();
				prevx=x;
				prevy=y;
				while(button==1)
				{

				   // line(prevx,prevy,x,y);
				   // prevx=x;
				    //prevy=y;

				    getmousepos(&button,&x,&y);

				    if((x<20||y<10)||(y>473 || x>500))
				    {

				    break;

				    }

				}
				if(!((x<10||y<5)||(y>473 || x>505)))
				 line(prevx,prevy,x,y);
				showmouseptr();
			}
		      else if(x>510&&x<600&&y>460&&y<475)
			{
				/*save*
				break*/
				break;
			}
		     /**	 else if(x>620&&x<635&&y>460&&y<475)
		       {
				 button=0;
				 cleardevice();
				 mainpage;
				 break;
		       }*/
		}//end        of main if

	       }


}
/*************************************************************************
**************************DRAW CIRCLE**************************************
***************************************************************************/
void dcircle()
{
	int button,x,y,prevx,prevy,d;
	while(1)
	{
		getmousepos(&button,&x,&y);
		if(button==1)
		{      setcolour(x,y);
		       setcolor(colorcode);
			if(x>10&&x<505&&y>10&&y<473)
			{
				hidemouse();
				prevx=x;
				prevy=y;
				while(button==1)
				{
				    getmousepos(&button,&x,&y);
				    if((x<10 || x>510) || (y>473 || y<10))
				    break;
				}

					if(!((x+2*d<10||y+2*d<5)||(y+2*d>473 || x+2*d>505)))
					{
					//hidemouse();
					d=sqrt(pow((x-prevx),2)+pow((y-prevy),2));

					circle(prevx,prevy,d);
					}
				showmouseptr();
			}
		      else if(x>510&&x<600&&y>460&&y<475)
			{
				/*save*
				break*/
				break;
			}
			/* else if(x>620&&x<635&&y>460&&y<475)
		       {
				 button=0;
				 cleardevice();
				 mainpage();
				 break;
		       }  */
		}//end        of main if
	 }
}

void rectz()
{
    int button,x,y,prevx,prevy;
	while(1)
	{
		getmousepos(&button,&x,&y);
		if(button==1)
		{      setcolour(x,y);
		       setcolor(colorcode);
			if(x>10&&x<505&&y>10&&y<473)
			{
				hidemouse();
				prevx=x;
				prevy=y;
				while(button==1)
				{

				    rectangle(prevx,prevy,x,y);
				    prevx=x;
				    prevy=y;

				    getmousepos(&button,&x,&y);
				    if((x<10 || x>510) || (y>473 || y<10))
				    break;
				}
				showmouseptr();
			}
		      else if(x>510&&x<600&&y>460&&y<475)
			{
				/*save*
				break*/
				break;
			}
			/* else if(x>620&&x<635&&y>460&&y<475)
		       {
				 button=0;
				 cleardevice();
				 mainpage();
				 break;
		       }  */
		}//end        of main if
	 }


}

void bubble()
{

	int button,x,y,prevx,prevy,d,r;
	randomize();
	while(1)
	{
		getmousepos(&button,&x,&y);
		if(button==1)
		{      setcolour(x,y);
		       setcolor(colorcode);
			if(x>10&&x<505&&y>10&&y<473)
			{
				hidemouse();
				prevx=x;
				prevy=y;
				r=random(10);
				while(button==1)
				{
				    getmousepos(&button,&x,&y);
				    if((x<10 || x>510) || (y>473 || y<10))
				    break;

					if(!((x+2*d<10||y+2*d<5)||(y+2*d>473 || x+2*d>505)))
					{
					//hidemouse();
				       //	d=sqrt(pow((x-prevx),2)+pow((y-prevy),2));

					circle(x,y,random(20));
					delay(40);
					}

				}

				  /*	if(!((x+2*d<10||y+2*d<5)||(y+2*d>473 || x+2*d>505)))
					{
					//hidemouse();
					d=sqrt(pow((x-prevx),2)+pow((y-prevy),2));

					circle(prevx,prevy,d);
					}     */
				showmouseptr();
			}
		      else if(x>510&&x<600&&y>460&&y<475)
			{
				/*save*
				break*/
				break;
			}
		      /*	 else if(x>620&&x<635&&y>460&&y<475)
		       {
				 button=0;
				 cleardevice();
				 mainpage();
				 break;
		       }*/
		}//end        of main if
	 }


}


void setcolour(int x,int y)
{
   if(x>512&&x<542&&y>25&&y<55)
    colorcode=1;
   else if(x>542&&x<572&&y>25&&y<55)
   colorcode=4;
    else if(x>572&&x<602&&y>25&&y<55)
   colorcode=7;
    else if(x>602&&x<632&&y>25&&y<55)
   colorcode=10;

    else if(x>512&&x<542&&y>55&&y<85)
   colorcode=2;
    else if(x>542&&x<572&&y>55&&y<85)
   colorcode=5;
    else if(x>572&&x<602&&y>55&&y<85)
   colorcode=8;
    else if(x>602&&x<632&&y>55&&y<85)
   colorcode=11;

    else if(x>512&&x<542&&y>85&&y<115)
   colorcode=3;
    else if(x>542&&x<572&&y>85&&y<115)
   colorcode=6;
    else if(x>572&&x<602&y>85&&y<115)
   colorcode=9;
   else if(x>602&&x<632&&y>85&&y<115)
   colorcode=12;
}
/***************************************************************************
******************************End_of_Paint**********************************
****************************************************************************


/********************************************************/

/**********************musiczone*************************/
void music_zone()
{
	int button,x,y;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"");
	cleardevice();
	rectangle(8,8,getmaxx()-8,getmaxy()-8);
	rectangle(10,10,getmaxx()-10,getmaxy()-10);
	setcolor(12);
	settextstyle(GOTHIC_FONT,0,5);
	outtextxy(180,40,"MUSIC ZONE");
	setcolor(14);
	settextstyle(SANS_SERIF_FONT,0,1);
	outtextxy(150,100,"Now lets do something with Music....");
	outtextxy(170,120,"Select any of the following....");
	setcolor(1);
	rectangle(200,200,400,240);//music with names
	rectangle(200,260,400,300);//music with numbers
	rectangle(200,320,400,360);//music piano
	setcolor(10);
	outtextxy(213,207,"MUSIC WITH NAMES");

	outtextxy(210,267,"MUSIC WITH NUMBERS");
	outtextxy(210,327,"   8 NODE PIANO");
	setcolor(15);
	settextstyle(0,0,1);
	rectangle(500,440,550,465);
	outtextxy(510,449,"BACK");
	showmouseptr();
	while(1)
	{
		getmousepos(&button,&x,&y);
		if(button==1)
		{
			if(x>200&&x<400&&y>200&&y<240)//music with names
			{
				sound(650);
				delay(400);
				nosound();
				hidemouse();

				cleardevice();
				setbkcolor(0);
				closegraph();
				mname();
				break;
			}
		       else	if(x>200&&x<400&&y>260&&y<300)//music with numbers
			{
				sound(650);
				delay(400);
				nosound();
				hidemouse();
				cleardevice();
				setbkcolor(0);
				closegraph();
				mnum();
				break;
			}
		       else	if(x>200&&x<400&&y>320&&y<360)//piano
		       {
				sound(650);
				delay(400);
				nosound();
				hidemouse();
				cleardevice();
				setbkcolor(0);
				closegraph();
				piano();
				break;
		       }
		       else if(x>500&&x<550&&y>440&&y<465)//back button
		       {
				sound(650);
				delay(400);
				nosound();
				hidemouse();
				cleardevice();
				setbkcolor(0);
				closegraph();
				mainpage();
				break;
		       }

		}

	}



}

/********************************************************/


/*************************celestialzone******************/
void celestial_zone()
{
	int gm=DETECT,gd;
	int button,x,y;
	initgraph(&gm,&gd,"");
	rectangle(8,8,getmaxx()-8,getmaxy()-8);
	rectangle(10,10,getmaxx()-10,getmaxy()-10);
	setcolor(2);
	settextstyle(GOTHIC_FONT,0,5);
	outtextxy(160,40,"Celestial Zone");
	setcolor(5);
	settextstyle(SANS_SERIF_FONT,0,1);
	outtextxy(160,100,"Lets know about the planetary bodies...");
	outtextxy(180,120,"Know about yourself..");
	setcolor(14);
	rectangle(200,200,400,240);
	rectangle(200,260,400,300);
	rectangle(200,320,400,360);
	setcolor(10);
	outtextxy(213,207," HOROSCOPE");
	outtextxy(210,267," SOLAR ECLIPSE");
	outtextxy(210,327," LUNAR ECLIPSE");
	setcolor(15);
	settextstyle(0,0,1);
	rectangle(500,440,550,465);
	outtextxy(510,449,"BACK");
	showmouseptr();
	while(1)
	{
		getmousepos(&button,&x,&y);
		if(button==1)
		{
			if(x>200&&x<400&&y>200&&y<240)
			{
				cleardevice();
				setbkcolor(0);
				hidemouse();
				closegraph();
			     ///	horomain();
				break;
			}
			else if(x>200&&x<400&&y>260&&y<300)
			{
				cleardevice();
				setbkcolor(0);
				hidemouse();
				closegraph();
			      ///	solar();
				break;
			}
			else if(x>200&&x<400&&y>320&&y<360)
			{
				cleardevice();
				setbkcolor(0);
				hidemouse();
				closegraph();
			       //	lunar();
				break;
			}
			else if(x>500&&x<550&&y>440&&y<465)
			{
				cleardevice();
				setbkcolor(0);
				hidemouse();
				closegraph();
				mainpage();
				break;
			}

		}
	}


	getch();
}
/*******************************************************/
/*void solar()
{
	int i;
	for(i=0;i<=385;i++)
	{
	   //
	  if(i%3==0)
	   cleardevice();
	       delay(20);
	       setcolor(3);
	setfillstyle(1,14);
	circle(140,getmaxy()/2-20,80);       //sun
	floodfill(150,getmaxy()/2-20,3);
	setfillstyle(1,11);
	circle(520,getmaxy()/2-14,55);      //earth
	floodfill(520,getmaxy()/2-14,3);
	setfillstyle(1,1);
	circle(409,getmaxy()/2-13,13);      //moon
	floodfill(409,getmaxy()/2-13,3);
	settextstyle(SANS_SERIF_FONT,0,2);
	outtextxy(120,getmaxy()/2-30,"Sun");
	outtextxy(495,getmaxy()/2-23,"Earth");
	outtextxy(400,getmaxy()/2+2,"Moon");
	line(152,getmaxy()/2+60,i+100,getmaxy()/2-57-385+i); //lower upper
	line(150,getmaxy()/2+60,i+80,getmaxy()/2-10-385+i);//lower lowwer
	line(160,getmaxy()/2-99,i+123,getmaxy()/2+38+389-i); //upper lower
	line(160,getmaxy()/2-99,i+83,getmaxy()/2-10+385-i);//upper upper
       }
       { cleardevice();
       setfillstyle(1,14);
       circle(140,getmaxy()/2-20,80);
	floodfill(150,getmaxy()/2-20,3);  //sun
       setfillstyle(1,11);
       circle(520,getmaxy()/2-14,55);   //earth
       floodfill(520,getmaxy()/2-14,3);
       setfillstyle(1,1);
	circle(409,getmaxy()/2-13,13);      //moon
	floodfill(409,getmaxy()/2-13,3);
	line(152,getmaxy()/2+60,485,getmaxy()/2-57); //lower upper
	line(150,getmaxy()/2+60,465,getmaxy()/2-10);//lower lowwer
	line(160,getmaxy()/2-99,500,getmaxy()/2+38); //upper lower
	line(160,getmaxy()/2-99,468,getmaxy()/2-10);//upper upper
	outtextxy(120,getmaxy()/2-30,"Sun");
	outtextxy(495,getmaxy()/2-23,"Earth");
	outtextxy(400,getmaxy()/2+2,"Moon");
	}
	{         delay(200);
	 setfillstyle(1,8);
	 floodfill(425,getmaxy()/2-13,3);
	 setfillstyle(1,7);
	 floodfill(425,getmaxy()/2-33,3);
	 floodfill(425,getmaxy()/2,3);
	 setcolor(15);
	 settextstyle(SANS_SERIF_FONT,0,2);
	 outtextxy(450,70,"Penumbra");
	 line(460,90,430,getmaxy()/2-30);
	 outtextxy(450,getmaxy()-150,"Umbra");
	 line(455,getmaxy()-140,450,getmaxy()/2-12);
	  delay(20);
	  setcolor(1);
	 settextstyle(TRIPLEX_FONT,0,4);
	 outtextxy(0,getmaxy()-130,"The Geometry of Solar Eclipse");
	 settextstyle(0,0,1);



       }
       outtextxy(20,450,"PRESS X TO GO BACK");
       X:	if(getch()!='x')
		goto X;
		closegraph();
		celestial_zone();
}
/********************************************************/
/*void lunar()
{
	int gd=DETECT,gm,i;
	int size;
	initgraph(&gd,&gm,"");
	setfillstyle(1,14);
	circle(150,getmaxy()/2-20,80);       //sun
	floodfill(150,getmaxy()/2-20,15);
	size=imagesize(70,139,230,299);
	sun=malloc(size);
	getimage(70,139,230,299,sun);
	circle(380,getmaxy()/2-14,36);      //earth
	circle(520,getmaxy()/2-9,10);      //moon
	for(i=0;i<500;i++)
	{
	cleardevice();

	 setcolor(15);
	 putimage(70,139,sun,0);
     //circle(150,getmaxy()/2-20,80);       //sun
       setcolor(3) ;
	circle(380,getmaxy()/2-14,36);
	setfillstyle(1,11);
	floodfill(380,getmaxy()/2-14,3);     //earth
	setfillstyle(1,9);
	circle(520,getmaxy()/2-9,10);      //moon
	floodfill(520,getmaxy()/2-9,3);

	setcolor(3);

	line(150,getmaxy()/2+60,100+i,getmaxy()/2+510-i-20); //lower stm
	line(150,getmaxy()/2-100,100+i,getmaxy()/2-503+i);//upper stm
	line(173,getmaxy()/2+60,230+i,getmaxy()/2-750+i); //lower ste
	line(173,getmaxy()/2-100,230+i,getmaxy()/2+740-i);//upper ste
	settextstyle(SANS_SERIF_FONT,0,2);
	outtextxy(130,getmaxy()/2-40,"Sun");
	outtextxy(355,getmaxy()/2-30,"Earth");
	outtextxy(500,getmaxy()/2+10,"Moon");
	delay(20);
   //	setfillstyle(0,1);
     //	floodfill(460,getmaxy()/2,15);
    }
    delay(100);
    line(230+365,getmaxy()/2-176,230+365,getmaxy()/2+165);
    setfillstyle(1,7);
    floodfill(520,getmaxy()/2-25,3);
    floodfill(520,getmaxy()/2+40,3);
    floodfill(520,getmaxy()/2+25,3);
    floodfill(527,getmaxy()/2+25,3);
    setfillstyle(1,8);
    floodfill(430,getmaxy()/2,3);
    settextstyle(SANS_SERIF_FONT,0,1);
    setcolor(15);
    delay(100);
    outtextxy(400,60,"Umbral Shadow ");
    line(430,90,430,getmaxy()/2-10);
    delay(100);
    outtextxy(450,getmaxy()/2+40,"Penumbral Shadow");
    setcolor(1);
    settextstyle(TRIPLEX_FONT,0,4);
    outtextxy(0,getmaxy()-130,"The Geometry of Lunar Eclipse");
      X: if(getch()!='x')
       goto X;
       closegraph();
       celestial_zone();
}*/
/********************************************************************
************************************************************************
*******************************HOROSCOPE*********************************
*******************************************************************/
//void horomain()
//{



/*for taking date and month*/
/*	int gm=DETECT,gd;
	initgraph(&gm,&gd,"");
	setcolor(12);
	settextstyle(BOLD_FONT,0,4);
	outtextxy(200,40,"Horoscope");
	settextstyle(SANS_SERIF_FONT,0,2);
	setcolor(2);
	outtextxy(50,165,"Enter your date of Birth");
	rectangle(120,200,190,225);
	outtextxy(50,245,"Enter your month of Birth");
	rectangle(120,280,190,305);
	setcolor(14);
	settextstyle(SANS_SERIF_FONT,0,1);
	outtextxy(0,getmaxy()-50,"NOTE: Donot enter a character or the program will abort permanently");


	input();
	getch();
	closegraph();
	cleardevice();
	celestial_zone();
}*/
/************************animationzone******************/
/*********************optics************************/
void optics()
{
	int button,x,y;
	int maxx,maxy;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"");
	cleardevice();
	maxx=getmaxx();
	maxy=getmaxy();
	setbkcolor(5);
	rectangle(8,8,maxx-8,maxy-8);
	rectangle(12,12,maxx-12,maxy-12);
	rectangle(210,50,400,100);
	settextstyle(1,0,5);
	outtextxy(230,50,"OPTICS");
	putpixel(80,200,15);
	rectangle(80,200,200,300);
	rectangle(240,200,360,300);
	rectangle(400,200,520,300);
	setfillstyle(1,4);
	delay(350);
	floodfill(90,220,15);
	delay(350);
	floodfill(250,220,15);
	delay(350);
	floodfill(410,220,15);
	settextstyle(2,0,5);
	delay(350);
	outtextxy(85,240,"PLANE MIRROR");
	delay(350);
	outtextxy(245,240,"CONVEX MIRROR");
	delay(350);
	outtextxy(405,240,"CONCAVE MIRROR");
	delay(350);
	rectangle(500,440,550,465);
	settextstyle(0,0,1);
	outtextxy(510,449,"BACK");
	showmouseptr();
	while(1)
	{
		getmousepos(&button,&x,&y);
		if(button==1)
		{
			if((x>=80)&&(x<=200)&&(y>=200)&&(y<=300))
			{
				sound(650);
				delay(300);
				nosound();
				hidemouse();
				closegraph();
				planemirror();
				break;
			}
			else
			if((x>=240)&&(x<=360)&&(y>=200)&&(y<=300))
			{
				sound(650);
				delay(300);
				nosound();
				hidemouse();
				closegraph();
				convex();
				break;
			}
			else
			if((x>=400)&&(x<=520)&&(y>=200)&&(y<=300))
			{
				sound(650);
				delay(300);
				nosound();
				hidemouse();
				closegraph();
				concave();
				break;
			}
			else
			if(x>=500&&x<=550&&y>=440&&y<=465)
			{
				sound(650);
				delay(300);
				nosound();
				hidemouse();
				closegraph();
				study_zone();
				break;
			}
			else
			;
		}//end of if
	}//end of while

}//end of func


/****************************************************************************
*********************************CONVEX MIRROR*****************************
***************************************************************************/

void convex()
{
	void *p;
	int button,x,y;
	int gd=DETECT,gm;
	int i;
	int size;
	initgraph(&gd,&gm,"");
	cleardevice();
	arc(getmaxx()/2,getmaxy()/2,318,49,160);
	arc(getmaxx()/2+270,getmaxy()/2,130,220,160);
       //	rectangle(428,152,480,327);
       //	setfillstyle(1,14);
	size=imagesize(428,152,480,327);
	p=malloc(size);
	getimage(428,152,480,327,p);
	cleardevice();
	setbkcolor(4);
	rectangle(8,8,getmaxx()-8,getmaxy()-8);
	rectangle(12,12,getmaxx()-12,getmaxy()-12);
	putimage(260,120,p,0);//convex mirror
	line(286,115,286,300);//division
	line(10,210,620,210);//principal axis
	outtextxy(80,220,"OBJECT");
	outtextxy(120,130,"INCIDENT RAYS");
	outtextxy(500,130,"REFRACTED RAYS");
	line(100,210,100,150);//object
	line(100,150,90,170);//arrow head
	line(100,150,110,170);//arrow head 2
	settextstyle(BOLD_FONT,0,1);
	outtextxy(100,50,"CONVEX MIRROR");

	for(i=0;i<186;i++)
	{
		putpixel(100+i,150,15);
		delay(15);
	}
	for(i=0;i<160;i++)
	{
		putpixel(285+2*i,150+i/2,15);
		delay(15);
	}
	for(i=0;i<140;i++)
	{
		putpixel(100+3*i,150+i,15);
		delay(20);
	}
	getch();
	cleardevice();
	setbkcolor(4);//red bkgrund
	settextstyle(0,0,1);
	outtextxy(210,230,"OBJECT");
	outtextxy(210,100,"INCIDENT RAYS");
	outtextxy(500,130,"REFRACTED RAYS");
	rectangle(8,8,getmaxx()-8,getmaxy()-8);//border 1
	rectangle(12,12,getmaxx()-12,getmaxy()-12);//border 2
	putimage(260,120,p,0);//convex lens
	line(286,115,286,300);//division
	line(10,210,620,210);//principal axis
	line(236,210,236,160);//object
	line(236,160,228,168);//arrow head
	line(236,160,244,168);//arrow 2
		settextstyle(BOLD_FONT,0,1);
	outtextxy(100,50,"CONVEX MIRROR");
	for(i=0;i<=50;i++)             //incident ray
	{
		putpixel(236+i,160,15);
	}
	for(i=0;i<=150;i++)
	{
		putpixel(286+2*i,160+i,15);
		if(i<50)
		putpixel(286-2*i,160-i,15);
	}
	for(i=0;i<=200;i++)
	{
		putpixel(236+i,160+i,15);
		if(i<50)
		putpixel(236-i,160-i,15);
	}
	for(i=0;i<=100;i++)
	{
		if(i%2==0)
		putpixel(187,210-i,15);
		delay(20);
	}
	settextstyle(0,0,1);
	outtextxy(147,220,"VIRTUAL");
	outtextxy(147,240,"IMAGE");
	line(187,110,180,118);
	line(187,110,195,118);
	showmouseptr();
	rectangle(500,440,550,465);
	settextstyle(0,0,1);
	outtextxy(510,449,"BACK");
	while(1)
	{

		getmousepos(&button,&x,&y);
		if(button==1)
		{
			if((x>=500)&&(x<=550)&&(y>=440)&&(y<=465))
			{
				sound(650);
				delay(400);
				nosound();
				hidemouse();
				cleardevice();
				closegraph();
				optics();
				break;
			}
		}
		else;
       }

}
/*****************************************************************************
*****************************CONCAVE MIRROR***********************************
************************************************************************/
void concave()
{
	int size,i;
	int button,x,y,gd=DETECT,gm;
	void *cv;
	initgraph(&gd,&gm,"");

	cleardevice();
	setbkcolor(4);
	arc(getmaxx()/2,getmaxy()/2,320,40,100);//left
	arc(550,getmaxy()/2,140,224,100);
	line(400,180,468,180);
	line(396,300,470,300);
	size=imagesize(400,180,470,300);
	cv=malloc(size);
	getimage(400,180,470,300,cv);
	cleardevice();
	setbkcolor(4);
	settextstyle(1,0,1);
	outtextxy(100,50,"CONCAVE MIRROR");
	putimage(250,180,cv,0);
	line(0,240,639,240);
	line(285,180,285,300);
	rectangle(8,8,getmaxx()-8,getmaxy()-8);
	rectangle(12,12,getmaxx()-12,getmaxy()-12);
	settextstyle(0,0,1);
	outtextxy(50,100,"INCIDENT RAY");
	outtextxy(50,120,"PARALLEL TO PRINCIPAL AXIS");
	for(i=0;i<=85;i++)//incident
	{
		putpixel(200+i,200,15);
		putpixel(200+i,280,15);
		delay(15);
	}
	for(i=0;i<100;i++)//refracted
	{
		putpixel(285+i,200-i,15);
			putpixel(285+i,280+i,15);
		delay(15);
	}
	for(i=0;i<40;i++)//image
	{
		if(i%2==0)
		{
		putpixel(285-i,200+i,15);
		putpixel(285-i,280-i,15);
		delay(15);
		}
	}
	getch();
	cleardevice();
	setbkcolor(4);
	settextstyle(1,0,1);
	outtextxy(100,50,"CONCAVE MIRROR");
	settextstyle(0,0,1);
	outtextxy(50,100,"INCIDENT RAY");
	outtextxy(50,120,"AT AN ANGLE TO PRINCIPAL AXIS");
	rectangle(8,8,getmaxx()-8,getmaxy()-8);
	rectangle(12,12,getmaxx()-12,getmaxy()-12);
	putimage(250,180,cv,0);
	line(0,240,639,240);
	line(285,180,285,300);
	getch();
	for(i=0;i<=50;i++)//incident
	{
		putpixel(235+i,150+i,15);
		putpixel(235+i,330-i,15);
		delay(15);
	}
	for(i=0;i<=100;i++)
	{
		putpixel(285+i,200,15);
		putpixel(285+i,280,15);
		delay(15);
	}
	for(i=0;i<=40;i++)
	{
		putpixel(285+i,200+i,15);
		putpixel(285+i,280-i,15);
		delay(15);
	}
	settextstyle(0,0,1);
	rectangle(500,440,550,465);
	outtextxy(510,449,"BACK");
	showmouseptr();
	while(1)
	{
		getmousepos(&button,&x,&y);
		if(button==1)
		{
			if((x>=500)&&(x<=550)&&(y>=440)&&(y<=465))
			{
				sound(650);
				delay(400);
				nosound();
				hidemouse();
				closegraph();
				optics();
				break;
			}
		}
		else;
       }


}
/********************************************************************
*********************PLANE MIRROR************************************
****************************************************************/
void planemirror()
{
	int i;
	int button,x,y;
	int gd=DETECT,gm;
	void *m;
	int size;
	initgraph(&gd,&gm,"");

	cleardevice();
	setbkcolor(4);
	line((getmaxx()/2),getmaxy()/2+150,getmaxx()/2,getmaxy()/2-150);

	for(i=0;i<=300;i=i+10)
	{
		line(getmaxx()/2,getmaxy()/2+150-i,getmaxx()/2+10,getmaxy()/2+170-i);
	}
       //tma	rectangle(getmaxx()/2-15,getmaxy()/2-148,getmaxx()/2+15,getmaxy()/2+152);
	size=imagesize(getmaxx()/2-15,getmaxy()/2-148,getmaxx()/2+15,getmaxy()/2+152);
	m=malloc(size);
	getimage(getmaxx()/2-15,getmaxy()/2-148,getmaxx()/2+15,getmaxy()/2+152,m);
	cleardevice();
	setbkcolor(4);
	settextstyle(BOLD_FONT,0,1);
	rectangle(8,8,getmaxx()-8,getmaxy()-8);
	rectangle(12,12,getmaxx()-12,getmaxy()-12);
	outtextxy(80,40,"PLANE MIRROR");
	settextstyle(0,0,1);
	putimage(getmaxx()/2-15,getmaxy()/2-148,m,0);
	outtextxy(200,400,"Press key to Pass A incident ray Normal to plane");
	getch();
	settextstyle(0,0,1);
	outtextxy(100,220,"INCIDENT RAY");
       for(i=0;i<=220;i++)
	{
		putpixel(100+i,240,15);
		delay(25);
	}
	outtextxy(100,260,"REFLECTED RAY");
	getch();
	cleardevice();
	setbkcolor(4);
	rectangle(8,8,getmaxx()-8,getmaxy()-8);
	rectangle(12,12,getmaxx()-12,getmaxy()-12);
	settextstyle(BOLD_FONT,0,1);
	outtextxy(80,40,"PLANE MIRROR");
	putimage(getmaxx()/2-15,getmaxy()/2-148,m,0);
	line(100,240,320,240);
	settextstyle(0,0,1);
	outtextxy(200,400,"Press a key pass incident ray in a angle");
		getch();
		outtextxy(200,100,"INCIDENT RAY");
	for(i=0;i<=120;i++)
	{
		putpixel(200+i,120+i,15);
		delay(15);

	}
	for(i=0;i<=120;i++)
	{
		putpixel(320-i,240+i,15);
		delay(25);

	}
	outtextxy(200,372,"REFLECTED RAY");
	settextstyle(0,0,1);
	rectangle(500,440,550,465);
	outtextxy(510,449,"BACK");
	showmouseptr();
	while(1)
	{
		getmousepos(&button,&x,&y);
		if(button==1)
		{
			if(x>500&&x<550&&y>440&&y<465)
			{
				sound(650);
				delay(400);
				nosound();
				hidemouse();
				closegraph();
				optics();
				break;
			}
			else
			;
		}
	}


}
/*/********************************************************************
*****************************MATHS ZONE*****************************
*******************************************************************/
void maths()
{
	int i,k=0;
	int gd=DETECT,gm;
	int button,x,y;
	initgraph(&gd,&gm,"");
	cleardevice();
	setbkcolor(4);
	rectangle(8,8,getmaxx()-7,getmaxy()-7);
	rectangle(12,12,getmaxx()-12,getmaxy()-12);
	settextstyle(BOLD_FONT,0,4);
	outtextxy(220,60,"MATHS");
	rectangle(60,180,200,300);
	rectangle(230,180,370,300);
	rectangle(400,180,540,300);
	setfillstyle(1,6);
	for(i=1;i<=3;i++)
	{

		floodfill(100+k,200,15);
		k=k+160;
		delay(400);
	}
	settextstyle(3,0,2);
	delay(300);
	outtextxy(80,220,"GEOMETRY");
	delay(300);
	outtextxy(80+155,210,"PLAYING WITH");
	delay(300);
	outtextxy(80+180,250,"NUMBERS");
	delay(300);
	outtextxy(80+155+200,210,"SERIES");
	showmouseptr();
	settextstyle(0,0,1);
	rectangle(500,440,550,465);
	outtextxy(510,449,"BACK");
	while(1)
	{       showmouseptr();
		getmousepos(&button,&x,&y);
		if(button==1)
		{
			if(x>60&&x<200&&y>180&&y<300)
			{
				hidemouse();
				sound(600);
				delay(400);
				nosound();
				cleardevice();
				setbkcolor(0);
				closegraph();
				geometry();
				break;
			 }
			 else if(x>230&&x<370&&y>180&&y<300)
			 {
				sound(600);
				delay(400);
				nosound();
				hidemouse();
				cleardevice();
				setbkcolor(0);
				closegraph();
				playnum();
				break;
			 }
			 else if(x>500&&x<550&&y>440&&y<465)
			 {
				sound(600);
				delay(400);
				nosound();
				hidemouse();
				cleardevice();
				setbkcolor(0);
				closegraph();
				study_zone();
				break;
			 }
			 else if(x>400&&y>180&&x<540&&y<300)
			 {

				sound(600);
				delay(400);
				nosound();
				hidemouse();
				cleardevice();
				setbkcolor(0);
				closegraph();
				series();
				break;
			  }
		 }
	}

}
/****************************geometry******************************
******************************************************************
**************************************************************************
************************************************************************/
void geometry()
{
     //cleardevice();
     int button,x,y;
     int gd=DETECT,gm;
     initgraph(&gd,&gm,"");
     cleardevice();
     setbkcolor(3);
     rectangle(8,8,getmaxx()-8,getmaxy()-8);
     rectangle(12,12,getmaxx()-12,getmaxy()-12);
     rectangle(50,150,250,200);//2d
     rectangle(50,250,250,300);//3d
     rectangle(50,350,250,400);//circle
     rectangle(400,150,580,200);//ellipse
     rectangle(400,250,580,300);//parabola
     settextstyle(7,0,1);
     outtextxy(120,165,"2D");
     outtextxy(120,265,"3D");
     outtextxy(120,365,"CIRCLE");
     outtextxy(450,165,"ELLIPSE");
     outtextxy(450,265,"PARABOLA");
     settextstyle(1,0,5);
     outtextxy(200,40,"GEOMETRY");
     settextstyle(0,0,1);
     rectangle(500,440,550,465);
     outtextxy(510,449,"BACK");
     showmouseptr();
     while(1)
     {  showmouseptr();
	getmousepos(&button,&x,&y);
	if(button==1)
	{
		if(x>50&&x<250&&y>150&&y<200)//2d
		{
		   sound(600);
		   delay(400);
		   nosound();
		   hidemouse();
		   closegraph();
		   _2D();
		   break;
		}
	       else	if(x>50&&x<250&&y>250&&y<300)//3d
		{
		    sound(600);
		    delay(400);
		    nosound();
		    hidemouse();
		    closegraph();
		    _3D();
		    break;
		}
		else if(x>50&&x<250&&y>350&&y<400)//circle
		{
			sound(600);
			delay(400);
			nosound();
			hidemouse();
			closegraph();
			circal();
			break;
		}
	  else	if(x>400&&x<580&&y>150&&y<200)//ellipse
		{
			sound(600);
			delay(400);
			nosound();
			hidemouse();
			closegraph();
			ellip();
			break;
		}
	     else if(x>400&&x<580&&y>250&&y<300)//parabola
		{
		sound(600);
		delay(400);
		nosound();
		hidemouse();
		closegraph();
		parabola();
		break;
		}
	     else if(x>500&&x<550&&y>440&&y<465)
	     {
		sound(650);
		delay(400);
		nosound();
		cleardevice();
		setbkcolor(0);
		hidemouse();
		closegraph();
		maths();
		break;
	     }
	     else;


	}
     }

}
/****************************2D********************************
**********************************************************/
void _2D()
{

	int i;
	char c;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"");
	cleardevice();
	setfillstyle(1,1);
	setbkcolor(2);
	rectangle(160,18,440,68);
	floodfill(170,25,15);
	settextstyle(BOLD_FONT,0,3);
	outtextxy(210,14,"2 D Space");
	settextstyle(COMPLEX_FONT,0,1);
	rectangle(8,8,getmaxx()-8,getmaxy()-8);
	rectangle(4,4,getmaxx()-4,getmaxy()-4);
       for(i=0;i<100;i++)
       {        delay(50);
	line(getmaxx()/2,getmaxy()/2-i-30,getmaxx()/2,getmaxy()/2+i+30); //vertical
	line(getmaxx()/2-i-50,getmaxy()/2,getmaxx()/2+i+50,getmaxy()/2);  //horizontal
	}
	outtextxy(getmaxx()/2+20,getmaxy()/2-100,"1st quadrant");
	outtextxy(getmaxx()/2-160,getmaxy()/2-100,"2nd quadrant");
	outtextxy(getmaxx()/2-160,getmaxy()/2+70,"3rd quadrant");
	outtextxy(getmaxx()/2+20,getmaxy()/2+70,"4th quadrant");
	outtextxy(getmaxx()/2+160,getmaxy()/2-18,"+X");
	outtextxy(getmaxx()/2-175,getmaxy()/2-18,"-X");
	outtextxy(getmaxx()/2-18,getmaxy()/2-160,"+Y");
	outtextxy(getmaxx()/2-18,getmaxy()/2+130,"-Y");
	settextstyle(0,0,1);
	outtextxy(20,450,"Press 'x' to back");
       D:	c=getch();
       if(c!='x')
       goto D;
       else
       {
       hidemouse();
       closegraph();
       geometry();  }


}
/***********************************************************************
*******************************3D****************************************/
void _3D()
{

	int i;
	 int poly[]={230,266,230,130,366,80,366,216,230,266};
	 int poly1[]={366,216,502,216,385,266,230,266};
	 int poly2[]={366,266,366,342,230,402,230,266};
	 int poly3[]={230,266,94,266,190,216,230,216};


       int gd=DETECT,gm;
	char c;
	initgraph(&gd,&gm,"");
	//setbkcolor(2);
	cleardevice();
	setbkcolor(0);
	setfillstyle(1,1);
	rectangle(160,18,440,68);
	//rectangle(165,23,435,63);
	floodfill(180,28,15);
	settextstyle(BOLD_FONT,0,3);
	outtextxy(210,14,"3 D Space");
	rectangle(8,8,getmaxx()-8,getmaxy()-8);
	rectangle(4,4,getmaxx()-4,getmaxy()-4);

	      setfillstyle(1,1);
	      delay(300);
	      fillpoly(5,poly);
	      delay(300);
	      setfillstyle(1,3);
	      fillpoly(4,poly1);
	      delay(300);
	      setfillstyle(1,1);
	      fillpoly(4,poly2);
	      delay(300);
	      setfillstyle(1,3);
	      fillpoly(4,poly3);
	      delay(300);
	      settextstyle(COMPLEX_FONT,0,1);
	      /*outtextxy(380,150," 1st REGION");
	      outtextxy(100,150," 2nd REGION");
	      outtextxy(380,300," 3rd REGION");
	      outtextxy(100,300," 4th REGION");*/

	      for(i=0;i<80;i++)
	      {
		line(299,237-i,399,241-i);      //1st
		delay(40);
		line(180,230-i,230,233-i);        //3rd

		}
		for(i=0;i<80;i++)
		{
		line(299,267+i,399,271+i);    //1st
		delay(40);
		line(180,266+i,230,269+i);
		line(299,269,399,267);
		line(299,269,399,268);
		line(299,269,399,269);

		}

		for(i=0;i<120;i++)
		{
		line(238,259,238,259-i);//y
		delay(40);
		line(238,259,238+i+16,259);//x
	       //	line(238,259,238+i,92-i); //z

		}


	      outtextxy(245,125,"+Y");
	      outtextxy(375,234,"+X ");
	      outtextxy(340,186,"+Z");
	      settextstyle(SCRIPT_FONT,0,2);
	      outtextxy(getmaxx()/2-100,getmaxy()-50,"The 8 regions of 3 D space");
	     settextstyle(0,0,1);
	     outtextxy(20,450,"Press 'x' to back");
	    F:  c=getch();
	      if(c!='x')
	       goto F;
	       else
	       {hidemouse();
	       closegraph();
	       geometry();  }


}
/***************************************************************************
******************************circle************************************/
void circal()
{
	char c;
	int i;
	int gd=DETECT,gm;
      initgraph(&gd,&gm,"");
      cleardevice();
	setfillstyle(1,1);
	rectangle(150,18,430,68);
	floodfill(160,25,15);
	settextstyle(BOLD_FONT,0,3);
	outtextxy(230,14,"CIRCLE");
	settextstyle(SIMPLEX_FONT,0,1);
	outtextxy(getmaxx()/2-20,getmaxy()/2-23,"r");
	outtextxy(getmaxx()/4,getmaxy()-50,"Press W for ZOOM IN and S for ZOOM OUT");
	outtextxy(15,115,"Equation: ");
	outtextxy(100,100,"2       2     2");
	settextstyle(SIMPLEX_FONT,0,4);
	outtextxy(89,102,"x + y= r");
       y: rectangle(150,18,430,68);
	  floodfill(160,25,15);
	settextstyle(BOLD_FONT,0,3);
	outtextxy(230,14,"CIRCLE");
	settextstyle(SIMPLEX_FONT,0,1);
	outtextxy(getmaxx()/4,getmaxy()-50,"Press W for ZOOM IN and S for ZOOM OUT");
	outtextxy(getmaxx()/2-20,getmaxy()/2-23,"r");
	outtextxy(15,115,"Equation: ");
	outtextxy(100,100,"2       2     2");
	settextstyle(SIMPLEX_FONT,0,4);
	outtextxy(89,102,"x + y= r");
	for(i=11;i<100 && i>10;i++)
	{
	rectangle(150,18,430,68);
	floodfill(160,25,15);
	settextstyle(BOLD_FONT,0,3);
	outtextxy(230,14,"CIRCLE");
	settextstyle(SIMPLEX_FONT,0,1);
	outtextxy(getmaxx()/4,getmaxy()-50,"Press W for ZOOM IN and S for ZOOM OUT");

	outtextxy(getmaxx()/2-20,getmaxy()/2-23,"r");
	outtextxy(15,115,"Equation: ");
	outtextxy(100,100,"2       2     2");
	settextstyle(SIMPLEX_FONT,0,4);
	outtextxy(89,102,"x + y= r");

	circle(getmaxx()/2,getmaxy()/2,1);
	line(getmaxx()/2-(i+40),getmaxy()/2,getmaxx()/2,getmaxy()/2);
	circle(getmaxx()/2,getmaxy()/2,i+40);
	setbkcolor(4);
	gotoxy(9,22);

	printf("Radius: %d px",i+39);
	settextstyle(0,0,1);
	outtextxy(20,450,"Press 'x' to back");
       x:	c=getch();
	if(c=='w')
	{
		cleardevice();
	}
	else  if(c=='s')
	{
	 i=i-2;
	 cleardevice();
	 }
	 else if(c!='w'&&c!='s'&&c!='x')
	 {
	 goto x;
	 }
	 else if(c=='x')
	 {
	 break;
	  }

	}
	if(c!='x')
	goto y;
	else
	{hidemouse();
	closegraph();
	geometry();  }

}
/***************************************************************************
*************************************************************************/
void ellip()
{
	char c;
	int i;
	int gd=DETECT,gm;
       initgraph(&gd,&gm,"");
       cleardevice();
	setfillstyle(1,1);
       //rectangle(160,18,440,68);
       //floodfill(170,25,15);
	settextstyle(BOLD_FONT,0,3);
	outtextxy(230,14,"ELLIPSE");
	settextstyle(SIMPLEX_FONT,0,2);
	outtextxy(getmaxx()/2-30,getmaxy()/2-25,"a");
	outtextxy(getmaxx()/2+5,getmaxy()/2-30,"b");
	settextstyle(SIMPLEX_FONT,0,1);
	outtextxy(getmaxx()/4,getmaxy()-50,"Press W for ZOOM IN and S for ZOOM OUT");
	outtextxy(15,115,"Equation: ");
	outtextxy(100,100,"2       2     ");
	outtextxy(100,135,"2       2      ");
	settextstyle(SIMPLEX_FONT,0,4);
	outtextxy(85,100,"__  __   ");
	outtextxy(89,102,"x + y = 1");

	outtextxy(89,138,"a    b   ");  //text formatting ends
       y:	for(i=11;i<100 && i>10;i++)
	{
	setfillstyle(1,1);       //text formating starts
       //	rectangle(160,18,440,68);
       //	floodfill(170,25,15);
	settextstyle(BOLD_FONT,0,3);
	outtextxy(230,14,"ELLIPSE");
	settextstyle(SIMPLEX_FONT,0,2);
	outtextxy(getmaxx()/2-30,getmaxy()/2-25,"a");
	outtextxy(getmaxx()/2+5,getmaxy()/2-30,"b");
	settextstyle(SIMPLEX_FONT,0,1);
	outtextxy(getmaxx()/4,getmaxy()-50,"Press W for ZOOM IN and S for ZOOM OUT");
	outtextxy(15,115,"Equation: ");
	outtextxy(100,100,"2       2     ");
	outtextxy(100,135,"2       2      ");
	settextstyle(SIMPLEX_FONT,0,4);
	outtextxy(85,100,"__  __   ");
	outtextxy(89,102,"x + y = 1");
	outtextxy(89,138,"a    b   ");  //text formatting ends
	ellipse(getmaxx()/2,getmaxy()/2,0,360,i+50,i+10);
	gotoxy(9,22);
	printf("a= %d px\n",i+49);
	printf("        b= %d px \n ",i+9);
       //	printf("	e= %f  px  ",(float)(((i+9)*(i+9))/(i+49)));
	setbkcolor(4);
	line((getmaxx()/2),getmaxy()/2-30-i,getmaxx()/2,getmaxy()/2+30+i);  //vertical line
	line(getmaxx()/2-70-(i),getmaxy()/2,getmaxx()/2+70+(i),getmaxy()/2);  //horizontal line
	settextstyle(0,0,1);
	outtextxy(20,450,"Press 'x' to back");
       x:	c=getch();
	if(c=='w')
	{
		cleardevice();
	}
	else  if(c=='s')
	{
	 i=i-2;
	 cleardevice();
	 }
	 else if(c!='w'&&c!='s'&&c!='x')
	 {
	 goto x;
	 }
	 else if(c=='x')
	 {
	 break;
	  }

	}
	if(c!='x')
	goto y;
	else
	{ hidemouse();
	closegraph();
	geometry();   }

}
/***************************************************************************
**********************PARABOLA*********************************************/
void parabola()
{
	char c;
	int i,x,y;
       int gd=DETECT,gm;
       initgraph(&gd,&gm,"");
	cleardevice();
	setbkcolor(0);
	settextstyle(BOLD_FONT,0,3);
	outtextxy(210,14,"PARABOLA");
	settextstyle(SIMPLEX_FONT,0,1);

	outtextxy(120,200,"Equation: x =4ay");

	outtextxy(310,200,"Equation: y =4ax");

	outtextxy(120,380,"Equation: x =-4ax");

	outtextxy(310,380,"Equation: y =-4ax");
	settextstyle(0,0,1);
	outtextxy(202,203,"2");
	outtextxy(392,203,"2");
	outtextxy(202,383,"2");
	outtextxy(392,383,"2");
	line(getmaxx()/2-250,getmaxy()/2-160,getmaxx()/2-250,getmaxy()/2-15); //vertical left top
	line(getmaxx()/2-330,getmaxy()/2-50,getmaxx()/2-170,getmaxy()/2-50);//horizontal left top
	line(getmaxx()/2+170,getmaxy()/2-160,getmaxx()/2+170,getmaxy()/2-15); //vertical right top
	line(getmaxx()/2+130,getmaxy()/2-90,getmaxx()/2+280,getmaxy()/2-90); //horizontal right top
	line(getmaxx()/2-250,getmaxy()/2+55,getmaxx()/2-250,getmaxy()/2+200); //vertical left bottom
	line(getmaxx()/2-330,getmaxy()/2+85,getmaxx()/2-170,getmaxy()/2+85);//horizontal left bottom
	line(getmaxx()/2+230,getmaxy()/2+55,getmaxx()/2+230,getmaxy()/2+200); //vertical right bottom
	line(getmaxx()/2+130,getmaxy()/2+125,getmaxx()/2+280,getmaxy()/2+125); //horizontal right bottom

      y:	for(i=9;i<40 && i>8;i++)
	{
	settextstyle(BOLD_FONT,0,3);
	outtextxy(210,14,"PARABOLA");
	settextstyle(SIMPLEX_FONT,0,1);

	outtextxy(120,200,"Equation: x =4ay");

	outtextxy(310,200,"Equation: y =4ax");

	outtextxy(120,380,"Equation: x =-4ax");

	outtextxy(310,380,"Equation: y =-4ax");
	settextstyle(0,0,1);
	outtextxy(202,203,"2");
	outtextxy(392,203,"2");
	outtextxy(202,383,"2");
	outtextxy(392,383,"2");
	arc(getmaxx()/2-250,getmaxy()/2-120,180,0,i+10);//left top
	arc(getmaxx()/2-250,getmaxy()/2+160,0,180,i+10);//left bottom
	arc(getmaxx()/2+250,getmaxy()/2-90,90,270,i+10);//right top
	arc(getmaxx()/2+160,getmaxy()/2+125,270,90,i+10);//right bottom
	line(getmaxx()/2-250,getmaxy()/2-160,getmaxx()/2-250,getmaxy()/2-15); //vertical left top
	line(getmaxx()/2-330,getmaxy()/2-50,getmaxx()/2-170,getmaxy()/2-50);//horizontal left top
	line(getmaxx()/2+170,getmaxy()/2-160,getmaxx()/2+170,getmaxy()/2-15); //vertical right top
	line(getmaxx()/2+130,getmaxy()/2-90,getmaxx()/2+280,getmaxy()/2-90); //horizontal right top
	line(getmaxx()/2-250,getmaxy()/2+55,getmaxx()/2-250,getmaxy()/2+200); //vertical left bottom
	line(getmaxx()/2-330,getmaxy()/2+85,getmaxx()/2-170,getmaxy()/2+85);//horizontal left bottom
	line(getmaxx()/2+230,getmaxy()/2+55,getmaxx()/2+230,getmaxy()/2+200); //vertical right bottom
	line(getmaxx()/2+130,getmaxy()/2+125,getmaxx()/2+280,getmaxy()/2+125); //horizontal right bottom

	settextstyle(0,0,1);
	outtextxy(20,450,"Press 'x' to back");
	settextstyle(SIMPLEX_FONT,0,1);
	outtextxy(getmaxx()/4,getmaxy()-50,"Press W for ZOOM IN and S for ZOOM OUT");
	//   left top
	outtextxy(getmaxx()/2-240,getmaxy()/2-75,"O");
	outtextxy(getmaxx()/2-170,getmaxy()/2-75,"+X");
	outtextxy(getmaxx()/2-320,getmaxy()/2-75,"-X");
	outtextxy(getmaxx()/2-240,getmaxy()/2-175,"+Y");
	//  left bottom
	outtextxy(getmaxx()/2-235,getmaxy()/2+80,"O");
	outtextxy(getmaxx()/2-170,getmaxy()/2+80,"+X");
	outtextxy(getmaxx()/2-320,getmaxy()/2+80,"-X");
	outtextxy(getmaxx()/2-240,getmaxy()/2+175,"-Y");
	//right top
	outtextxy(getmaxx()/2+175,getmaxy()/2-95,"O");
	outtextxy(getmaxx()/2+175,getmaxy()/2-35,"-Y");
	outtextxy(getmaxx()/2+280,getmaxy()/2-100,"+X");
	outtextxy(getmaxx()/2+175,getmaxy()/2-175,"+Y");
	//right bottom
	outtextxy(getmaxx()/2+215,getmaxy()/2+95,"O");
	outtextxy(getmaxx()/2+200,getmaxy()/2+35,"+Y");
	outtextxy(getmaxx()/2+120,getmaxy()/2+100,"-X");
	outtextxy(getmaxx()/2+200,getmaxy()/2+175,"-Y");
	  outtextxy(20,470,"Press 'x' to back");
	  x:	c=getch();
	if(c=='w')
	{
		cleardevice();
	}
	else  if(c=='s')
	{
	 i=i-2;
	 cleardevice();
	 }
	 else if(c!='w'&&c!='s'&&c!='x')
	 {
	 goto x;
	 }
	 else if(c=='x')
	 {
	 break;
	  }

	}
	if(c!='x')
	goto y;
	else
	{hidemouse();
	closegraph();
	geometry();
	 }

}


void series()
{
	int loop=1,x,y,button,i;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"");
	cleardevice();
	settextstyle(BOLD_FONT,0,3);
	setbkcolor(2);
	rectangle(8,8,getmaxx()-8,getmaxy()-8);
	rectangle(10,10,getmaxx()-10,getmaxy()-10);
	outtextxy(210,30,"SERIES");
	for(i=1;i<=4;i++)
	{
	if(i==1)
	{   delay(1000);
	//cos x
	settextstyle(SANS_SERIF_FONT,0,1);
	outtextxy(210,95,"        2      4       6      8");
	settextstyle(SANS_SERIF_FONT,0,4);
	outtextxy(50,100,"cos x = 1 - x + x - x + x ...... ");
	outtextxy(54,110,"             _   _   _   _ ");
	settextstyle(SANS_SERIF_FONT,0,2);
	outtextxy(140,140,"            2!      4!     6!     8!");
	delay(1000);
	}
	if(i==2)
	{
	//sin x
	settextstyle(SANS_SERIF_FONT,0,1);
	outtextxy(210,185,"        3      5       7      9");
	settextstyle(SANS_SERIF_FONT,0,4);
	outtextxy(50,190,"sin x  = x - x + x - x + x ...... ");
	outtextxy(54,200,"             _   _   _   _ ");
	settextstyle(SANS_SERIF_FONT,0,2);
	outtextxy(140,230,"            3!      5!     7!     9!");
	delay(1000);
	}
	//e x
	if(i==3)
	{
	settextstyle(SANS_SERIF_FONT,0,1);
	outtextxy(70,265,"x                         2      3       4      5");
	settextstyle(SANS_SERIF_FONT,0,4);
	outtextxy(50,270,"e  = 1 + x + x + x + x + x...... ");
	outtextxy(57,275,"              _   _   _   _ ");
	settextstyle(SANS_SERIF_FONT,0,2);
	outtextxy(140,305,"              2!      3!     4!     5!");
	delay(1000);
	}
	if(i==4)
	{
	//1/1-x
	settextstyle(SANS_SERIF_FONT,0,1);
	outtextxy(75,350,"                              2      3       4      5");
	settextstyle(SANS_SERIF_FONT,0,4);
	outtextxy(54,355,"1    = 1 + x + x + x + x + x...... ");
	outtextxy(50,360,"__      ");
	settextstyle(SANS_SERIF_FONT,0,2);
	outtextxy(48,390,"1-x                      ");
	delay(1000);
	}
       }
       rectangle(500,440,550,465);
       settextstyle(0,0,1);
       outtextxy(510,449,"back ");
	showmouseptr();
	while(loop)
	{
		getmousepos(&button,&x,&y);
		if(button==1)
		{
			if(x>500&&x<550&&y>440&&y<465)
			{
				hidemouse();
				loop=0;
				closegraph();
				maths();
			}
		}
	}



}



/**************************************************************************
*****************************PHYSICS***************************************
*****************************************************************************
***************************************************************************/
void physics()
{
	int maxx,maxy;
	int button,x,y,gd=DETECT,gm;
	initgraph(&gd,&gm,"");
	cleardevice();

	maxx=getmaxx();
	maxy=getmaxy();
	setbkcolor(9);
	rectangle(8,8,maxx-8,maxy-8);
	rectangle(12,12,maxx-12,maxy-12);
	settextstyle(1,0,3);
	outtextxy(250,100,"PHYSICS");
	outtextxy(250,110,"________");
	rectangle(200,200,400,400);
	setfillstyle(1,4);
	floodfill(210,210,15);
	settextstyle(TRIPLEX_FONT,0,2);
	outtextxy(260,260,"LASER");
	outtextxy(250,290,"PROJECT");
	settextstyle(0,0,1);
	rectangle(500,440,550,465);
	outtextxy(510,449,"BACK");
	showmouseptr();
	while(1)
	{
		getmousepos(&button,&x,&y);
		if(button==1)
		{
			if(x>200&&x<400&&y>200&&y<400)
			{
				hidemouse();
				closegraph();
				laser();
				break;
			}
			if(x>500&&x<550&&y>440&&y<465)
			{
				sound(650);
				delay(400);
				nosound();
				hidemouse();
				cleardevice();
				setbkcolor(0);
				closegraph();
				study_zone();
				break;
			}
		}
	}

}
/*************************LASER********************************************
*************************************************************************
*************************************************************************
**************************************************************************/
void laser()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"");
   projectwork1();
   projectwork2();
   projectwork3();
   getch();
   cleardevice();
   setbkcolor(0);
   closegraph();
   physics();
}


/**************************************************************************
*****************************BEE PROJECT*********************************
***************************************************************************/
void bee()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"");
	cleardevice();
	first_page();
	closegraph();

}


void fun_call()
{

	int b_poly4[]={120,70,145,70,153,78,153,62,160,70};
	int b_poly5[]={185,70,210,70,218,78,218,62,225,70,250,70};
	int b_poly6[]={120,130,145,130,153,138,153,122,160,130,212,130,220,138,220,122,228,130,250,130};
	//cleardevice();
	int loop=1,x,y,i;
	cleardevice();
	index=0;
	rectangle(2,2,638,478);
	rectangle(8,8,632,472);
	setfillstyle(1,1);
	floodfill(3,3,15);
	rectangle(120,200,530,250);
	settextstyle(TRIPLEX_FONT,0,2);
	outtextxy(215,70,"Loading Please Wait!!!");
	for(x=125;x<=515;x+=10)
	{

		rectangle(x,205,x+10,245);
		setfillstyle(1,2);
		floodfill(x+2,207,15);
		x+=5;
		delay(20);
	}
	delay(300);
	cleardevice();
	ansrecord[0]=0;
	ansrecord[1]=0;
	ansrecord[2]=0;
	ansrecord[3]=0;
	question1();
	cleardevice();
	question2();
	cleardevice();
	question3(b_poly4,b_poly5,b_poly6);
	cleardevice();
	question4();
	//cleardevice();
	//check();
}



/**********************************************************************************
*************************QUESTION_1_WITH_OPTION************************************
**********************************************************************************/

void question1()
{

	int button,x,y,answer,response_st=0,loop=1,loop2=1;
	int poly[10]={120,70,145,70,153,78,153,62,160,70};
	int poly2[12]={185,70,210,70,218,78,218,62,225,70,250,70};
	int poly3[]={120,130,145,130,153,138,153,122,160,130,212,130,220,138,220,122,228,130,250,130};
	line(100,200,180,200);
	line(180,185,180,215);
	line(190,200,270,200);
	line(190,193,190,207);
	line(270,200,270,100);
	line(270,100,250,100);
	line(100,200,100,100);
	line(100,100,115,100);
	line(100,100,120,100);
	line(120,70,120,130);
	line(250,70,250,130);
	drawpoly(5,poly);
	drawpoly(6,poly2);
	line(160,70,185,70);
	drawpoly(10,poly3);
	line(185,70,185,85);
	rectangle(175,85,195,110);
	line(185,110,185,130);
	settextstyle(0,0,1);
	outtextxy(25,235,"1 What will be the Thevnin Voltage across the Load");
	outtextxy(150,50,"2");
	outtextxy(150,145,"2");
	outtextxy(220,50,"2");
	outtextxy(220,145,"2");
	outtextxy(180,95,"L");
	/***************************option*********************************/

	rectangle(25,270,35,280);	//Ist option(x>25,x<35 y>270,y<280)
	outtextxy(40,273,"1 ohm");
	rectangle(185,270,195,280);	//IInd option
	outtextxy(200,273,"2 ohm");
	rectangle(25,350,35,360);  	//IIIrd option
	outtextxy(40,350,"4 ohm");
	rectangle(185,350,195,360);     //IVth option
	outtextxy(200,350,"8 ohm");
	setfillstyle(1,2);
	rectangle(290,300,350,330);     //Submit tab
	rectangle(292,303,348,328);
	floodfill(300,310,15);
	outtextxy(297,313,"Submit");
	setfillstyle(1,4);
	rectangle(610,10,630,25);       //X button
	floodfill(613,13,15);           //X button colour
	rectangle(608,8,632,27);	//
	line(611,11,629,24);            // X button
	line(611,26,629,11);

	loop=1;
	loop2=1;

	response_st=0;
	showmouseptr();
	while(loop)
	{
		getmousepos(&button,&x,&y);
		if(button==1)
		{
			setfillstyle(1,2);

			if(response_st==0)
			{
				if(((x>22)&&(x<38))&&((y>267)&&(y<284)))
				{

					hidemouseptr();
					setfillstyle(1,2);
					rectangle(27,272,33,278);
					floodfill(29,275,15);
					response_st=1;
					answer=1;
					break;
				}
				else
				if(((x>182)&&(x<198))&&((y>267)&&(y<283)))
				{
					hidemouseptr();
					rectangle(187,272,193,278);
					floodfill(189,274,15);
					response_st=1;
					answer=2;
					break;
				}
				else
				if(((x>22)&&(x<38))&&((y>347)&&(y<363)))
				{

					hidemouseptr();
					rectangle(27,352,33,358);
					floodfill(30,354,15);
					response_st=1;
					answer=3;
					break;
				}
				else
				if(((x>182)&&(x<198))&&((y>347)&&(y<363)))
				{

					hidemouseptr();
					rectangle(187,352,193,358);
					floodfill(190,355,15);
					response_st=1;
					answer=4;
					break;
				}
				else
				if(((x>605)&&(x<635))&&((y>5)&&(y<30)))
				{
					loop=0;
					hidemouse();
					mainpage();
					break;
				}

			}				//end of response check

		}					//end of click check

	}						//end of while loop

	showmouseptr();
	while(loop2)
	{
		showmouseptr();
		getmousepos(&button,&x,&y);
		if((response_st==1)&&(button==1))
		{
			if(((x>287)&&(x<353))&&((y>297)&&(y<393)))
			{
				hidemouse();
				ansrecord[index]=answer;
				loop2=0;
				break;
			}
		}
	}

}

/*****************************************************************************************
***************************************QUESTION_2_WITH_OPTION*****************************
*****************************************************************************************/

void question2()
{
	int button,x,y,answer,response_st=0,loop=1,loop2=1;
	index++;
	line(25,50,25,90);
	line(25,110,25,150);
	line(25,90,35,95);
	line(35,95,25,100);
	line(25,100,15,105);
	line(15,105,25,110);

	line(25,50,65,50);
	line(85,50,125,50);
	line(65,50,70,60);
	line(70,60,80,40);
	line(80,40,85,50);

	line(25,150,65,150);
	line(85,150,125,150);
	line(65,150,70,140);
	line(70,140,80,160);
	line(80,160,85,150);

	line(125,150,125,110);
	line(125,90,125,50);
	line(125,110,115,105);
	line(115,105,135,95);
	line(135,95,125,90);

	line(125,50,225,50);

	line(225,50,225,90);
	line(225,110,225,150);
	line(225,90,235,95);
	line(235,95,215,105);
	line(215,105,225,110);

	line(225,150,180,150);
	line(165,150,125,150);

	line(180,145,180,155);
	line(165,135,165,165);

	settextstyle(0,0,1);
	outtextxy(25,235,"2 Find the equivalent resistance");
	outtextxy(70,30,"2");
	outtextxy(70,160,"2");
	outtextxy(100,95,"2");
	outtextxy(5,100,"2");
	outtextxy(240,100,"3");

	/**************************option****************************/

	rectangle(25,270,35,280);	//Ist option(x>25,x<35 y>270,y<280)
	outtextxy(40,273,"4 ohm");
	rectangle(185,270,195,280);	//IInd option
	outtextxy(200,273,"16 ohm");
	rectangle(25,350,35,360);  	//IIIrd option
	outtextxy(40,350,"2 ohm");
	rectangle(185,350,195,360);     //IVth option
	outtextxy(200,350,"None of these");
	setfillstyle(1,2);
	rectangle(290,300,350,330);     //Submit tab
	rectangle(292,303,348,328);
	floodfill(300,310,15);
	outtextxy(297,313,"Submit");
	setfillstyle(1,4);
	rectangle(610,10,630,25);       //X button
	floodfill(613,13,15);           //X button colour
	rectangle(608,8,632,27);	//
	line(611,11,629,24);            // X button
	line(611,26,629,11);           //


	loop=1;
	loop2=1;
	response_st=0;
	showmouseptr();
	while(loop)
	{
		getmousepos(&button,&x,&y);
		if(button==1)
		{
			setfillstyle(1,2);
			if(response_st==0)
			{
				if(((x>22)&&(x<38))&&((y>267)&&(y<284)))
				{
					hidemouseptr();
					setfillstyle(1,2);
					rectangle(27,272,33,278);
					floodfill(29,275,15);
					response_st=1;
					answer=1;
					break;
				}
				else
				if(((x>182)&&(x<198))&&((y>267)&&(y<283)))
				{

					hidemouseptr();
					rectangle(187,272,193,278);
					floodfill(189,274,15);
					response_st=1;
					answer=2;
					break;
				}
				else
				if(((x>22)&&(x<38))&&((y>347)&&(y<363)))
				{
					hidemouseptr();
					rectangle(27,352,33,358);
					floodfill(30,354,15);
					response_st=1;
					answer=3;
					break;
				}
				else
				if(((x>182)&&(x<198))&&((y>347)&&(y<363)))
				{
					hidemouseptr();
					rectangle(187,352,193,358);
					floodfill(190,355,15);
					response_st=1;
					answer=4;
					break;
				}
				else
				if(((x>605)&&(x<635))&&((y>5)&&(y<30)))
				{
					loop=0;
					hidemouse();
					mainpage();
					break;
				}

			}				//end of response check

		}					//end of click check

	}						//end of while loop

	showmouseptr();
	while(loop2)
	{
		showmouseptr();
		getmousepos(&button,&x,&y);
		if((response_st==1)&&(button==1))
		{
			if(((x>287)&&(x<353))&&((y>297)&&(y<393)))
			{
				printf("\a");
				hidemouse();
				ansrecord[index]=answer;
				loop2=0;
				break;
			}
		}
	}
}



/***************************************************************************/
/*************************QUESTION_3_WITH_OPTION****************************/
/***************************************************************************/

void question3(int b_poly4[],int b_poly5[],int b_poly6[])
{
	int button,x,y,answer,response_st=0,loop=1,loop2=1;
	index++;
	line(100,200,180,200);
	line(180,185,180,215);
	line(190,200,270,200);
	line(190,193,190,207);
	line(270,200,270,100);
	line(270,100,250,100);
	line(100,200,100,100);
	line(100,100,115,100);
	line(100,100,120,100);
	line(120,70,120,130);
	line(250,70,250,130);
	drawpoly(5,b_poly4);
	drawpoly(6,b_poly5);
	line(160,70,185,70);
	drawpoly(10,b_poly6);
	settextstyle(0,0,1);
	outtextxy(25,235,"3 Find the equivalent resistance");
	outtextxy(150,45,"4");
	outtextxy(215,45,"4");
	outtextxy(150,150,"4");
	outtextxy(215,150,"4");

/******************************* options ************************************/

	rectangle(25,270,35,280);	//Ist option(x>25,x<35 y>270,y<280)
	outtextxy(40,273,"16 ohm");
	rectangle(185,270,195,280);	//IInd option
	outtextxy(200,273,"8 ohm");
	rectangle(25,350,35,360);  	//IIIrd option
	outtextxy(40,350,"4 ohm");
	rectangle(185,350,195,360);     //IVth option
	outtextxy(200,350,"6 ohm");
	setfillstyle(1,2);
	rectangle(290,300,350,330);     //Submit tab
	rectangle(292,303,348,328);
	floodfill(300,310,15);
	outtextxy(297,313,"Submit");
	setfillstyle(1,4);
	rectangle(610,10,630,25);       //X button
	floodfill(613,13,15);           //X button colour
	rectangle(608,8,632,27);	//
	line(611,11,629,24);            // X button
	line(611,26,629,11);           //



	loop=1;
	loop2=1;
	response_st=0;

	showmouseptr();
	while(loop)
	{
			getmousepos(&button,&x,&y);
		if(button==1)
		{
			setfillstyle(1,2);
			if(response_st==0)
			{
				if(((x>22)&&(x<38))&&((y>267)&&(y<284)))
				{
					hidemouseptr();
					setfillstyle(1,2);
					rectangle(27,272,33,278);
					floodfill(29,275,15);
					response_st=1;
					answer=1;
					break;
				}
				else
				if(((x>182)&&(x<198))&&((y>267)&&(y<283)))
				{

					hidemouseptr();
					rectangle(187,272,193,278);
					floodfill(189,274,15);
					response_st=1;
					answer=2;
					break;
				}
				else
				if(((x>22)&&(x<38))&&((y>347)&&(y<363)))
				{

					hidemouseptr();
					rectangle(27,352,33,358);
					floodfill(30,354,15);
					response_st=1;
					answer=3;
					break;
				}
				else
				if(((x>182)&&(x<198))&&((y>347)&&(y<363)))
				{

					hidemouseptr();
					rectangle(187,352,193,358);
					floodfill(190,355,15);
					response_st=1;
					answer=4;
					break;
				}
				else
				if(((x>605)&&(x<635))&&((y>5)&&(y<30)))
				{
					loop=0;
					hidemouse();
					mainpage();
					break;
				}

			}				//end of response check

		}					//end of click check

	}						//end of while loop

	showmouseptr();
	while(loop2)
	{
		showmouseptr();
		getmousepos(&button,&x,&y);
		if((response_st==1)&&(button==1))
		{
			if(((x>287)&&(x<353))&&((y>297)&&(y<393)))
			{
				printf("\a");
				hidemouse();
				ansrecord[index]=answer;
				loop2=0;
				break;
			}
		}
	}
}


/***************************************************************************/
/***********************QUESTION_4_WITH_OPTION*******************************/
/***************************************************************************/

void question4()
{

	int button,x,y,answer,response_st=0,loop=1,loop2=1;
	index++;
	line(50,200,180,200);
	line(180,185,180,215);//batt bar
	line(190,200,320,200);
	line(190,193,190,207);//batt bar
	line(320,200,320,50);
	line(50,200,50,50);
	line(50,50,85,50);
	line(105,50,140,50);
	line(140,50,140,160);
	line(140,160,175,160);//I
	line(195,160,230,160);//II
	line(230,160,230,50);//III
	line(230,50,265,50);//IV
	line(285,50,320,50);//V
	line(140,130,175,130);//VI
	line(195,130,230,130);


	line(85,50,90,40);
	line(90,40,100,60);  //Ist rst
	line(100,60,105,50);

	line(175,130,180,120);
	line(180,120,190,140); //IInd rst
	line(190,140,195,130);

	line(175,160,180,150);
	line(180,150,190,170);  //IIIrd rst
	line(190,170,195,160);

	line(265,50,270,40);
	line(270,40,280,60);    //IVth rst
	line(280,60,285,50);

	settextstyle(0,0,1);

	outtextxy(25,235,"4 Find the equivalent resistance");
	outtextxy(90,30,"2");     //Ist rst value
	outtextxy(180,105,"4");   //IInd rst value
	outtextxy(180,170,"4");   //IIIrd rst value
	outtextxy(270,30,"2");    //IVth rst value


/******************************* options ************************************/

	rectangle(25,270,35,280);	//Ist option(x>25,x<35 y>270,y<280)
	outtextxy(40,273,"16 ohm");
	rectangle(185,270,195,280);	//IInd option
	outtextxy(200,273,"8 ohm");
	rectangle(25,350,35,360);  	//IIIrd option
	outtextxy(40,350,"4 ohm");
	rectangle(185,350,195,360);     //IVth option
	outtextxy(200,350,"6 ohm");
	setfillstyle(1,2);
	rectangle(290,300,350,330);     //Submit tab
	rectangle(292,303,348,328);
	floodfill(300,310,15);
	outtextxy(297,313,"Submit");
	setfillstyle(1,4);
	rectangle(610,10,630,25);       //X button
	floodfill(613,13,15);           //X button colour
	rectangle(608,8,632,27);	//
	line(611,11,629,24);            // X button
	line(611,26,629,11);           //


	loop=1;
	loop2=1;
	response_st=0;
	showmouseptr();
	while(loop)
	{
		getmousepos(&button,&x,&y);
		if(button==1)
		{
			setfillstyle(1,2);

			if(response_st==0)
			{
				if(((x>22)&&(x<38))&&((y>267)&&(y<284)))
				{

					hidemouseptr();
					rectangle(27,272,33,278);
					floodfill(29,275,15);
					response_st=1;
					answer=1;
					break;
				}
				else
				if(((x>182)&&(x<198))&&((y>267)&&(y<283)))
				{

					hidemouseptr();
					rectangle(187,272,193,278);
					floodfill(189,274,15);
					response_st=1;
					answer=2;
					break;
				}
				else
				if(((x>22)&&(x<38))&&((y>347)&&(y<363)))
				{
					hidemouseptr();
					rectangle(27,352,33,358);					hidemouseptr();
					floodfill(30,354,15);
					response_st=1;
					answer=3;
					break;
				}
				else
				if(((x>182)&&(x<198))&&((y>347)&&(y<363)))
				{

					hidemouseptr();
					rectangle(187,352,193,358);
					floodfill(190,355,15);
					response_st=1;
					answer=4;
					break;
				}
				else
				if(((x>605)&&(x<635))&&((y>5)&&(y<30)))
				{
					loop=0;
					hidemouse();
					mainpage();
					break;
				}

			}				//end of response check

		}					//end of click check

	}						//end of while loop

	showmouseptr();
	while(loop2)
	{
		showmouseptr();
		getmousepos(&button,&x,&y);
		if((response_st==1)&&(button==1))
		{
			if(((x>287)&&(x<353))&&((y>297)&&(y<393)))
			{
				printf("\a");
				hidemouse();
				ansrecord[index]=answer;
				loop2=0;
				cleardevice();
				check();
				break;
			}
		}
	}
}


/****************************************************************************
*****************************Check_Function**********************************
****************************************************************************/
void check()
{
    int in=0,trueanswer[4],loop=1,button,x,y;
    int total=0;
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"");
    trueanswer[0]=2;
    trueanswer[1]=4;
    trueanswer[2]=3;
    trueanswer[3]=4;
    settextstyle(0,0,2);
    for(in=0;in<4;in++)
    {
	if(trueanswer[in]==ansrecord[in])
	{
		total++;
	}
    }
    if(total==1)
    {
	outtextxy((getmaxx()/2)-200,getmaxy()/2,"Poor.you have scored 1/4");
    }
    else
    if(total==2)
    {
	outtextxy((getmaxx()/2)-200,getmaxy()/2,"Good.You have scored 2/4");
    }
    else
    if(total==3)
    {
	outtextxy((getmaxx()/2)-200,getmaxy()/2,"Nice try.You have scored 3/4");
    }
    else
    if(total==4)
    {
	outtextxy(20,getmaxy()/2,"WOW.., You are excellent with circuits");
	outtextxy(150,getmaxy()/2+100,"You have scored 4/4");
    }
    else
    if(total==0)
    {
	outtextxy((getmaxx()/2)-220,getmaxy()/2,"Very poor.You should concentrate in study");
	outtextxy((getmaxx()/2)-120,getmaxy()/2+50,"You have scored 0/4");
    }
    rectangle(590,440,635,475);
    setfillstyle(1,2);
    floodfill(595,445,15);
    settextstyle(0,0,1);
    outtextxy(600,460,"Back");

    while(loop)
    {
	showmouseptr();
	getmousepos(&button,&x,&y);
	if(button==1)
	{
		if(((x>540)&&(x<635))&&((y>440)&&(y<475)))
		{
			hidemouseptr();
			loop=0;
			cleardevice();
			closegraph();
			mainpage();
			break;
		}
	}
    }
}


void first_page()
{
	int button,x,y,b_loop3=1;
	rectangle(5,5,getmaxx()-5,getmaxy()-5);
	rectangle(10,10,getmaxx()-10,getmaxy()-10);
	setfillstyle(1,15);
	floodfill(7,7,15);
	setfillstyle(1,4);
	floodfill(12,12,15);
	settextstyle(0,0,2);
	outtextxy(20,200,"Let's Check Your Circuit Solving Skill!!!");
	rectangle(250,300,380,340);	//continue tab
	rectangle(247,297,383,343);
	setfillstyle(1,4);
	floodfill(248,298,15);
	setfillstyle(1,2);
	floodfill(255,305,15);
	settextstyle(0,0,1);
	outtextxy(275,315,"Continue...");

	setfillstyle(1,4);
	rectangle(610,10,630,25);       //X button
	floodfill(613,13,15);           //X button colour
	rectangle(608,8,632,27);	//
	line(611,11,629,24);            // X button
	line(611,26,629,11);           //

	rectangle(500,440,550,465);
	floodfill(505,445,15);     	//back button
	outtextxy(510,449,"Back");
	showmouseptr();
	while(b_loop3)
	{
		showmouseptr();
		getmousepos(&button,&x,&y);
		if(button==1)
		{
			if(((x>245)&&(x<385))&&((y>295)&&(y<345))) //continue
			{
				hidemouseptr();
				b_loop3=0;
				fun_call();
				break;
			}
			else
			if(((x>500)&&(x<550))&&((y>440)&&(y<465))) //back button
			{
				hidemouseptr();
				b_loop3=0;
				study_zone();
				break;
			}
			else
			if(((x>605)&&(x<635))&&((y>5)&&(y<30)))//exit button
			{
				hidemouseptr();
				b_loop3=0;
				mainpage();
				break;
			}
		}
	}
	//getch();
}



/****************************************************************************
*****************************End_of_BEE_Section******************************
****************************************************************************/





/**************************LASER PROJECTS*****************************
*********************************************************************
*************************************************************************
*********************************************************************/
void projectwork1()
{
	cleardevice();
setbkcolor(BLUE);
    setcolor(WHITE);
    circle(170,230,8);

    setfillstyle(1,YELLOW);
    floodfill(170,230,WHITE);
    setcolor(GREEN);
    settextstyle(11,0,2);
    outtextxy(150,250,"PHOTON");
    delay(2000);

    settextstyle(7,0,4);
    setcolor(WHITE);
    outtextxy(110,380,"Amplification of Photons");
    delay(1000);

    setcolor(WHITE);
    circle(250,180,8);     //SECOND_UP
    circle(250,280,8);
    floodfill(250,180,WHITE);
    floodfill(250,280,WHITE);
    delay(500);

    circle(330,120,8);     //THIRD_UP
    circle(330,195,8);

    circle(330,265,8);
    circle(330,340,8);     //THIRD_DOWN

    floodfill(330,120,WHITE);
    floodfill(330,195,WHITE);
    floodfill(330,265,WHITE);
    floodfill(330,340,WHITE);
    delay(500);

    circle(410,80,8);
    circle(410,125,8);
    circle(410,165,8);
    circle(410,210,8);

    circle(410,245,8);
    circle(410,285,8);
    circle(410,325,8);
    circle(410,370,8);

    floodfill(410,80,WHITE);
    floodfill(410,125,WHITE);
    floodfill(410,165,WHITE);
    floodfill(410,210,WHITE);
    floodfill(410,245,WHITE);
    floodfill(410,285,WHITE);
    floodfill(410,325,WHITE);
    floodfill(410,370,WHITE);


    delay(3000);
    cleardevice();
}
/*********************************************************************
**************************************************************/
void projectwork2()
{
	 setbkcolor(BLUE);
     setcolor(WHITE);

     setfillstyle(1,RED);        // ATOM
     circle(310,230,30);
     floodfill(310,230,WHITE);
     setcolor(YELLOW);
     settextstyle(11,0,2);
     outtextxy(296,270,"ATOM");

     setcolor(WHITE);
     setfillstyle(1,GREEN);     // PHOTON
     circle(190,110,5);
     floodfill(190,110,WHITE);
     setcolor(GREEN);
     outtextxy(170,120,"PHOTON");
     delay(2000);
     setcolor(BLUE);
     outtextxy(170,120,"PHOTON");
     setfillstyle(1,BLACK);
     floodfill(190,110,WHITE);
     setcolor(BLACK);
     circle(190,110,5);
     setcolor(WHITE);
     circle(210,130,5);
     setfillstyle(1,GREEN);
     floodfill(210,130,WHITE);
     delay(300);
     setfillstyle(1,BLACK);
     floodfill(210,130,WHITE);
     setcolor(BLACK);
     circle(210,130,5);
     setcolor(WHITE);
     circle(230,150,5);
     setfillstyle(1,GREEN);
     floodfill(230,150,WHITE);
     delay(300);
     setfillstyle(1,BLACK);
     floodfill(230,150,WHITE);
     setcolor(BLACK);
     circle(230,150,5);
     setcolor(WHITE);
     circle(250,170,5);
     setfillstyle(1,GREEN);
     floodfill(250,170,WHITE);
     delay(300);
     setfillstyle(1,BLACK);
     floodfill(250,170,WHITE);
     setcolor(BLACK);
     circle(250,170,5);
     setcolor(WHITE);
     circle(270,190,5);
     setfillstyle(1,GREEN);
     floodfill(270,190,WHITE);
     delay(300);
     setfillstyle(1,BLACK);
     floodfill(270,190,WHITE);
     setcolor(BLACK);
     circle(270,190,5);
     setcolor(WHITE);
     circle(295,215,5);
     setfillstyle(1,GREEN);
     floodfill(295,215,WHITE);
     delay(300);
     setfillstyle(1,RED);
     floodfill(295,215,WHITE);
     setcolor(RED);
     circle(295,215,5);
     setcolor(WHITE);
     setfillstyle(1,YELLOW);        // ATOM
     circle(310,230,30);
     floodfill(310,230,WHITE);
     setcolor(YELLOW);
     settextstyle(7,0,3);
     outtextxy(115,50,"Stimulation of ATOM to Release Photons");
     setcolor(WHITE);
     delay(300);
     setfillstyle(1,RED);        // ATOM
     circle(310,230,30);
     floodfill(310,230,WHITE);
     setcolor(WHITE);
     circle(346,225,5);
     setfillstyle(1,GREEN);
     floodfill(346,225,WHITE);
     circle(346,235,5);
     floodfill(346,235,WHITE);
     delay(800);
     setfillstyle(1,BLACK);
     floodfill(346,225,WHITE);
     floodfill(346,235,WHITE);
     setcolor(BLACK);
     circle(346,225,5);
     circle(346,235,5);
     setcolor(WHITE);
     circle(365,205,5);
     setfillstyle(1,GREEN);
     floodfill(365,205,WHITE);
     circle(365,255,5);
     floodfill(365,255,WHITE);
     delay(300);
     setfillstyle(1,BLACK);
     floodfill(365,205,WHITE);
     floodfill(365,255,WHITE);
     setcolor(BLACK);
     circle(365,205,5);
     circle(365,255,5);
     setcolor(WHITE);
     circle(385,185,5);
     setfillstyle(1,GREEN);
     floodfill(385,185,WHITE);
     circle(385,275,5);
     floodfill(385,275,WHITE);
     delay(300);
     setfillstyle(1,BLACK);
     floodfill(385,185,WHITE);
     floodfill(385,275,WHITE);
     setcolor(BLACK);
     circle(385,185,5);
     circle(385,275,5);
     setcolor(WHITE);
     circle(405,165,5);
     setfillstyle(1,GREEN);
     floodfill(405,165,WHITE);
     circle(405,295,5);
     floodfill(405,295,WHITE);
     delay(300);
     setfillstyle(1,BLACK);
     floodfill(405,165,WHITE);
     floodfill(405,295,WHITE);
     setcolor(BLACK);
     circle(405,165,5);
     circle(405,295,5);
     setcolor(WHITE);
     circle(425,145,5);
     setfillstyle(1,GREEN);
     floodfill(425,145,WHITE);
     circle(425,315,5);
     floodfill(425,315,WHITE);
     delay(300);
     setfillstyle(1,BLACK);
     floodfill(425,145,WHITE);
     floodfill(425,315,WHITE);
     setcolor(BLACK);
     circle(425,145,5);
     circle(425,315,5);
     setcolor(WHITE);
     circle(445,125,5);
     setfillstyle(1,GREEN);
     floodfill(445,125,WHITE);
     circle(445,335,5);
     floodfill(445,335,WHITE);
     delay(300);
     setfillstyle(1,BLACK);
     floodfill(445,125,WHITE);
     floodfill(445,335,WHITE);
     setcolor(BLACK);
     circle(445,125,5);
     circle(445,335,5);
     setcolor(WHITE);
     circle(465,105,5);
     setfillstyle(1,GREEN);
     floodfill(465,105,WHITE);
     circle(465,355,5);
     floodfill(465,355,WHITE);
     delay(300);
     setfillstyle(1,BLACK);
     floodfill(465,105,WHITE);
     floodfill(465,355,WHITE);
     setcolor(BLACK);
     circle(465,105,5);
     circle(465,355,5);
     setcolor(WHITE);
     circle(485,95,5);
     setfillstyle(1,GREEN);
     floodfill(485,95,WHITE);
     circle(485,375,5);
     floodfill(485,375,WHITE);
     circle(190,110,5);
     floodfill(190,110,WHITE);
     setcolor(YELLOW);
     settextstyle(11,0,2);
     outtextxy(170,120,"PHOTON");
     outtextxy(465,110,"PHOTON");
     outtextxy(465,390,"PHOTON");
     delay(5000);
     cleardevice();
}
/*********************************************************************
********************************************************************/
void projectwork3()
{

	int gd=DETECT,gm;
     setbkcolor(BLACK);
     setcolor(WHITE);
     rectangle(200,150,460,160);
     rectangle(200,300,460,310);
     setfillstyle(1,GREEN);
     floodfill(250,155,WHITE);
     floodfill(250,305,WHITE);
     ellipse(200,230,90,89,15,70);      //MIRROR
     setfillstyle(1,BLUE);
     floodfill(205,232,WHITE);
     ellipse(460,230,90,89,15,70);      // SEMI SILVERED MIRROR
     setfillstyle(1,CYAN);
     floodfill(465,232,WHITE);
     rectangle(300,365,360,380);       //  POWER SOURCE
     setfillstyle(1,RED);
     floodfill(305,370,WHITE);
     moveto(300,365);
     lineto(310,355);
     lineto(370,355);
     lineto(360,365);
     moveto(360,380);
     lineto(370,370);
     lineto(370,355);
     floodfill(305,362,WHITE);
     floodfill(366,370,WHITE);
     setcolor(YELLOW);
     settextstyle(11,0,2);
     outtextxy(288,390,"POWER SOURCE");
     outtextxy(300,120,"ELECTRODES");
     outtextxy(130,230,"MIRROR");
     outtextxy(480,175,"SEMI SILVERED");
     outtextxy(510,190,"MIRROR");
     setcolor(WHITE);
     moveto(370,363);
     lineto(411,363);
     lineto(411,265);
     moveto(370,366);
     lineto(413,366);
     lineto(413,265);

     rectangle(395,260,428,265);
     floodfill(396,261,WHITE);
     rectangle(395,200,428,205);
     floodfill(396,201,WHITE);
     rectangle(240,260,273,265);
     floodfill(241,261,WHITE);
     rectangle(240,200,273,205);
     floodfill(241,201,WHITE);


     moveto(255,265);
     lineto(255,376);
     lineto(300,376);
     moveto(257,265);
     lineto(257,373);
     lineto(300,373);

     setcolor(RED);

     moveto(280,205);
     lineto(280,260);
     lineto(273,260);
     moveto(273,205);
     lineto(280,205);

     moveto(435,205);
     lineto(435,260);
     lineto(428,260);
     moveto(428,205);
     lineto(435,205);

     setcolor(WHITE);
     circle(100,50,8);
     setfillstyle(1,RED);
     floodfill(100,50,WHITE);
     circle(100,85,3);
     setfillstyle(1,YELLOW);
     floodfill(100,85,WHITE);
     setcolor(YELLOW);
     outtextxy(128,47,"ATOM");
     outtextxy(128,82,"PHOTON");


//  ATOM AND PHOTON MOVEMENT

     setcolor(WHITE);
     setfillstyle(1,RED);    //ATOM
     circle(365,205,8);
     floodfill(365,205,WHITE);

     circle(325,285,8);
     floodfill(325,285,WHITE);
     delay(3000);

     circle(325,260,8);
     floodfill(325,260,WHITE);

     setfillstyle(1,BLACK);
     floodfill(325,285,WHITE);
     setcolor(BLACK);
     circle(325,285,8);

     setcolor(WHITE);

     setfillstyle(1,RED);
     circle(345,190,8);
     floodfill(345,190,WHITE);
     setfillstyle(1,BLACK);
     floodfill(365,205,WHITE);
     setcolor(BLACK);
     circle(365,205,8);
     delay(500);


     setfillstyle(1,RED);
     setcolor(WHITE);
     circle(325,170,8);
     floodfill(325,170,WHITE);
     setfillstyle(1,BLACK);
     floodfill(345,190,WHITE);
     setcolor(BLACK);
     circle(345,190,8);


     setcolor(WHITE);
     setfillstyle(1,YELLOW);
     circle(250,250,3);
     floodfill(250,250,WHITE);
     delay(100);
     circle(275,225,3);
     floodfill(275,225,WHITE);
     delay(100);
     circle(295,205,3);
     floodfill(295,205,WHITE);
     delay(100);
     circle(315,185,3);
     floodfill(315,185,WHITE);
     delay(100);
     circle(320,205,3);
     floodfill(320,205,WHITE);
     delay(100);
     circle(345,205,3);
     floodfill(345,205,WHITE);
     circle(365,205,3);
     floodfill(365,205,WHITE);
     delay(100);
     circle(385,210,3);
     floodfill(385,210,WHITE);

     circle(395,220,3);
     floodfill(395,220,WHITE);
     circle(305,225,3);
     floodfill(305,225,WHITE);

     circle(325,245,3);
     floodfill(325,245,WHITE);
     delay(100);
     circle(345,265,3);
     floodfill(345,265,WHITE);
     delay(100);
     circle(345,235,3);
     floodfill(345,235,WHITE);
     delay(100);
     circle(365,285,3);
     floodfill(365,285,WHITE);
     circle(365,230,3);
     floodfill(365,230,WHITE);
     delay(100);
     circle(395,245,3);
     floodfill(395,245,WHITE);
     delay(100);
     circle(415,225,3);
     floodfill(415,225,WHITE);
     delay(100);
     circle(425,245,3);
     floodfill(425,245,WHITE);
     delay(300);

     setlinestyle(SOLID_LINE,1,3);
     setcolor(YELLOW);
     moveto(460,230);
     lineto(600,230);      //LASER
     setcolor(YELLOW);
     outtextxy(510,240,"LASER");
     moveto(540,230);
     lineto(535,225);
     moveto(540,230);
     lineto(535,235);
     delay(3000);
     cleardevice();

}


/*************************************************************************
**************************Playing numbers*******************************
**************************************************************************/
void playnum()
{
	int i=8,rval,flag=0;
	int button,x,y;
	int val;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"");
		cleardevice();
	setbkcolor(0);

	settextstyle(BOLD_FONT,0,3);
	outtextxy(160,40,"Guess the Number !!!");

	randomize();
	rval=random(99);

	gotoxy(17,8);
	//clrscr();
	printf("Welcome to the guessing game");
	printf("\n Rules:\n 1. Guess the number which is between 1 to 100 ");
	printf("\n 2. Only 8 chances to guess the randomly generated number");
	printf("\n 3. You can win the game when the number guessed is same as the random no.");
	printf("\n 4. Hints will be provided during the PLAY.");
	printf("\n  Good Luck Start Guessing");
	for(i=1;i<=8;i++)
	{
		printf("\n\n Guess %d ? ",i);
		scanf("%d",&val);


			if(val>rval)
				printf("Your value is Greater than the generated number");
			else if(val<rval)
				printf("Your value is Less than the generated value");
			else if(val==rval)
			{
			 flag=1;
			 break;
			}

	}

	       clrscr();


		if(flag==1)
		{

			cleardevice();
			settextstyle(BOLD_FONT,0,3);
			outtextxy(160,40,"Guess the Number !!!");
			settextstyle(SIMPLEX_FONT,0,3);
			outtextxy(145,145,"You Are Winner");
			outtextxy(145,178," NO. of tries");
			gotoxy(35,13);
			printf("%d",i);

		       //try again
			rectangle(190,250,300,280);
			settextstyle(TRIPLEX_FONT,0,1);
			outtextxy(200,250,"Try again");
		       //quit
			rectangle(340,250,420,280);
			settextstyle(TRIPLEX_FONT,0,1);
			outtextxy(350,250," Quit");

		   }
		else
		{       cleardevice();
			settextstyle(BOLD_FONT,0,3);
			outtextxy(160,40,"Guess the Number !!!");
			settextstyle(SIMPLEX_FONT,0,3);
			outtextxy(180,180,"Sorry 8 chances over..You LOOSE.");

		       //try again
			rectangle(190,250,300,280);
			settextstyle(TRIPLEX_FONT,0,1);
			outtextxy(200,250,"Try again");
		       //quit
			rectangle(340,250,420,280);
			settextstyle(TRIPLEX_FONT,0,1);
			outtextxy(350,250," Quit");
		}
		showmouseptr();
		while(1)
		{
			getmousepos(&button,&x,&y);
			if(button==1)
			{
				if(x>190&&x<300&&y>250&&y<280)
				{
				      sound(650);
				      delay(400);
				      nosound();
				      hidemouse();
				      cleardevice();
				      closegraph();
				      playnum();
				      break;
				}
			else if(x>340&&x<420&&y>250&&y<280)
				{
					sound(650);
					delay(400);
					nosound();
					hidemouse();
					cleardevice();
					setbkcolor(0);
					closegraph();
					maths();
					break;
				}
			else;
		    }//End Of if
		}//END OF WHILE


}

/************************************************************************
*************************End_of_playing_with_number**********************
************************************************************************/



/************************************************************************
*****************************History_zone********************************
************************************************************************/
void history()
{
	//cleardevice();

		int loop=1,loop2=1,x,y,button;
		int gd=DETECT,gm;
		initgraph(&gd,&gm,"");
	cleardevice();
	rectangle(5,5,635,475);
	setfillstyle(1,8);
	floodfill(10,10,15);
	setfillstyle(1,2);
	rectangle(200,200,400,240);
	rectangle(200,300,400,340);
	floodfill(202,202,15);
	floodfill(202,302,15);
	settextstyle(SANS_SERIF_FONT,0,2);
	outtextxy(220,200,"History of Fire");
	outtextxy(220,300,"History of Wheel");
	rectangle(500,440,550,465);	//back
	floodfill(502,442,15);
	settextstyle(SANS_SERIF_FONT,0,5);
	outtextxy(250,100,"HISTORY");
	settextstyle(0,0,1);
	outtextxy(505,445,"Back");

	while(loop)
	{
		showmouseptr();
		getmousepos(&button,&x,&y);
		if(button==1)
		{
			if(x>200&&x<400&&y>200,y<240)
			{
				loop=0;
				hidemouseptr();
				closegraph();
				fire();
				break;
			}
			else if(x>500&&x<550&&y>440&&y<465)//back
			{
				loop=0;
				hidemouseptr();
				closegraph();
				study_zone();
				break;
			}
		}
	}

}



void fire()
{
	void *p;
	void *l;
	void *m;
	int size1;
    int gd=DETECT,gm;
	int poly1[10]={400,360,400,320,495,275,495,290,400,360};
	int poly2[10]={495,290,495,275,590,320,590,360,495,290};
	int poly3[10]={475,429,490,295,500,295,515,429,475,429};
      initgraph(&gd,&gm,"");
	setbkcolor(4);
	arc(200,200,315,55,100);
	arc(350,200,125,255,100);
       //	rectangle(248,132,302,267);
	size1=imagesize(248,132,302,267);
	p=malloc(size1);
	getimage(248,132,302,267,p);
	cleardevice();
	setbkcolor(0);
       //	putimage(248,132,p,0);
	arc(200,178,308,55,120);
	arc(350,178,125,255,120);
       //	rectangle(227,83,323,273);
	size1=imagesize(227,83,323,273);
	l=malloc(size1);
	getimage(227,83,323,273,l);
	cleardevice();
	arc(200,222,315,55,85);
	arc(350,222,125,255,85);
     //  rectangle(262,180,287,265);
       size1=imagesize(262,180,287,265);
       m=malloc(size1);
       getimage(262,180,287,265,m);
       cleardevice();
       setbkcolor(6);
      // putimage(482,180,m,1);//small flame
      // putimage(447,83,l,1); //big flame
      // putimage(468,132,p,1); //middle flame
      // putpixel(490,210,15);   //small dot point
      // putpixel(490,183,15);   //middle dot point
      // putpixel(490,120,15);   //big dot point
       //floodfill(490,210,15);
       cleardevice();
       while(!kbhit())
       {
	  cleardevice();
	  setfillstyle(6,6);
	  fillpoly(5,poly1);
	  fillpoly(5,poly2);
	  fillpoly(5,poly3);
	  setbkcolor(0);
	  setfillstyle(1,4);
	  putimage(482,180,m,1);
	  floodfill(490,210,15);
	  delay(800);
	  setfillstyle(1,14);
	  putimage(468,132,p,1);
	  floodfill(490,183,15);
	  delay(400);
	  setfillstyle(1,6);
	  putimage(447,83,l,1);
	  floodfill(490,120,15);
	  delay(200);
       }
       cleardevice();
       setbkcolor(0);
       setfillstyle(6,6);
       fillpoly(5,poly1);
       fillpoly(5,poly2);
       fillpoly(5,poly3);
       setfillstyle(1,4);
       putimage(482,180,m,1);
       floodfill(490,210,15);
       delay(800);
       setfillstyle(1,14);
       putimage(468,132,p,1);
       floodfill(490,183,15);
       delay(400);
       setfillstyle(1,6);
       putimage(447,83,l,1);
       floodfill(490,120,15);
       delay(400);
       getch();
      //  rectangle(400,280,490,310);
      //rectangle(455,300,535,429);

       getch();
       while(!kbhit())
	{
		setfillstyle(6,6);
		fillpoly(5,poly1);
		fillpoly(5,poly2);
		fillpoly(5,poly3);
		setfillstyle(1,6);
		floodfill(490,210,15);
		delay(200);
		setfillstyle(1,14);
		floodfill(490,183,15);
		delay(200);
		setfillstyle(1,4);
		floodfill(490,120,15);
		delay(200);
		//************next pat*********
		setfillstyle(1,14);
		floodfill(490,210,15);
		delay(200);
		setfillstyle(1,4);
		floodfill(490,183,15);
		delay(200);
		setfillstyle(1,6);
		floodfill(490,120,15);
		delay(200);
      //***************next pat***********
      }
      getch();
      closegraph();
      history();

}



/*******************************************************************************
*******************************End of fire**************************************
*******************************************************************************/


/************************************************************************
**************************************************************************
**********************MUSIC WITH NAME************************************
*************************************************************************
*************************************************************************/
void mname()
{
	char name[50];
	int j,y1=1;
	int button,xpos,ypos;
	int x[8]={240,270,300,320,360,400,450,480};
       int gd=DETECT,gm;
       //	closegraph();
	initgraph(&gd,&gm,"");
	rectangle(8,8,getmaxx()-8,getmaxy()-8);
	rectangle(10,10,getmaxx()-10,getmaxy()-10);
	settextstyle(BOLD_FONT,0,3);
	setcolor(2);
	outtextxy(155,30,"Music with Names");
	settextstyle(SANS_SERIF_FONT,0,3);
	setcolor(13);
	outtextxy(100,110,"Do you know your name also has music.. ");
	outtextxy(150,130," Lets try... ");
	setcolor(15);
	outtextxy(100,213,"Enter your Name: ");
	settextstyle(0,0,1);
	rectangle(500,440,550,465);
	outtextxy(510,449,"BACK");
	gotoxy(39,15);
	getch();

	scanf("%s",&name);
	setcolor(12);
	settextstyle(SANS_SERIF_FONT,0,3);
	outtextxy(100,240,"The tone of your name is......");
	while(y1<=3)
	{
		for(j=0;name[j]!='\0';j++)
		{
			sound(x[name[j]%8]);
			delay(400);
			nosound();
			delay(40);
		}
		y1++;
		delay(20);
	}

	showmouseptr();
	while(1)
	{
		getmousepos(&button,&xpos,&ypos);
		if(button==1)
		{
			if(xpos>500&&xpos<550&&ypos>440&&ypos<465)
			{
				sound(650);
				delay(400);
				nosound();
				closegraph();
				music_zone();
				break;
			}
			else;
		}
	}


}
/*************************************************************************
**************************************************************************
*********************MUSIC WITH NUMBERS*************************************
****************************************************************************
************************************************************************/
void mnum()
{

	int a[10],i,j,x,y,xpos,ypos,button;
	int srgm[8]={240,270,300,320,360,400,450,480};
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"");
	cleardevice();
	setbkcolor(0);

	rectangle(0,0,639,200);
	settextstyle(TRIPLEX_FONT,0,5);
	outtextxy(180,8,"MUSICAL NUMBERS");
	settextstyle(0,0,1);
	outtextxy(10,100,"1.Music and numbers have a great combination.");
	outtextxy(10,110,"2.WANNA SEE");
	outtextxy(10,120,"3.Enter 10 numbers in a queue");
	outtextxy(10,130,"4.Wait for them to show their magic");
	outtextxy(10,140,"5.WARNING!Dont enter any character or else the program will terminate");
	outtextxy(10,210,"ENTER BELOW  | ");
	outtextxy(10,220,"            \\|/");
	gotoxy(10,15);
	for(i=0;i<10;i++)
	{
		gotoxy(10,15+i);
		scanf("%d",&a[i]);

	}
	i=0;

	cleardevice();
	rectangle(0,0,639,200);
	settextstyle(TRIPLEX_FONT,0,5);
	outtextxy(180,8,"MUSICAL NUMBERS");

		while(i<10)
		{
		sound(srgm[a[i]%8]);
		delay(200);
		       x=rand()%639;
		       y=rand()%279+200+40;
		for(j=0;j<40;j++)
		{
		  rectangle(0,0,639,200);
		outtextxy(180,8,"MUSICAL NUMBERS");
		  circle(x,y,0+j);
		  delay(5);
		}

		nosound();
		i++;
		}
			settextstyle(0,0,1);
			rectangle(500,440,550,465);
			outtextxy(510,449,"BACK");
		showmouseptr();
		while(1)
		{
			getmousepos(&button,&xpos,&ypos);
			if(button==1)
			{
			      if(xpos>500&&xpos<550&&ypos>440&&ypos<465)
			      {
					sound(650);
					delay(300);
					nosound();
					cleardevice();
					setbkcolor(0);
					closegraph();
					music_zone();
					break;
			      }
				else;
			}
		}

 }
 /************************************************************************
 **************************************************************************
 ******************    IPIANO   **********************************************
 ***********************************************************************
 *************************************************************************/
void piano()
{
		char a;
      int gd=DETECT,gm;
	int i,c=0,button,x,y;
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
	 outtextxy(100,50,"PRESS X TO TERMINATE PIANO");
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
	settextstyle(0,0,1);
			rectangle(500,440,550,465);
			outtextxy(510,449,"BACK");
	showmouseptr();
	while(1)
	{
		getmousepos(&button,&x,&y);
		if(button==1)
		{
			if(x>500&&x<550&&y>440&&y<465)
			{
				sound(650);
				delay(300);
				nosound();
				hidemouse();
				cleardevice();
				setbkcolor(0);
				closegraph();
				music_zone();
				break;
			  }
			  else;
		}
	}

}
/******************************************************
***********************************************************************
*************animation*****************************
**********************************************************/
void animation_zone()
{
int a=10,b=10,button,x,y;
int gd=DETECT,gm;

initgraph(&gd,&gm,"");
cleardevice();
setbkcolor(0);

settextstyle(TRIPLEX_FONT,0,1);
outtextxy(352,432,"BACK");
rectangle(350,430,402,460);


settextstyle(TRIPLEX_FONT,0,5);
outtextxy(170,45,"ANIMATIONS");
settextstyle(TRIPLEX_FONT,0,3);


setfillstyle(1,4);
rectangle(80,140,250,200); //smiley
floodfill(125,151,15);
outtextxy(125,151,"SMILEY");

rectangle(80,220,273,280);  //bouncing ball
floodfill(90,235,15);
outtextxy(90,235,"BOUNCING BALL");

rectangle(80,300,250,360);    //moving car
floodfill(90,315,15);
outtextxy(90,315,"MOVING CAR");




     setmousepos(&a,&b);

    showmouseptr();
while(1)
{
    getmousepos(&button,&x,&y);
    if(button==1)
    {
    if(x>80&&y>140&&x<250&&y<200)
    {
      hidemouse();
    setfillstyle(1,6);
    sound(650);
    outtextxy(125,151,"SMILEY");
    floodfill(125,151,15);
    delay(400);
    nosound();
    closegraph();
    ismile();
    break;
    }

    else if(x>80&&y>220&&x<273&&y<280)
    {
     hidemouse();
     sound(650);
    setfillstyle(1,6);
    floodfill(90,235,15);
    outtextxy(90,235,"BOUNCING BALL");
    delay(400);
    nosound();
   // printf("ball");
   closegraph();

   ibal();
   break;
    }

    else if(x>80&&y>300&&x<250&&y<360)
    {
     hidemouse();
     sound(650);
    setfillstyle(1,6);
    floodfill(90,315,15);
    delay(400);
    nosound();
    closegraph();
     icar();
     break;
//    printf("car");
 //   break;
    }

    else if(x>350&&y>430&&x<402&&y<460)
    {
     sound(650);
     delay(400);
     nosound();
     hidemouse();
     cleardevice();
     setbkcolor(0);
     closegraph();
     mainpage();
     break;
    }

  }


}


}



void ismile()
{



       int gd=DETECT,gm;
       int x,y,c,i=0;


	initgraph(&gd,&gm,"");
	 cleardevice();
       setbkcolor(0);
	x=getmaxx()/2;

	y=getmaxy()/2;

	circle(x,y,100);

	line(x-70,y-25,x-40,y-25);
	line(x+70,y-25,x+40,y-25);

	line(x-25,y+30,x+25,y+30);





       //	arc(x,y,225,315,70);smile



	cleardevice();
	 settextstyle(1,HORIZ_DIR,1);

	outtextxy(25,240,"Press any key to make the face smile");
	outtextxy(25,260,"Press x to quit");

	while(1)
	{


	 c=getch();



	 if(c!='x')
	 {

	while(i>=0&&i<20)
	{
	cleardevice();


	settextstyle(DEFAULT_FONT,HORIZ_DIR,1);

	outtextxy(200,25,"A:: Smile and Cheeks up S::Cheeks Down");
	setfillstyle(1,14);
	circle(x,y,100);
	floodfill(x,y,15);
	setfillstyle(1,4);
	circle(x-45,y-25,6+i);
	floodfill(x-45,y-28+i+1,15);
	circle(x+45,y-25,6+i);
	floodfill(x+45,y-28+i+1,15);


	setfillstyle(1,7);
	setcolor(6);

	circle(x-45,y-28,i);   //i
	floodfill(x-45,y-28,6);
	circle(x+45,y-28,i);   // i
	floodfill(x+45,y-28,6);
	setcolor(15);
	setcolor(4);
	arc(x,y-i,225-i,315+i,70);
	setcolor(15);
	c=getch();

	if(c=='a')
	i++;
	else if(c=='s')
	i--;
	else if(c=='x')
	break;

	}
	if(c=='a')
	i=19;
	else if(c=='s')
	i=1;
	else if(c=='x')
	break;
	}

	else
	break;

	}
       //	getch();
       closegraph();
	animation_zone();

}



void icar()
{
	int i,j=0,gd=DETECT,gm;
	initgraph(&gd,&gm,"");
	cleardevice();
	setbkcolor(0);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
	outtextxy(25,240,"press any key to view moving car");
	getch();
	while(1)
	{
		while(!kbhit())
		{
			for(i=0;i<=420;i=i+10,j++)      //front moving car
			{
				outtextxy(2,200,"press key to stop......");

				rectangle(50+i,275,150+i,400);
				rectangle(150+i,350,200+i,400);
				circle(75+i,410,10);
				circle(175+i,410,10);
				setcolor(j);
				delay(100);
				if(i==420)
				break;
				if(j==15)
				j=2;
				cleardevice();//clear screen
			}


			for(i=420;i>=0;i=i-10,j++)     //backmoving car
			{
				outtextxy(2,200,"press key to stop......");
				rectangle(50+i,275,150+i,400);
				rectangle(150+i,350,200+i,400);
				circle(75+i,410,10);
				circle(175+i,410,10);
				setcolor(j);
				delay(100);
				if(i==0)
				break;
				if(j==15)
				j=2;
				cleardevice();//clear screen
			}

		}

		break;
	}
	cleardevice();
	setbkcolor(0);
	closegraph();
	animation_zone();
}



void ibal()
{



       int gd=DETECT,gm;

	float x=1,y=0.00000,j=0.5,count=0.1;
	float r=10,i;
	int k;

	initgraph(&gd,&gm,"");
	 cleardevice();
       setbkcolor(0);
	setcolor(10);

	line(0,415,650,415);
	sleep(1) ;


	for(k=0;k<=7;k++)
	{

	  for(i=90;i<270;i+=10)
	  {

	       y=cos(((i*22/7)/180))/j;

		 if(y>0)
		 y=-y;

		 x+=5;

		 setcolor(10);
		 setfillstyle(1,10);
		 circle(x,y*100+400,r);
		 floodfill(x,y*100+400,10);
		 delay(100);

		 setcolor(5);
		 setfillstyle(1,0);
		 circle(x,y*100+400,r);
		 floodfill(x,y*100+400,5);

	  }

	  j+=count;
	  count +=0.1;
	}
       //	getch();
	cleardevice();
	setbkcolor(0);
	closegraph();
	animation_zone();

}
/***********************HOROS INPUT FUNC********************************/
/*void input()
{
	int d,  m;
	gotoxy(18,14);
	scanf("%d",&d);
	gotoxy(18,19);
	scanf("%d",&m);
   //	gotoxy(20,23);
     //	printf("%d %d",d,m);
	horo(d,m);

}*/





/*********************************LAST***********************************/
