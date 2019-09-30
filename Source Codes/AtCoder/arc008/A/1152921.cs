using System;
class A{
static void Main()
 
{
int a=int.Parse(Console.ReadLine());if(a%10>=7){
Console.WriteLine((a%10)*15*0+((int)a/10+1)*100);}else{Console.WriteLine((a%10)*15+((int )a/10)*100);}
}
}