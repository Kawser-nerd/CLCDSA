using System;
using System.Linq;
using System.Collections.Generic;

public class Program{
  public static void Main(){
    var n = Int32.Parse(Console.ReadLine());
    var l = new Int32[n];
    for(var i=0; i<n; i++) l[i] = Int32.Parse(Console.ReadLine())-1;
    var j = 0;
    var c = 0;
    var tmp = 0;
    while(true){
      if(l[j]==-1){
        c = -1;
        break;
      }
      if(j==1) break;
      tmp = l[j];
      l[j] = -1;
      j = tmp;
      c++;
    }
    Console.WriteLine(c.ToString());
  }
}