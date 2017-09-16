#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
#include<dos.h>
#include<time.h>
#include<math.h>

/***************************************FUNC*********************************
*********************************************************************/
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
	int86(0x88,&i,&o);
}

void main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"");
	paint();
}




void paint()
{
	int i=1,x,y,flag=0;
	int button,x1,y1;
	int size[4];
	//int gd=DETECT,gm;
	unsigned int size1;
       //	initgraph(&gd,&gm,"");
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
				paint();
				break;
		       }
		       else if(x>620&&x<635&&y>460&&y<475)
		       {
				 button=0;
				exit(0);
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
			 else if(x>620&&x<635&&y>460&&y<475)
		       {
				 button=0;
				exit(0);
		       }
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
			 else if(x>620&&x<635&&y>460&&y<475)
		       {
				 button=0;
				exit(0);
		       }
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
			 else if(x>620&&x<635&&y>460&&y<475)
		       {
				 button=0;
				exit(0);
		       }
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
			 else if(x>620&&x<635&&y>460&&y<475)
		       {
				 button=0;
				exit(0);
		       }
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
			 else if(x>620&&x<635&&y>460&&y<475)
		       {
				 button=0;
				exit(0);
		       }
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
			 else if(x>620&&x<635&&y>460&&y<475)
		       {
				 button=0;
				exit(0);
		       }
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
			 else if(x>620&&x<635&&y>460&&y<475)
		       {
				 button=0;
				exit(0);
		       }
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
			 else if(x>620&&x<635&&y>460&&y<475)
		       {
				 button=0;
				exit(0);
		       }
		}//end        of main if
	 }


}
/**************************************************************************
***********************GAME OVER***************************************
*******************************************************************/

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
