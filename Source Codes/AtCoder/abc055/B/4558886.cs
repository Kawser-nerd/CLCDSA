using System;

class Program
{
 static void Main(String[] args)
 {
   var num = int.Parse(Console.ReadLine());
   var cnt = 0;
   long power = 1;
   
   for( cnt = 1; cnt <= num; cnt++ )
   {
     power = (power * cnt) % 1000000007;
   }
   
   Console.WriteLine(power);
 }
}