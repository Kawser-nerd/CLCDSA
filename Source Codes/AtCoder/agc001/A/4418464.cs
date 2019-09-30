using System;
public class c
{
  public static void Main()
  {
    int N = int.Parse(Console.ReadLine());
    string[] s = Console.ReadLine().Split(' ');
    int[]  L = new int[N*2];
    for(int i=0;i<2*N;i++)
    {
      L[i]=int.Parse(s[i]);
    }
    Array.Sort(L);
    int x=0;
   for(int i=0;i<N;i++)
  {
    x+=L[2*i];
  }Console.WriteLine(x);
}}