using System;
using System.Linq;
public class c
{
  public static void Main()
  {
    int[]ABCK=Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
    int[] ST=Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
    if(ST[0]+ST[1]>=ABCK[3])Console.WriteLine((ABCK[0]-ABCK[2])*ST[0]+(ABCK[1]-ABCK[2])*ST[1]);
    else Console.WriteLine((ABCK[0])*ST[0]+(ABCK[1])*ST[1]);
  }
}