using System;
using System.Linq;
using System.Collections.Generic;

public class Program{
  public static void Main(){
    var abc = Array.ConvertAll(Console.ReadLine().Split(' '), UInt32.Parse);
    var flug = false;
    for(var i=1; i<abc[1]+1; i++){
      if((i*abc[0])%abc[1]==abc[2]){
        flug = true;
        break;
      }
    }
    Console.WriteLine(flug?"YES":"NO");
  }
}