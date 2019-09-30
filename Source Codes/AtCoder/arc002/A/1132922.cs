using System;
class AS
{
static void Main()
{
int a=int.Parse(Console.ReadLine());
bool uru=false;
if(a%4==0)
{
if(a%100==0)
{
if(a%400==0)
{uru=true;}
else{uru=false;}}
else{uru=true;}
}
if(uru
==true){Console.WriteLine("YES");}
else{Console.WriteLine("NO");}
}
}