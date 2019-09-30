using System;

class Program
{
 static void Main(string[] args)
 {
   string[] input = Console.ReadLine().Split(' ');
   
   long a = long.Parse(input[0]);
   long b = long.Parse(input[1]);
   long x = long.Parse(input[2]);
   long num1 = 0;
   long num2 = 0;
   long calc = 0;
   
   num1 = a / x;
   num2 = b / x;
   
   if( (a%x) == 0 )
   {
     calc = (num2 - num1) + 1;
   }
   else
   {
     calc = (num2 - num1);
   }
   
   Console.WriteLine(calc);
 }
}