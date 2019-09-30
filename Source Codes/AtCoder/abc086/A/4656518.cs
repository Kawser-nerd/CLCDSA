using System;
using System.Collections.Generic;
using System.Linq;

class M {
  static void Main(string[] __) {
    new M();
  }
  
  M() {
    var tmp = Console.ReadLine().Split(' ');
    int a = int.Parse(tmp[0]);
    int b = int.Parse(tmp[1]);
    int c = a * b;
    if ( c % 2 == 0 ) {
      Console.Write("Even");
    } else {
      Console.Write("Odd");
    }
  }
  
}