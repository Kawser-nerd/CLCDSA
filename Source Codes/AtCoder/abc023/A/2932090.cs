using System;

class Program
{
  static void Main(string[] args)
  {
    int x = int.Parse(Console.ReadLine());
    int y = x / 10;
    int z = x % 10;
    
    Console.WriteLine(y + z);
  }
}