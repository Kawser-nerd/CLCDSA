using System;
using System.Linq;
using System.Collections.Generic;

public class Program{
  public static void Main(){
    var n = Array.ConvertAll(Console.ReadLine().Split(' '), long.Parse);
    Console.WriteLine(((n[1]/n[2])-(n[0]%n[2]==0?n[0]/n[2]-1:n[0]/n[2])).ToString());
  }
}