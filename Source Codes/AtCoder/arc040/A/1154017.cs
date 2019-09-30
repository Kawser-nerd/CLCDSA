using System;
class A{
static void Main()
{int r=0;int b=0;
int a=int.Parse(Console.ReadLine());////////////////////////////////////////////////////////////////////////
for(int i=0;i<a;i++){
string s=Console.ReadLine();
for(int k=0;k<a;k++){
string f=s.Substring(k,1);
if(f=="R"){r++;}
if(f=="B"){b++;}
}
}
if(r>b){Console.WriteLine("TAKAHASHI");}
else if(r<b){Console.WriteLine("AOKI");}
else{Console.WriteLine("DRAW");}
}
}