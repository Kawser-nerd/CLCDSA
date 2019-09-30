using System;
using System.Linq;
using System.Collections.Generic;

public class Program{
  public static void Main(){
    var nk = Array.ConvertAll(Console.ReadLine().Split(' '), UInt32.Parse);
    var a = Array.ConvertAll(Console.ReadLine().Split(' '), UInt32.Parse);
    var gcd = a[0];
    var max = a[0];
    for(var i=1; i<nk[0]; i++){
      var m = Math.Max(gcd, a[i]);
      var n = Math.Min(gcd, a[i]);
      max = Math.Max(max, a[i]);
      for(;;){
        if(n==0) break;
        var tmp = n;
        n = m%n;
        m = tmp;
      }
      gcd = m;
    }
    Console.WriteLine((nk[1]%gcd==0&&nk[1]<=max)?"POSSIBLE":"IMPOSSIBLE");
  }
}