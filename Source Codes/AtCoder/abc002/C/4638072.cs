using System;
using System.Linq;
public class c
{
  public static void Main()
  {
    double[] aabbcc=Console.ReadLine().Split(' ').Select(double.Parse).ToArray();
    aabbcc[2]-=aabbcc[0];
    aabbcc[4]-=aabbcc[0];
    aabbcc[3]-=aabbcc[1];
    aabbcc[5]-=aabbcc[1];
    aabbcc[0]=aabbcc[1]=0;
    double ans=(aabbcc[2]*aabbcc[5]-aabbcc[3]*aabbcc[4])/2;
    ans=ans<0?-ans:ans;
    Console.WriteLine(ans);
  }
}