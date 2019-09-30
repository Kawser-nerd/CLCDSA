using System;
using System.Linq;
public class c
{
  public static void Main()
  {
    int[] NMC=Console.ReadLine().Split(' ').Select(int.Parse).ToArray(); 
    int[] B=Console.ReadLine().Split(' ').Select(int.Parse).ToArray(); 
    int ans=0;
    int sum=0;
    for(int i=0;i<NMC[0];i++)
    {
      int[] A=Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
      for(int j=0;j<NMC[1];j++)
      {
        sum+=A[j]*B[j];
      }
      sum+=NMC[2];
      if(sum>0)ans++;
      sum=0;
    }
    Console.WriteLine(ans);
  }
}