using System;

class M {
  public static void Main(String[] a) {
    double total = 0;
    
    var N = int.Parse(Console.ReadLine()); 
    for ( int I=0 ; I<N ; ++I ) {
      var A = Console.ReadLine().Split(' ');
      var val = double.Parse(A[0]);
      var currency = A[1];
      
      if ( currency.Equals("JPY") ) {
        total += val;
        continue;
      }
      
      if ( currency.Equals("BTC") ) {
        total += val * 380000.0;
      }
    }
    Console.Write(""+total);
      
  }
    
}