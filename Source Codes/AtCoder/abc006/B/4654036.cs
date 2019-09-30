using System;
using System.Linq;
public class c
{
  public static void Main()
  {
    long n=long.Parse(Console.ReadLine());
    int[] ans=new int[10000000];
    int i;
    ans[0]=0;
    ans[1]=0;
    ans[2]=1;
    for(i=3;i<10000000;i++)
    {
      ans[i]=(ans[i-1]+ans[i-2]+ans[i-3])%10007;
    }
    Console.WriteLine(ans[n-1]%10007);
  }
}