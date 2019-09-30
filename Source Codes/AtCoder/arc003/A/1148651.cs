using System;
class A{
static void Main()
{
int q=int.Parse(Console.ReadLine());
string s=Console.ReadLine();
int a=0;int b=0;int c=0;int d=0,f=0;
for(int i=0;i<q;i++){string y=s.Substring (i,1);
if(y=="A"){a++;}
if(y=="B"){b++;}
if(y=="C"){c++;}
if(y=="D"){d++;}
if(y=="F"){f++;}
}
Console.WriteLine((double)(a*4+b*3+c*2+d*1+f*0)/q);
}
}