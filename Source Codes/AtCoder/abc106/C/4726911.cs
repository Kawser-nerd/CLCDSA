using System;
using System.Linq;
public class c
{
  public static void Main()
  {
    char[] S=Console.ReadLine().ToCharArray();
    ulong K=ulong.Parse(Console.ReadLine());
    int i;
    int[] ans=new int[S.Length];
    int x=0;
    for(i=0;i<S.Length;i++)
    {
      if(int.Parse(S[i].ToString())==1){ans[i]=1;}
      else {ans[i]=int.Parse(S[i].ToString());x=i;break;}
    }
    if(K<=(ulong)x)Console.WriteLine(1);
    else Console.WriteLine(ans[x]);
  }
}