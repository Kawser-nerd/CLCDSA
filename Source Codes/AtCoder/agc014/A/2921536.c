# include <stdio.h>
int main ()
{
	int a,b,c,p=1,d=1;
	scanf ("%d%d%d",&a,&b,&c);
	int i=0;
     if (a%2!=0||b%2!=0||c%2!=0)
        printf ("%d\n",0);
    else
    {
        for (i=1;i<=100;++i)
	    {
	     int d=0,e=0,f=0;
	  	 d=a/2;
	  	 e=b/2;
	  	 f=c/2;
	  	 a=e+f;
	  	 b=d+f;
	  	 c=d+e;
	  	 if (a%2!=0||b%2!=0||c%2!=0)
	  	    {
	  	    	p=0;
	  	    	break;
		    }
	    }
	  if (p==0)
	  printf ("%d\n",i);
	else
	  printf ("%d\n",-1);	
	}
    	  
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf ("%d%d%d",&a,&b,&c);
  ^