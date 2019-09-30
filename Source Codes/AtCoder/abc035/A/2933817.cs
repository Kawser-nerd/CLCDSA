using System;

class Program
{
  static void Main(string[] args)
  {
    string[] input = Console.ReadLine().Split(' ');
    int w = int.Parse(input[0]);
    int h = int.Parse(input[1]);
    
    if(w * 3 == h * 4)
    {
      Console.WriteLine("4:3");
    }
    else
    {
      Console.WriteLine("16:9");
    }
  }
}