using System;
class Program
{
 static void Main(string[] args)
 {
   Console.WriteLine("1" + new string('0', int.Parse(Console.ReadLine()) - 1) + "7");
 }
}