using System;
using System.Linq;
using System.Collections.Generic;

public class Program{
  public static void Main(){
    var hw = Array.ConvertAll(Console.ReadLine().Split(' '), uint.Parse);
    var s = Array.ConvertAll(Console.ReadLine().Split(' '), uint.Parse);
    var g = Array.ConvertAll(Console.ReadLine().Split(' '), uint.Parse);
    var m = new short[hw[0],hw[1]];
    for(uint i=0; i<hw[0]; i++){
      var c = Console.ReadLine().ToCharArray();
      for(uint j=0; j<hw[1]; j++) m[i,j] = (short) (c[j]=='#'?-1:0);
    }
    var q = new Queue<uint>();
    q.Enqueue(s[0]-1+hw[1]*(s[1]-1));
    short w = 0;
    while(q.Count()!=0){
      var n = q.Dequeue();
      var x = n%hw[1]; var y = n/hw[1];
      w = m[y,x];
      if(x==g[1]-1&&y==g[0]-1) break;
      if(x>0){if(m[y,x-1]==0){q.Enqueue(n-1); m[y,x-1]=(short) (w+1);}}
      if(y>0){if(m[y-1,x]==0){q.Enqueue(n-hw[1]); m[y-1,x]=(short) (w+1);}}
      if(y<hw[0]-1){ if(m[y+1,x]==0){ q.Enqueue(n+hw[1]); m[y+1,x]=(short) (w+1);}}
      if(x<hw[1]-1){ if(m[y,x+1]==0){ q.Enqueue(n+1); m[y,x+1]=(short) (w+1);}}
    }
    Console.WriteLine(w.ToString());
  }
}