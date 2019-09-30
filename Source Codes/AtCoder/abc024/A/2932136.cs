using System;
 
class Program
{
  static void Main(string[] args)
  {
    string[] input1 = Console.ReadLine().Split(' ');
    int a = int.Parse(input1[0]);
    int b = int.Parse(input1[1]);
    int c = int.Parse(input1[2]);
    int k = int.Parse(input1[3]);
    
    string[] input2 = Console.ReadLine().Split(' ');
    int s = int.Parse(input2[0]);
    int t = int.Parse(input2[1]);
    
    int sum = a * s + b * t;
    
    if(k <= s + t)
    {
      sum -= c * (s + t);
    }
    
    Console.WriteLine(sum);
  }
}