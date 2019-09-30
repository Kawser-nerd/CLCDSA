using System;
 
class Program
{
  static void Main(string[] args)
  {
    string[] input = Console.ReadLine().Split(' ');
    int N = int.Parse(input[0]);
    int S = int.Parse(input[1]);
    int T = int.Parse(input[2]);
    int W = int.Parse(Console.ReadLine());
    int count = 0;
    
    if(S <= W && W <= T) count++;
    
    for(int i = 1; i < N; i++)
    {
      int Ai = int.Parse(Console.ReadLine());
      W += Ai;
      
      if(S <= W && W <= T) count++;
    }
    
    Console.WriteLine(count);
  }
}