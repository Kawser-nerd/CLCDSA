using System;
using System.Linq;
using System.Collections;
using System.Text;
public class c
{
  public static void Main()
  {
    int[] NM=Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
    long[][] AB=new long[NM[0]][];
    int i;
    for(i=0;i<NM[0];i++)
    {
      long[]x=Console.ReadLine().Split(' ').Select(long.Parse).ToArray(); 
      AB[i]=new long[2];
      AB[i][0]=x[0];
      AB[i][1]=x[1];
    }
     Array.Sort(AB, (a, b) => a[0].CompareTo(b[0]));
    long ans=0;
    long countM=0;
    
    for(i=0;i<NM[0];i++)
    {
      if(countM<=NM[1]-AB[i][1]){ans+=AB[i][0]*AB[i][1];countM+=AB[i][1];}
      else if(countM<NM[1]){ans+=AB[i][0]*(NM[1]-countM);countM+=NM[1]-countM;}
      else break;
    }
    Console.WriteLine(ans);
  }
}