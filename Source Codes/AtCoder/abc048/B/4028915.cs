using System;
using System.Linq;
using System.Collections.Generic;

public class Program{
  public static void Main(){
    var n = Array.ConvertAll(Console.ReadLine().Split(' '), long.Parse);
    long a = n[0]%n[2]==0?n[0]/n[2]-1:n[0]/n[2];
    long b = n[1]/n[2];
    Console.WriteLine((b-a).ToString());
  }
}