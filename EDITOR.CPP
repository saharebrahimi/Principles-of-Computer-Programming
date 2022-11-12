#include<conio.h>
#include<iostream.h>
int maxstate=17,e,cs=0;
int lang=0,ins=0;
int far*s=(int far*)0xB8000000 ;
void chapkon (x,y,c,color,bgcolor,islight,isblink)
{
 int v=color + 8*islight + 16*bgcolor +128*isblink ;
 s[y*80+x] = v*256 +c;
}


void border(){
for(int i=20;i<=60;i++){
chapkon(i,9,205,7,0,0,0);

}
for(int m=20;m<=60;m++){
chapkon(m,13,205,7,0,0,0);
}

for(int v=9;v<=13;v++){
chapkon(20,v,186,7,0,0,0);
}
for(int b=9;b<=13;b++){
chapkon(60,b,186,7,0,0,0);
}
chapkon(20,11,27,7,0,0,0);
chapkon(60,11,26,7,0,0,0);
}

struct stack
{
	int last;
	void init()
	{
	last=-1;
	}
	char A[2000];
	int isempty()
	{
		return(last==-1);
	}
	int isfull()
	{
		return(last==1999);
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
}q,p;

void p0()
{
   q.init();
   p.init();
}
    char  a;
void p1()//c !lang !ins
{

q.push(a);


}

void p2()
{
  ins=!ins;
}
void p3()
{
 lang=!lang;
}
void p4()  //bs !lang
{
      q.pop();
}
void p5() // bs lang
{
      p.pop();
}
void p6()  //home !lang
{
	while(!q.isempty())
	p.push(q.pop());

}
void p7()//home lang
{
	while(!p.isempty())
	q.push(p.pop());
}
void p8() //c,!lang,ins
{
 q.pop();
 q.push(a);


}
void p9() // c,lang,!ins
{
p.push(a);

}
void p10()//c,lang,ins
{
 p.pop();
 p.push(a);


}

void p11() //del,!lang
{
 p.pop();

}
void p12()//del lang
{
 q.pop();

}
void p13() //chap
{
 if (!p.isempty())
 q.push(p.pop());
}
void p14()//rast
{
 if (!q.isempty())
 p.push(q.pop());
}
void p15()//end!lang
{
 while(!p.isempty())
 q.push(p.pop());
}
void p16()//end lang
{
 while(!q.isempty())
 p.push(q.pop());
}

void printstack ()
{        for (int b=0;b<2000;b++)
	 s[b]=256*16*7;
	 border();
	int j=901;
	for(int i=0;i<=p.last;i++)
	{
		if (j<939){
		s[j]=p.A[i]+256*16*7;
		j++;}
	}
	gotoxy((j%80)+1,12);
	for(i=q.last;i>=0;i--)
	{
		if (j<939){
		s[j]=q.A[i]+256*16*7;
		j++;}
	}

}
char funckey(int &T)
{
	char c;
	c=getch();
	if (c==0)
	{
		c=getch();
		T=1;
	}
	else
		T=0;
	return c;
}
int getevent()
{
	int w=0;
	if(a!=27)
	{
	a=funckey(w);
	if (w)
	{     switch(a)
	       {
	       case 'K':
	       return 12;
	       break;
	       case 'M':
	       return 13;
	       break;
	       case 'S': //delete
	       if (lang==0)
	       return 5;
	       else
	       return 4;
	       case ';':  // home f1
	       if (lang==0)
	       return 9;
	       else
	       return 8;
	       break;
	       case'<':  //end  f2
	       if (lang==0)
	       return 11;
	       else
	       return 10;
	       break;
	       case'R': //ins
	       return 15;
	       break;
	       case'=': //backspace f3
	       if (lang==0)
	       return 7;
	       else
	       return 6;
	       break;
	       case'D': //lang f10
	       return 14;
	       break;
	       a=getevent();
	       break;
		}

	}
	if (w==0)
	{

		if((a<=90&&a>=65)||(a<=122&&a>=97)||a==' '||(a<=57&&a>=48))
		{
		if(ins==0 && lang==0)
		 return 2;
		if(ins==0 && lang!=0)
		 return 0;
		 if(ins!=0 && lang==0)
		 return 3;
		 if(ins!=0 && lang!=0)
		 return 1;
		}
		else
			a=getevent();
	}
	}
	return -1;
}

int FSM[17][17]=
{
	 {1,8,9,10,0,0,0,0,0,0,0,0,0,0,3,2,-1}
	,{1,8,9,10,11,12,4,5,6,7,15,16,13,14,3,2,-1}
	,{1,8,9,10,11,12,4,5,6,7,15,16,13,14,3,2,-1}
	,{1,8,9,10,11,12,4,5,6,7,15,16,13,14,3,2,-1}
	,{1,8,9,10,11,12,4,5,6,7,15,16,13,14,3,2,-1}
	,{1,8,9,10,11,12,4,5,6,7,15,16,13,14,3,2,-1}
	,{1,8,9,10,11,12,4,5,6,7,15,16,13,14,3,2,-1}
	,{1,8,9,10,11,12,4,5,6,7,15,16,13,14,3,2,-1}
	,{1,8,9,10,11,12,4,5,6,7,15,16,13,14,3,2,-1}
	,{1,8,9,10,11,12,4,5,6,7,15,16,13,14,3,2,-1}
	,{1,8,9,10,11,12,4,5,6,7,15,16,13,14,3,2,-1}
	,{1,8,9,10,11,12,4,5,6,7,15,16,13,14,3,2,-1}
	,{1,8,9,10,11,12,4,5,6,7,15,16,13,14,3,2,-1}
	,{1,8,9,10,11,12,4,5,6,7,15,16,13,14,3,2,-1}
	,{1,8,9,10,11,12,4,5,6,7,15,16,13,14,3,2,-1}
	,{1,8,9,10,11,12,4,5,6,7,15,16,13,14,3,2,-1}
	,{1,8,9,10,11,12,4,5,6,7,15,16,13,14,3,2,-1}
};


int main()
{

void(*p[17])()={p0,p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13,p14,p15,p16};

	while (cs>=0)
	{
		p[cs]();
		printstack();
		e=getevent();
		cs=FSM[cs][e];

	}

return 0;
}
