using System;
using System.Linq;
using System.Collections.Generic;
class P{
  class V{
    public long x,y,i;
    public V(long a,long b,int c){x=a;y=b;i=c;}
  }
  static void Main(){
    var n=Console.ReadLine().Split().Select(int.Parse);
    var ls=new List<V>();var lp=new List<V>();
    for(int i=0;i<n.First();i++){
      var r=Console.ReadLine().Split().Select(long.Parse);
      ls.Add(new V(r.First(),r.Last(),0));
    }
    for(int i=0;i<n.Last();i++){
      var r=Console.ReadLine().Split().Select(long.Parse);
      lp.Add(new V(r.First(),r.Last(),i+1));
    }
    foreach(V s in ls)Console.WriteLine(lp.OrderBy(x=>Math.Abs(s.x-x.x)+Math.Abs(s.y-x.y)).First().i);
  }
}