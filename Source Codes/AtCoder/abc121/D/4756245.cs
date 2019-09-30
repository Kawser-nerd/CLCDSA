using System;
using System.Collections.Generic;
using System.Linq;

class M{static void Main(string[] _) {
  
  var I0 = Console.ReadLine().Split(' ');
  long A = long.Parse(I0[0]) - 1;
  long B = long.Parse(I0[1]);

  long a = ( A % 2 != 0 )? ((A+1)/2)%2 : (A+(A/2)%2);
  long b = ( B % 2 != 0 )? ((B+1)/2)%2 : (B+(B/2)%2);
  
  long r = 0;
  long P = 1;
  while( P <= a || P <= b ) {
    r+= ( ((a/P)%2) != ((b/P)%2) )? P : 0;
    P *= 2;
  }

  Console.WriteLine( r );
  
}}