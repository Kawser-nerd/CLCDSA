using System;
using System.Linq;
public class c
{
  public static void Main()
  {
    int N = int.Parse(Console.ReadLine());
    int[] x=new int[N];
    int i;
    for(i=0;i<N;i++)
    {
      x[i]=int.Parse(Console.ReadLine());
    }
    Array.Sort(x);
    int s=1;
    int ans=0;
    for(i=1;i<N;i++)
    {
      if(x[i]==x[i-1])s++;
      else 
      {
        if(s%2==1)ans++;
         s=1;
      }
      
    }if(s%2==1)ans++;
    
    Console.WriteLine(ans);
  }
}