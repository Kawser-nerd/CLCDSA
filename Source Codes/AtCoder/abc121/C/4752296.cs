using System;
using System.Collections.Generic;
using System.Linq;

struct E {
  public long A;
  public long B;
}

class M{static void Main(string[] _) {
  var I0 = Console.ReadLine().Split(' ');
  var N = long.Parse(I0[0]);
  var M = long.Parse(I0[1]);
  
  var L = new List<E>();
  for( int I=0 ; I<N ; ++I ) {
    var I1 = Console.ReadLine().Split(' ');
    var e = new E();
    e.A = long.Parse(I1[0]);
    e.B = long.Parse(I1[1]);
    L.Add(e);
  }
  L.Sort( (a,b) => a.A.CompareTo(b.A) );
  
  long total = 0;
  foreach( var l in L) {
    if ( l.B <= M ) {
      total += l.A * l.B;
      M -= l.B;
    } else {
      total += l.A * M;
      break;
    }
  }
  
  Console.Write(total);  
}}