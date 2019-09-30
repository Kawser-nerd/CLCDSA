using System;
using System.Linq;
using System.Collections.Generic;
public class c
{
  public static void Main()
  {
    int[] ABC=Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
    Array.Sort(ABC);
    Console.WriteLine(ABC[0]+ABC[1]+10*ABC[2]);
  }
}