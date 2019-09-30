using System;

class Program
{
  static void Main(string[] args)
  {
    string[] input = Console.ReadLine().Split(' ');
    int M = int.Parse(input[0]);
    int D = int.Parse(input[1]);
    
    if(M % D == 0){
      Console.WriteLine("YES");
    }
    else{
      Console.WriteLine("NO");
    }
  }
}