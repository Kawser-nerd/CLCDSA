using System;
using System.Linq;
public class c
{
  public static void Main()
  {
    int[]AB=Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
    int sum =AB[0]+AB[1];
    int sub = AB[0]-AB[1];
    int multi=AB[0]*AB[1];
    if(sum>=sub&&sum>=multi)Console.WriteLine(sum);
    else if(sub>=sum&&sub>=multi)Console.WriteLine(sub);
    else Console.WriteLine(multi);
  }
}