using System;
using System.Linq;
using System.Collections.Generic;

public class Program{
  public static void Main(){
    var hw = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
    var a = new sbyte[hw[0],hw[1]];
    for(var i=0; i<hw[0]; i++){
      var l = Console.ReadLine();
      for(var j=0; j<hw[1]; j++) a[i,j] = (sbyte) ( l[j]=='#'?-1:0);
    }
    for(var i=0; i<hw[0]; i++){
      for(var j=0; j<hw[1]; j++){
        if(a[i,j]!=-1){
          a[i,j] += (sbyte) ((i!=0&&j!=0)?(a[i-1,j-1]==-1?1:0):0);
          a[i,j] += (sbyte) (i!=0?(a[i-1,j]==-1?1:0):0);
          a[i,j] += (sbyte) ((i!=0&&j!=hw[1]-1)?(a[i-1,j+1]==-1?1:0):0);

          a[i,j] += (sbyte) (j!=0?(a[i,j-1]==-1?1:0):0);
          a[i,j] += (sbyte) ((j!=hw[1]-1)?(a[i,j+1]==-1?1:0):0);

          a[i,j] += (sbyte) ((i!=hw[0]-1&&j!=0)?(a[i+1,j-1]==-1?1:0):0);
          a[i,j] += (sbyte) ((i!=hw[0]-1)?(a[i+1,j]==-1?1:0):0);
          a[i,j] += (sbyte) ((i!=hw[0]-1&&j!=hw[1]-1)?(a[i+1,j+1]==-1?1:0):0);
        }
        Console.Write("{0}", (a[i,j]==-1)?"#":a[i,j].ToString());
      }
      Console.Write("\n");
    }
  }
}