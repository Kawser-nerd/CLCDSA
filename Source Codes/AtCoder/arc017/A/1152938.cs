using System;
class A{
static void Main()
{bool flag=false;
int a=int.Parse(Console.ReadLine());
for(int i=2;i<(int)a/2;i++){if(a%i==0){flag=true;}}
Console.WriteLine(flag?"NO":"YES");
}
}