using System;
using System.Linq;
public class c
{
  public static void Main()
  {
    int[] NK= Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
   if(NK[0]%NK[1]==0) Console.WriteLine(0);
    else Console.WriteLine(1);
  }
}