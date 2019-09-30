using System;
using System.Collections.Generic;

class M {
  static void Main(String[] _) {
    var N = int.Parse( Console.ReadLine() );
    var W = Console.ReadLine().Split(' ');
	
    var L = new List<int>();
    foreach ( var T in W ) {
      var E = int.Parse(T);
      if ( L.Count + 1 < E ) {
	    Console.Write( "-1" );    
        return;
      }
      L.Insert( E - 1 , E ) ;
    }
    
    Console.Write( string.Join("\n",L.ToArray()) );    
    
  }
}