using System;
using System.Linq;
public class c
{
  public static void Main()
  {
    int[] AB=Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
    if(AB[0]>8||AB[1]>8)Console.WriteLine(":(");
    else Console.WriteLine("Yay!");
    
  }
}