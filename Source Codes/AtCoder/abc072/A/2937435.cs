using System;

class Program
{
  static void Main(string[] args)
  {
    string[] input = Console.ReadLine().Split(' ');
    int x = int.Parse(input[0]);
    int t = int.Parse(input[1]);
    
    int ans = x - t;
    if(ans < 0) ans = 0;
    
    Console.WriteLine("{0}", ans);
  }
}