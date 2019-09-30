using System;

class Program
{
  static void Main(string[] args)
  {
    string[] input = Console.ReadLine().Split(' ');
    int a = int.Parse(input[0]);
    int b = int.Parse(input[1]);
    int c = int.Parse(input[2]);
    
    Console.WriteLine(2 * a * b + 2 * a * c + 2 * b * c);
  }
}