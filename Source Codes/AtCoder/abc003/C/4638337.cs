using System;
using System.Linq;
public class c
{
  public static void Main()
  {
    int[] NK=Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
    double[] r=Console.ReadLine().Split(' ').Select(double.Parse).ToArray();
     Array.Sort(r);
    int i;
    double ave=0;
    for(i=NK[0]-NK[1];i<NK[0];i++)
    {
      ave+=(r[i]);
      ave/=2;
    }
    Console.WriteLine(ave);
  }
}