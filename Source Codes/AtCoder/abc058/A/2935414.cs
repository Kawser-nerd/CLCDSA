using System;
 
class Program
{
  static void Main(string[] args)
  {
    string[] input = Console.ReadLine().Split(' ');
    int a = int.Parse(input[0]);
    int b = int.Parse(input[1]);
    int c = int.Parse(input[2]);
    
    if(b - a == c - b) Console.WriteLine("YES");
    else Console.WriteLine("NO");
  }
}