using System;
 
class Program
{
  static void Main(string[] args)
  {
    string[] input = Console.ReadLine().Split(' ');
    int n = int.Parse(input[0]);
    int a = int.Parse(input[1]);
    int b = int.Parse(input[2]);
    
    if(a * n <= b) Console.WriteLine("{0}", a * n);
    else Console.WriteLine("{0}", b);
  }
}