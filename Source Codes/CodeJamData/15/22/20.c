#include<stdio.h>
#include<stdlib.h>

#define ll long long

ll **arr;
int main()
{
	ll kases,kase,i,j,check,def,ans,flag,left,max,R,C,N,p;
	int two,three,four;
	scanf("%lld",&kases);
	for(kase=1;kase<=kases;kase++)
	{
		two=0;
		three=0;
		four=0;
		p=0;
		scanf("%lld%lld%lld",&R,&C,&N);
		/*arr=(ll**)malloc(R*sizeof(ll*));
		for(i=0;i<R;i++)
			arr[i]=(ll*)malloc(C*sizeof(ll));
		for(i=0;i<R;i++)
			for(j=0;j<R;j++)
				arr[i][j]=0;*/

		if(R==1&&C==1) 
		{
			if(N==0) p=0;
			else p=0;
		}
		else if(R*C==2)
		{
			if(N==1) p=0;
			else p=1;
		}
		else if(R*C==3 ||R*C==5 ||R*C==7 ||R*C==11 ||R*C==13)
		{
			if(N<= ((R*C)/2+1)) p=0;
			else p=(N-((R*C)/2+1))+2;
		}
		else if(R*C==4)
		{
			if(N<=((R*C)/2)) p=0;
			else
			{
				if(R==2 && C==2)
				{
					if(N==3) p=2;
					else p=4;
				}
				else
				{
					if(N==3) p=1;
					else p=3;
				}
			}
		}
		else if(R*C==6)
		{
			if(N<=((R*C)/2)) p=0;
			else
			{
				if((R==2 && C==3) || (R==3 && C==2) )
				{
					if(N>3&&N<=5) p=2*(N-((R*C)/2));
					else p=7;
				}
				else
				{
					if((N-((R*C)/2))==1) p=1;
					else p=2*(N-((R*C)/2)-1)+1;
				}
			}
		}
		else if(R*C==10)
		{
			if(N<=((R*C)/2)) p=0;
			else
			{
				if((R==2 && C==5) || (R==5 && C==2) )
				{
					if(N>5&&N<=7) p=2*(N-((R*C)/2));
					else if(N>7 && N<=10) p=4+3*(N-7);
					else p=13;
				}
				else
				{
					if((N-((R*C)/2))==1) p=1;
					else if(N<=10) p=2*(N-((R*C)/2)-1)+1;
					else p=9;
				}
			}
		}
		else if(R*C==9)
		{
			if(R==3&&C==3)
			{
				if(N<=5) 
					p=0;
				else if(N==8) p=8;
				else if(N>5 && N<=9 && N!=8)
					p=3*(N-5);
				else
					p=12;
			}
			else if((R==1 && C==9) || (R==9 && C==1))
			{
				if(N<=5) 
					p=0;
				else if(N>5 && N<=9)
					p=2*(N-5);
				else
					p=8;
			}
		}
		else if(R*C==8)
		{
			if((R==2&&C==4) ||(R==4&&C==2) )
			{
				if(N<=4) 
					p=0;
				else if(N>4 && N<=6)
					p=2*(N-4);
				else if(N>6 && N<=8)
					p=4+3*(N-6);
				else
					p=10;
			}
			else if((R==1 && C==8) || (R==8 && C==1))
			{
				if(N<=4) 
					p=0;
				else if(N==5) p=1;
				else if(N>5 && N<=8)
					p=2*(N-5)+1;
				else
					p=7;
			}
		}
		else if(R*C==14)
		{
			if((R==2&&C==7) ||(R==7&&C==2) )
			{
				if(N<=7) 
					p=0;
				else if(N>7 && N<=9)
					p=2*(N-7);
				else if(N>9 && N<=14)
					p=4+3*(N-9);
				else
					p=19;
			}
			else if((R==1 && C==14) || (R==14 && C==1))
			{
				if(N<=7) 
					p=0;
				else if(N==8) p=1;
				else if(N>8 && N<=14)
					p=2*(N-8)+1;
				else
					p=13;
			}	
		}
		else if(R*C==15)
		{
			if((R==3&&C==5) ||(R==5&&C==3) )
			{
				if(N<=8) 
					p=0;
				else if(N>8 && N<=10)
					p=3*(N-8);
				else if(N==11) p =8;
				else if(N==12) p =11;
				else if(N==13) p =14;
				else if(N==14) p =18;
				else if(N==15) p =22;
				else
					p=22;
			}
			else if((R==1 && C==15) || (R==15 && C==1))
			{
				if(N<=8) 
					p=0;
				else if(N>8 && N<=15)
					p=2*(N-8);
				else
					p=14;
			}
		}
		else if(R*C==12)
		{
			if((R==3&&C==4) || (R==4&&C==3))
			{
				if(N<=6) 
					p=0;
				else if(N>6 && N<=8)
					p=2*(N-6);
				else if(N>8 && N<=11)
					p=4+3*(N-8);
				else if(N>11 && N<=12)
					p=17;
				else
					p=17;
			}
			else if((R==2 && C==6) || (R==6 && C==2))
			{
				if(N<=6) 
					p=0;
				else if(N>6 && N<=8)
					p=2*(N-6);
				else if(N>8 && N<=12)
					p=4+3*(N-8);
				else
					p=16;
			}
			else if((R==1 && C==12) || (R==12 && C==1))
			{
				if(N<=6) 
					p=0;
				else if(N==7)
					p=1;
				else if(N>7 && N<=12)
					p=1+2*(N-7);
				else
					p=11;
			}	
		}
		else if(R*C==16)
		{
			if(R==4&&C==4)
			{
				if(N<=8) 
					p=0;
				else if(N>8 && N<=10)
					p=2*(N-8);
				else if(N>10 && N<=14)
					p=4+3*(N-10);
				else if(N>14 && N<=16)
					p=16+4*(N-14);
				else
					p=24;
			}
			else if((R==2 && C==8) || (R==8 && C==2))
			{
				if(N<=8) 
					p=0;
				else if(N>8 && N<=10)
					p=2*(N-8);
				else if(N>10 && N<=16)
					p=4+3*(N-10);
				else
					p=22;
			}
			else if((R==1 && C==16) || (R==16 && C==1))
			{
				if(N<=8) 
					p=0;
				else if(N==9)
					p=1;
				else if(N>9 && N<=16)
					p=1+2*(N-9);
				else
					p=15;
			}
		}
		printf("Case #%lld: %lld\n",kase,p);	
	}
	return 0;
}
