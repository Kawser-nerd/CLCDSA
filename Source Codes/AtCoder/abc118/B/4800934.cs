using System;
using System.Linq;
class c
{
  static void Main()
  {
    int[] NM=Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
    int[] fav=new int[NM[1]];
    int count=0;
    for(int i = 0; i<NM[0];i++)
    {
      int[]ans=Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
      for(int j=1;j<ans.Length;j++)fav[ans[j]-1]++;
    }
    for(int i=0;i<NM[1];i++)if(fav[i]==NM[0])count++;
    Console.WriteLine(count);
  } 
}