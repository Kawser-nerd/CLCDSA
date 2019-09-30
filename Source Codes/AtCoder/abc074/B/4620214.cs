using System;
using System.Linq;
public class c
{
  public static void Main()
  {
    int N = int.Parse(Console.ReadLine());
    int K = int.Parse(Console.ReadLine());
    int[] ball = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
    int sum=0;
    for(int i=0;i<ball.Length;i++)
    {
      if(K<=2*ball[i])sum+=((K-ball[i])*2);
      else sum+=(ball[i]*2);
    }
    Console.WriteLine(sum);
  }
}