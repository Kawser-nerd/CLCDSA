using System;
using System.Linq;
public class c
{
  public static void Main()
  {
    int[]AB=Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
    Console.WriteLine((AB[0]-1)*(AB[1]-1));
  }
}