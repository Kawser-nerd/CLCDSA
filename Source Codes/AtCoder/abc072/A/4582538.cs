using System;
using System.Linq;
public class s
{
  public static void Main()
  {
    int[] Xt=Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
    if(Xt[0]<=Xt[1])Console.WriteLine(0);
    else Console.WriteLine(Xt[0]-Xt[1]);
  }
}