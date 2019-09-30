using System;
using System.Linq;

class M {
  static void Main(string[] __) {
    var N = int.Parse(Console.ReadLine());
    var L = Console.ReadLine().Split(' ').Select( (v) => int.Parse(v) );
    
    int result = 0;
	while(true) {   
      if ( L.Any( (v) => v%2==1 ) ) {
        Console.Write(result);
        return;
      }
      L = L.Select( (v)=>v/2 );
      ++result;
    }
    
    Console.Write( ""+result ) ;
    
    
  }
}