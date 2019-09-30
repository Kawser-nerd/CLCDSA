using System;
using System.Linq;
using System.Collections.Generic;

public class Program{
  public static void Main(){
    var n = uint.Parse(Console.ReadLine());
    var gcd = ulong.Parse(Console.ReadLine());
    ulong gcm = gcd;
    for(var i=1; i<n; i++){
      var x = ulong.Parse(Console.ReadLine());
      var a = Math.Max(gcm, x);
      var b = Math.Min(gcm, x);
      while(b!=0){
        var tmp = b;
        b = a%b;
        a = tmp;
      }
      gcd = a;
      gcm = (x/gcd)*gcm;
    }
    Console.WriteLine(gcm.ToString());
  }
}