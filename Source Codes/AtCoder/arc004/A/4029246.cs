using System;
using System.Linq;
using System.Collections.Generic;

public class Program{
  public static void Main(){
    var n = UInt16.Parse(Console.ReadLine());
    var a = new UInt16[n,2];
    for(var i=0; i<n; i++){
      var tmp = Array.ConvertAll(Console.ReadLine().Split(' '), UInt16.Parse);
      a[i,0]=tmp[0]; a[i,1]=tmp[1];
    }
    var m = 0;
    for(var i=0; i<n-1; i++){
      for(var j=i+1; j<n; j++){
        var x =a[j,0]-a[i,0];
        var y =a[j,1]-a[i,1];
        var tmp = x*x+y*y;
        if(tmp>m) m = tmp;
      }
    }
    Console.WriteLine(Math.Sqrt(m).ToString());
  }
}