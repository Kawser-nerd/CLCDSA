using System;
using System.Linq;
using System.Collections.Generic;

public class Program{
  public static void Main(){
    var n = byte.Parse(Console.ReadLine());
    var w = new uint[n];
    var max = 1;
    for(var i=0; i<n; i++){
      var m = uint.Parse(Console.ReadLine());
      for(var j=0; j<n; j++){
        if(m<=w[j]||w[j]==0){
          if(max<j+1) max++;
          w[j] = m;
          break;
        }
      }
    }
    Console.WriteLine(max.ToString());
  }
}