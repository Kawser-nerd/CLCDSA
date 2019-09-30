using System;
using System.Linq;
public class c
{
  public static void Main()
  {
    long[]ABK=Console.ReadLine().Split(' ').Select(long.Parse).ToArray();
    for(long i=ABK[0];i<=Math.Min(ABK[0]+ABK[2]-1,ABK[1]);i++)Console.WriteLine(i);
    for(long i=Math.Max(ABK[1]-ABK[2]+1,ABK[0]+ABK[2]);i<=ABK[1];i++)Console.WriteLine(i);
  }
}