#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
int x,y,l=1;
int k=0;
int e=0,r;
int far * screen =(int far *) 0XB8000000;
int sx[100];
int sy[100];
int slen=2;
char n=49;
char c;
char funckey(int &T)
{
  char c=getch();
  if(c==0)
  {
   T=1;
   c=getch();
  }
  else
  T=0;
  return c;
}
void print(int x,int y,char c,int color , int islight ,int bycolor, int isblink)
{
  int v= color +8*islight+16*bycolor+128*isblink;
  screen[y*80+x]=v*256+c;
}
int getmove(char key,int isfunc)
{
  if(isfunc){
  switch(key){
  case'K': //left
  e=1;
  return 0;
  case 'H'://up
  e=1;
  return 1;
  case 'M' ://right
  e=1;
  return 2;
  case'P': //down
  e=1;
  return 3 ;
  }
  }
  return -1;
 }
void  movesnake(int move)
{
int hx=sx[0];
int hy=sy[0];
for (int i=slen-1 ; i>0;i--)
{
sx[i]=sx[i-1];
sy[i]=sy[i-1];
}
switch(move){
case 0: //chap;
hx--;
if(hx==-1)
hx=79;
break;
case 1: //bala
hy--;
if(hy==0)
hy=24;
break;
case 2://rast
hx++;
if(hx==80)
hx=0;
break;
case 3: //payin
hy++;
if(hy==25)
hy=1;
break;

}
sx[0]=hx;
sy[0]=hy;

}
void food(){
time_t t = time(NULL);
srand(t);
int yf=(rand()%25);
int xf=(rand()%80);

//int check=(rand()%25);
while(yf==0){
//if(yf==0){
yf=(rand()%25);
}
if(l==2)
{
while((xf==4 && yf==13)||(xf==20 && yf==17)||(xf==65 && yf==11)||(xf==30 && yf==2)||(xf==5 && yf==5)||(xf==13 && yf==4)||(xf==26 && yf==9)||(xf==9 && yf==14) )
{
xf=(rand()%80);
yf=(rand()%25);
}
}
for(int w=0; w<slen ;w++)
{
while(sx[w]==x &&sy[w]==y)
{
x++;
}
}
if(n<58)
{
print(xf,yf,n,7,0,0,0);
x=xf;
y=yf;
  }
 if(n==58)
 {
 print(xf,yf,'0',7,0,0,0);
x=xf;
y=yf;
 }



  }

void clear(){
for(int cls=0;cls<2000;cls++)
{
screen[cls]=0;
}
}

void printsnake(){
int isfunc;
print(sx[0],sy[0],'@',2,0,0,0);
for( int i=1;i<slen;i++)
{
print(sx[i],sy[i],'o',2,0,0,0);

}
}
void gameover(){
clear();
print(36,13,'g',2,0,0,0);
print(37,13,'a',2,0,0,0);
print(38,13,'m',2,0,0,0);
print(39,13,'e',2,0,0,0);
print(40,13,'o',2,0,0,0);
print(41,13,'v',2,0,0,0);
print(42,13,'e',2,0,0,0);
print(43,13,'r',2,0,0,0);
	    delay(1000);
}


void mane(){
print(4,13,'#',7,0,0,0);
print(20,17,'#',7,0,0,0);
print(65,11,'#',7,0,0,0);
print(30,2,'#',7,0,0,0);
print(5,5,'#',7,0,0,0);
print(13,4,'#',7,0,0,0);
print(26,9,'#',7,0,0,0);
print(9,14,'#',7,0,0,0);

}


void init()
{
clear();
if(l==1){
print(1,0,'l',4,0,2,0);
print(2,0,'e',4,0,2,0);
print(3,0,'v',4,0,2,0);
print(4,0,'e',4,0,2,0);
print(5,0,'l',4,0,2,0);
print(6,0,' ',4,0,2,0);
print(7,0,'[',4,0,2,0);
print(8,0,'1',4,0,2,1);
print(9,0,']',4,0,2,0);
}
else
{
print(1,0,'l',4,0,2,0);
print(2,0,'e',4,0,2,0);
print(3,0,'v',4,0,2,0);
print(4,0,'e',4,0,2,0);
print(5,0,'l',4,0,2,0);
print(6,0,' ',4,0,2,0);
print(7,0,'[',4,0,2,0);
print(8,0,'2',4,0,2,1);
print(9,0,']',4,0,2,0);
}

for(int in=0;in<100;in++){
sx[in]=0;
sy[in]=0;
}
for(int jn=0;jn<slen;jn++){
sy[jn]=12;
sx[jn]=40+jn;
}
food();
}
void win()
{
clear();
print(36,13,'y',7,0,0,0);
print(37,13,'o',7,0,0,0);
print(38,13,'u',7,0,0,0);
print(39,13,' ',7,0,0,0);
print(40,13,'w',7,0,0,0);
print(41,13,'i',7,0,0,0);
print(42,13,'n',7,0,0,0);
delay(1000);
}


void level2()
{
 clear();
 k++;
   l=2;
   slen=2;
   n=49;
   init();
}

int main()
{
init();
int isfunc;
c=funckey(isfunc);
int temp=getmove(c,isfunc);
r=temp;
while(c!=27){
r=temp;
movesnake(temp);
printsnake();
if(sx[0]==x && sy[0]==y)
{
if(n==58 && k==0)
{
level2();

}
else
{
n++;
food();
slen=slen+(n-49);
}
}
printsnake();
print(sx[slen-1],sy[slen-1],' ',0,0,0,0);
for(int y=1;y<slen;y++)
{
if(sx[0]==sx[y] && sy[0]==sy[y] && e!=0 )
{
gameover();
return 0;
}}
if(l==1){
delay(250);


}
else
{
delay(150);
mane();
if((sx[0]==4 && sy[0]==13)||(sx[0]==20 && sy[0]==17)||(sx[0]==65 && sy[0]==11)||(sx[0]==30 && sy[0]==2)||(sx[0]==5 && sy[0]==5)||(sx[0]==13 && sy[0]==4)||(sx[0]==26 && sy[0]==9)||(sx[0]==9 && sy[0]==14) )
{gameover();
return 0;
}
if(n>58 )
{
win();
return 0;
 }

}
if(kbhit())
{
c=funckey(isfunc);
int move=getmove(c,isfunc);
if (move != -1 && r-move != 2 && move-r != 2 )
temp=move;
}
}

return 0;

}
