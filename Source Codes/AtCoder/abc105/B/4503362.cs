using System;

class Program
{
  static void Main()
  {
    var N = int.Parse(Console.ReadLine());
    var answer = "No";
    for (int i=0; i<=N/4; i++)
    {
      for (int j=0; j<=N/7; j++)
      {
        if ( 4*i + 7*j == N ) answer = "Yes";
      }
    }
    Console.WriteLine(answer);
  }
}