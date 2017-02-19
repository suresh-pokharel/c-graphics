#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
#include<time.h>
void clearscreen();
void timedelay();
void car(int x1,int y1,int x2,int y2,int obs);
void countdown();
void snowfall();
void rotatetyre(int x1,int y1,int x2,int y2,int i);
void obstacle(int x1,int y1,int x2,int y2,int obs);
void main(){
	int x1=5,y1=150,x2=155,y2=200,obs;
	int gdriver = DETECT,gmode;
	initgraph(&gdriver,&gmode,"C:\\TURBOC3\\BGI");
	setviewport(0,0,600,600,0);
	setbkcolor(0);
       //	printf("Press any key to start");
       //	getch();
	countdown();
	randomize();
	obs=400+rand()%300;//to generate the location for obstacle
	obstacle(x1,y1,x2,y2,obs);
	car(x1,y1,x2,y2,obs);
       // countdown();
	getch();
}//end of main

void obstacle(int x1,int y1,int x2,int y2,int obs){
	int i,ydiff;
	ydiff=y2-y1;
	randomize();
       //printf("%d",obs);
	setcolor(RED);
	line(obs,y1+ydiff,obs,y1); //for obstacle
	setcolor(GREEN);
	line(obs+1,y1+ydiff,obs+1,y1);//for obstacle
	setcolor(RED);
	line(obs+2,y1+ydiff,obs+2,y1); //for obstacle
	setcolor(GREEN);
	line(obs+3,y1+ydiff,obs+3,y1);//for obstacle
} //end of obstacle

void car(int x1,int y1,int x2,int y2,int obs){
	int tyre_radius,ysum,xsum,ydiff,xdiff,i=0;
	for(i=0;i<450;i++){
		clearscreen();

		x1=x1+1;
		x2=x2+1;
		ysum=y1+y2;
		xsum=x1+x2;
		ydiff=y2-y1;
		xdiff=x2-x1;
		tyre_radius=0.065*xdiff;
		line(x1-500,y1+ydiff,x2+500,y1+ydiff); //for road
		obstacle(x1,y1,x2,y2,obs);
		 //rectangle(x1,y1,x2,y2);
		 setcolor(BLUE);
		 line(x1,ysum/2,x2,ysum/2);//6
		 //line(x1,y1+0.8*ydiff,x2,y1+0.8*ydiff);

		ellipse(x1+0.2*xdiff,ysum/2,90,180,0.2*xdiff,ydiff/2);//1
		line(x1+0.2*xdiff,y1,x1+0.5*xdiff,y1);//2
		line(x1,y1+ydiff/2,x1,y1+0.8*ydiff);//7
		line(x2,y1+ydiff/2,x2,y1+0.8*ydiff);//8
		circle(x1+0.2*xdiff,y1+0.8*ydiff,tyre_radius);//9
		circle(x1+0.8*xdiff,y1+0.8*ydiff,tyre_radius);//10
		line(x1,y1+0.8*ydiff,x1+0.2*xdiff-tyre_radius,y1+0.8*ydiff);//11
		line(x1+0.2*xdiff+tyre_radius,y1+0.8*ydiff,x1+0.8*xdiff-tyre_radius,y1+0.8*ydiff);//12
		line(x1+0.8*xdiff+tyre_radius,y1+0.8*ydiff,x2,y1+0.8*ydiff);//13
		circle(x1+0.2*xdiff,y1+0.8*ydiff,0.055*xdiff);//14
		circle(x1+0.8*xdiff,y1+0.8*ydiff,0.055*xdiff);//15
		circle(x1+0.2*xdiff,y1+0.8*ydiff,1);//16
		circle(x1+0.8*xdiff,y1+0.8*ydiff,1);//17
		rectangle(x1+0.15*xdiff,y1+0.1*ydiff,x1+0.55*xdiff,y1+0.3*ydiff);//18
		line(x1+0.25*xdiff,y1+0.1*ydiff,x1+0.25*xdiff,y1+0.3*ydiff);//19
		line(x1+0.35*xdiff,y1+0.1*ydiff,x1+0.35*xdiff,y1+0.3*ydiff);//20
		line(x1+0.45*xdiff,y1+0.1*ydiff,x1+0.45*xdiff,y1+0.3*ydiff);//21
		ellipse(x1+0.5*xdiff,y1+0.4*ydiff,0,90,0.2*xdiff,0.4*ydiff);//3
		line(x1+0.7*xdiff,y1+0.4*ydiff,x1+0.96*xdiff,y1+0.4*ydiff);//4
		ellipse(x1+0.96*xdiff,y1+ydiff/2,0,90,0.04*xdiff,0.1*ydiff);//5
		rotatetyre(x1,y1,x2,y2,i);
	       //	snowfall();
		delay(40);//30
	       //	timedelay();
		if(x2>obs-10){
		      break;
		}

	}//end for loop
} //end of moving car

void clearscreen(){
	clearviewport();
}//end of clear screen
void countdown(){
	int i;
	char a[5];
	settextjustify( CENTER_TEXT, CENTER_TEXT);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,10);
	setcolor(GREEN);
	for(i=3;i>0;i--){
		sprintf(a,"%d",i);
		outtextxy(getmaxx()/2,getmaxy()/2,a);
		delay(1000);
		if(i==0){
		  break;
		}
		cleardevice();
	}

}
void rotatetyre(int x1,int y1,int x2,int y2,int i){
	int xdiff,ydiff,xt,yt;
	xdiff=x2-x1;
	ydiff=y2-y1;
	setcolor(GREEN);
	if(i%2==0){
	   xt= 0.039*xdiff;
	   yt= 0.036*xdiff;
	}
	else{
	   xt= 0.037*xdiff;
	   yt= 0.04*xdiff;
	}

	ellipse(x1+0.2*xdiff,y1+0.8*ydiff,0,360,xt,yt);
	ellipse(x1+0.8*xdiff,y1+0.8*ydiff,0,360,xt,yt);

}

void snowfall(){
	int i,x1,y1;
	randomize();
	x1=rand()%600-100;
	y1=rand()%5;
	for(i=0;i<5;i++){
	       //	circle(x1+4*i/3,y1+8*i,20);

	}
}

void timedelay(){
	int i;
	for(i=0;i<300;i++){
	  //do nothing
	}
}
