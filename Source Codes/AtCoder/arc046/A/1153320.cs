using System;
class A{
static void Main()
{
int a=int.Parse(Console.ReadLine());
if(a%9==0){for(int i=0;i<a/9;i++){Console.Write(9);}Console.WriteLine();}
else{for(int i=0;i<a/9+1;i++){Console.Write(a%9);}Console.WriteLine();}
}

}