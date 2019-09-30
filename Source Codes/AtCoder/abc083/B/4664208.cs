using System;
class M {
  static void Main(string[] _) {
    var P = Console.ReadLine().Split(' ');
    var N = int.Parse(P[0]);
    var A = int.Parse(P[1]);
    var B = int.Parse(P[2]);
    
    long total = 0;
    for ( int I=0 ; I<=N ; ++ I ) {
      var A0 = I % 10;
      var A1 = ( I / 10 ) % 10;
      var A2 = ( I / 100 ) % 10;
      var A3 = ( I / 1000 ) % 10;
      var A4 = ( I / 10000 ) % 10;
      var A5 = ( I / 100000 ) % 10;
      var A6 = A0 + A1 + A2 + A3 + A4 + A5 ;
      if ( A <= A6 && A6 <= B ) {
        total += I;
      }
    }
    
    
    Console.Write(total);
    
  }
}