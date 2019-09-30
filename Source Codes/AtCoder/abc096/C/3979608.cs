using System;
using System.Linq;
using System.Collections.Generic;

public class Program{
  public static void Main(){
    var hw = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
    var a = new byte[hw[0],hw[1]];
    for(var i=0; i<hw[0]; i++){
      var l = Console.ReadLine();
      for(var j=0; j<hw[1]; j++) a[i,j] = (byte) ( l[j]=='#'?1:0);
    }
    var can = true;
    for(var i=0; i<hw[0]; i++){
      for(var j=0; j<hw[1]; j++){
        if(a[i,j]==1){
          var count = 0;
          count += i!=0?(a[i-1,j]==1?1:0):0;
          count += j!=0?(a[i,j-1]==1?1:0):0;
          count += (j!=hw[1]-1)?(a[i,j+1]==1?1:0):0;
          count += (i!=hw[0]-1)?(a[i+1,j]==1?1:0):0;
          if(count==0) can = false;
        }
      }
      if(!can) break;
    }
    Console.WriteLine(can?"Yes":"No");
  }
}