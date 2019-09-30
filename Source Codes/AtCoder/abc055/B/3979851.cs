using System;
using System.Linq;
using System.Collections.Generic;

public class Program{
  public static void Main(){
    var n = ulong.Parse(Console.ReadLine());
    ulong p=1;
    for(ulong i=1; i<=n; i++) p = (p*i) % 1000000007;
    Console.WriteLine("{0}", p);
  }
}