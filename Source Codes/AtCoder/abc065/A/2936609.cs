using System;

class Program
{
  static void Main(string[] args)
  {
    string[] input = Console.ReadLine().Split(' ');
    int x = int.Parse(input[0]);
    int a = int.Parse(input[1]);
    int b = int.Parse(input[2]);
    
    if(b <= a) Console.WriteLine("delicious");
    else if(b <= a + x) Console.WriteLine("safe");
    else Console.WriteLine("dangerous");
  }
}