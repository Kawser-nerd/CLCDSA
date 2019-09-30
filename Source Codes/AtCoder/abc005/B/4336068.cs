using System;
public class c
{
  public static void Main()
  {
    int n = int.Parse(Console.ReadLine());
    int Min = 9999;
     int x = 0;
    for(int i=0;i<n;i++)
    {
      x=int.Parse(Console.ReadLine());
      if(x<Min)Min=x;
    }
    
    Console.WriteLine(Min);
  }
}