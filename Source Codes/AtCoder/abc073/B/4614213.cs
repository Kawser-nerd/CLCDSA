using System;
using System.Linq;
public class c
{
  public static void Main()
  {
    int N = int.Parse(Console.ReadLine());
    int sum=0;
    int i;
    for(i=0;i<N;i++)
    {
      int[] x=Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
      sum+=(x[1]-x[0]+1);
    }
    Console.WriteLine(sum);
  }
}