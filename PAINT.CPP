#include <iostream.h>
#include <conio.h>
#include<dos.h>
#include<stdio.h>
#include<time.h>
int x=39,y=12,back=7,pen=1;
char c;
int far*s=(int far*)0xB8000000 ;
int o=32+256*(16*7+7);


void chapkon (x,y,c,color,bgcolor,islight,isblink)
{
 int v=color + 8*islight + 16*bgcolor +128*isblink ;
 s[y*80+x] = v*256 +c;
}

char funkey( int &T)
{
  char c=getch();
  if(c==0)
  {
   T=1;
   //funckey hast
   c=getch();
  }
   else
   T=0;
   //funckey nist
  return c;
}


char M[100];
struct stack
{
	int last;
	void init()
	{
	last=-1;
	}
	char A[10];
	int isempty()
	{
		return(last==-1);
	}
	int isfull()
	{
		return(last==9);
	}
	void push(char x)
	{       if(!isfull())
		{
		last++;
		A[last]=x;
		}
	}
	char pop(void)
	{

		char result=0;
		if(!isempty())
		{
			result=A[last];
			last--;
		}
		return result;
	}
}m,n;


void  edit()
{
	m.init();
	n.init();
	char a=0;
	int w,j=0;
	while (a!=13)//enter
	{

		for(int i=0;i<=m.last;i++)
		{
			chapkon(j+40,0,m.A[i],0,7,0);
			M[i]=m.A[i];
			j++;
		}
		gotoxy(j+40,1);
		for(i=n.last;i>=0;i--)
		{
			chapkon(j+40,0,n.A[i],0,7,0);
			M[i]=n.A[i];
			j++;
		}
		chapkon(j+40,0,0,7,7,0);
		M[j]='\0';

		a=funkey(w);
			j=0;
		if (a=='K')//chap
		{
			n.push(m.pop());
		}
		else if (a=='M') //rast
		{
			m.push(n.pop());
		}
		else if (a==8) //bs
			m.pop();
		else if (a=='S')
			n.pop(); //delete
		else
			m.push(a);


	 }
		 for(int i=0;i<10;i++) //bad inke inter zad sefid mikone
		{
			s[i+40]=256*17*7;
		 }


}



void load ()
{
 FILE *MY;
 edit();
 MY =fopen(M,"r");
 if(!MY)
{
chapkon(40,0,'n',0,7,0,0);
chapkon(41,0,'o',0,7,0,0);
chapkon(42,0,'t',0,7,0,0);
chapkon(43,0,'e',0,7,0,0);
chapkon(44,0,'x',0,7,0,0);
chapkon(45,0,'i',0,7,0,0);
chapkon(46,0,'s',0,7,0,0);
chapkon(47,0,'t',0,7,0,0);

}
 else {
	int z;
	for(int i=0;i<=24;i++)
	 for (int j=0;j<=79;j++)
	 {
		fscanf(MY,"%d",&z);
		s[i*80+j]=z;
	 }
	  fscanf(MY,"%d",&z);
	 int xf=z;
	 fscanf(MY,"%d",&z);
	 int yf=z;
	 fscanf(MY,"%d",&z);
	 int of=z;
	 s[yf*80+xf]=of;
  }


  fclose(MY);
}

void save ()
{
	edit();
	FILE*MY;
	MY=fopen(M,"w");
	if(!MY)
	{
	chapkon(40,0,'n',0,7,0,0);
	chapkon(41,0,'o',0,7,0,0);
	chapkon(42,0,'t',0,7,0,0);
	chapkon(43,0,'c',0,7,0,0);
	chapkon(44,0,'r',0,7,0,0);
	chapkon(45,0,'e',0,7,0,0);
	chapkon(46,0,'a',0,7,0,0);
	chapkon(47,0,'t',0,7,0,0);
	chapkon(47,0,'e',0,7,0,0);
	chapkon(47,0,'d',0,7,0,0);

	}
	else {
		for(int i=0;i<=24;i++)
			for (int j=0;j<=79;j++)
				fprintf(MY,"%d ",s[i*80+j]);
				fprintf(MY,"%d ",x);
				fprintf(MY,"%d ",y);
				fprintf(MY,"%d ",o);

	}
	fclose(MY);
}


void first()
{
 for(int i=0;i<80;i++)
	{
		for( int j=0;j<25;j++)
			{
				chapkon(i,j,32,7,7,0,0);
			}
	 }

for(int a=1;a<=2;a++)
	{
		for(int b=0;b<1;b++)
			{
				chapkon(a,b,' ',0,0,0,0);
			}
	}
chapkon(3,0,'0',0,7,0,0);
for(int c=4;c<=5;c++)
	{
		for(int h=0;h<1;h++)
		{
			chapkon(c,h,' ',1,1,0,0);
		}
	}
chapkon(6,0,'1',0,7,0,0);
for(int j=7;j<=8;j++)
	{
		for(int k=0;k<1;k++)
			{
				chapkon(j,k,' ',2,2,0,0);
	}
			}
chapkon(9,0,'2',0,7,0,0);
for(int q=10;q<=11;q++)
	{
		for(int w=0;w<1;w++)
			{
				chapkon(q,w,' ',3,3,0,0);

	}
			}
chapkon(12,0,'3',0,7,0,0);
for(int t=13;t<=14;t++)
	{
		for(int z=0;z<1;z++)
			{
				chapkon(t,z,' ',4,4,0,0);
	}
			}
chapkon(15,0,'4',0,7,0,0);
for(int n=16;n<=17;n++)
	{
		for(int x=0;x<1;x++)
			{
				chapkon(n,x,' ',5,5,0,0);
	}
			}
chapkon(18,0,'5',0,7,0,0);
for(int m=19;m<=20;m++)
	{
		for(int p=0;p<1;p++)
			{
				chapkon(m,p,' ',6,6,0,0);
	}
			}
chapkon(21,0,'6',0,7,0,0);
for(int D=22;D<=23;D++)
	{
		for(int F=0;F<1;F++)
			{
				chapkon(D,F,' ',7,7,0,0);
	}
			}
chapkon(24,0,'7',0,7,0,0);

for(int A=25;A<=80;A++)
	{
		for(int B=0;B<1;B++)
			{
				chapkon(A,B,' ',7,7,0,0);
	}
			}
chapkon(x,y,127,0,7,0,0);
//mouse avalesh biad
chapkon(4,24,'p',0,7,0,0);
chapkon(5,24,'e',0,7,0,0);
chapkon(6,24,'n',0,7,0,0);
chapkon(7,24,':',0,7,0,0);
chapkon(8,24,'[',0,7,0,0);
chapkon(9,24,'o',0,7,0,1);
chapkon(10,24,'f',0,7,0,1);
chapkon(11,24,'f',0,7,0,1);
chapkon(12,24,']',0,7,0,0);


chapkon(15,24,'c',0,7,0,0);
chapkon(16,24,'l',0,7,0,0);
chapkon(17,24,'e',0,7,0,0);
chapkon(18,24,'a',0,7,0,0);
chapkon(19,24,'r',0,7,0,0);
chapkon(20,24,':',0,7,0,0);
chapkon(21,24,'[',0,7,0,0);
chapkon(22,24,'c',0,7,0,0);
chapkon(23,24,']',0,7,0,0);

chapkon(26,24,'e',0,7,0,0);
chapkon(27,24,'r',0,7,0,0);
chapkon(28,24,'a',0,7,0,0);
chapkon(29,24,'s',0,7,0,0);
chapkon(30,24,'e',0,7,0,0);
chapkon(31,24,'r',0,7,0,0);
chapkon(32,24,'[',0,7,0,0);
chapkon(33,24,'e',0,7,0,0);
chapkon(34,24,']',0,7,0,0);

chapkon(37,24,'s',0,7,0,0);
chapkon(38,24,'a',0,7,0,0);
chapkon(39,24,'v',0,7,0,0);
chapkon(40,24,'e',0,7,0,0);
chapkon(41,24,'[',0,7,0,0);
chapkon(42,24,'s',0,7,0,0);
chapkon(43,24,']',0,7,0,0);

chapkon(46,24,'l',0,7,0,0);
chapkon(47,24,'o',0,7,0,0);
chapkon(48,24,'a',0,7,0,0);
chapkon(49,24,'d',0,7,0,0);
chapkon(50,24,'[',0,7,0,0);
chapkon(51,24,'l',0,7,0,0);
chapkon(52,24,']',0,7,0,0);

chapkon(75,1,'c',0,7,0,0);
chapkon(76,1,'o',0,7,0,0);
chapkon(77,1,'l',0,7,0,0);
chapkon(78,1,'o',0,7,0,0);
chapkon(79,1,'r',0,7,0,0);

chapkon(35,0,'n',0,7,0,0);
chapkon(36,0,'a',0,7,0,0);
chapkon(37,0,'m',0,7,0,0);
chapkon(38,0,'e',0,7,0,0);
chapkon(39,0,':',0,7,0,0);

}



void fill(int xi,int yi )

{
	if (o == 32+256*(16*back+7))
	return;

     if (s[yi*80+xi+1]==o && xi<79)
     {
     chapkon(xi+1,yi,' ',7,back,0,0);
      fill(xi+1,yi);
      }
     if(s[yi*80+xi-1]==o &&  xi>0)
     {
     chapkon(xi-1,yi,' ',7,back,0,0);
     fill(xi-1,yi);
     }
     if(s[(yi+1)*80+xi]==o && yi<23)
      {
       chapkon(xi,yi+1,' ',7,back,0,0) ;
       fill(xi,yi+1);
       }
       if(s[(yi-1)*80+xi]==o && yi>2)
       {
       chapkon(xi,yi-1,' ',7,back,0,0);
	 fill(xi,yi-1);
	  }

}
void  paint(char h,int r)
{
 if (r)
  {

   switch(h)
   {


    case 'M':
    if(pen==0)
    chapkon(x,y,' ',7,back,0,0);
    if(pen==1)
     s[y*80+x]=o;
    x+=1;
    if(x>79)
    x=79;
    o=s[y*80+x];
    break;
    case 'K':
    if(pen==0)
    chapkon(x,y,' ',7,back,0,0);
    if(pen==1)
    s[y*80+x]=o;
    x-=1;
    if(x<0)
    x=0;
     o=s[y*80+x];
    break;
    case 'H':
    if(pen==0)
    chapkon(x,y,' ',7,back,0,0);
    if(pen==1)
    s[y*80+x]=o;
    y-=1;
    if(y<2)
    y=2;
     o=s[y*80+x];
    break;
    case 'P':
    if(pen==0)
    chapkon(x,y,' ',7,back,0,0);
   if(pen==1)
   s[y*80+x]=o;
    y+=1;
    if(y>23)
    y=23;
    o=s[y*80+x];
    break;}
    chapkon(x,y,127,0,7,0,0);
    }
    if(r==0)
    {
    switch(h)
    {

     case '0':
     if(pen==0)
    {
    back=0;
    chapkon(x,y,' ',7,back,0,0);
    }
    break;
    case '1':
   if(pen==0)
   {
    back=1;
    chapkon(x,y,' ',7,back,0,0);
   }
    break;
     case '2':
    if(pen==0)
    {
    back=2;
    chapkon(x,y,' ',7,back,0,0);
   }
    break;
     case '3':
    if(pen==0)
   {
    back=3;
    chapkon(x,y,' ',7,back,0,0);
   }
    break;
     case '4':
    if(pen==0)
    {
    back=4;
    chapkon(x,y,' ',7,back,0,0);
   }
    break;
     case '5':
     if(pen==0)
     {
    back=5;
    chapkon(x,y,' ',7,back,0,0);
    }
    break;
     case '6':
     if(pen==0)
     {
    back=6;
    chapkon(x,y,' ',7,back,0,0);
    }
    break;
       case '7':
     if(pen==0)
     {
    back=7;
    chapkon(x,y,' ',7,back,0,0);
    }
    break;
    case 'e':
    back=7;
    chapkon(x,y,' ',7,back,0,0);
    break;
    case 'c':
    o=32+256*(16*7+7);
    for(int i=0;i<80;i++)
	{
		for( int j=2;j<24;j++)
			{
				chapkon(i,j,32,7,7,0,0);
			}
	 }
    break;
    case 's':
	 for(i=0;i<10;i++)
		{
			s[i+40]=256*17*7;
		 }
    save();
    break;
    case 'l':
	 for(i=0;i<10;i++)
		{
			s[i+40]=256*17*7;
		 }
    load();
    break;
    case 'p':

    if(pen==1)
    {
     chapkon(9,24,'o',0,7,0,1);
     chapkon(10,24,'n',0,7,0,1);
     chapkon(11,24,' ',0,7,0,1);
     pen=0;
     }
     else
	 {
	 chapkon(9,24,'o',0,7,0,1);
	 chapkon(10,24,'f',0,7,0,1);
	 chapkon(11,24,'f',0,7,0,1);
	 pen=1;  }
	  break;

     case'f':
     fill(x,y);
     o=32+256*(16*back+7);
     //jaye mouse rangi nmishavad agar nazanim
     break;


    }
     chapkon(x,y,127,0,7,0,0);



     }
   chapkon(79,0,219,back,back,0,0);
   chapkon(78,0,219,back,back,0,0);
   chapkon(77,0,219,back,back,0,0);
   chapkon(76,0,219,back,back,0,0);
   chapkon(75,0,219,back,back,0,0);


}

int main()
{

 first();

 char d;
 int isfunc;
 d = funkey(isfunc);
 while(d!=27)
 {
 paint(d,isfunc);
  d = funkey(isfunc);
 }
}







