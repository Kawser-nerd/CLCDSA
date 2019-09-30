using System;
using System.Linq;
public class c
{ public static void Main()
  {
    int[] NAB = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
     if(NAB[0]*NAB[1]>NAB[2])Console.WriteLine(NAB[2]);
     else Console.WriteLine(NAB[0]*NAB[1]);
  }
}