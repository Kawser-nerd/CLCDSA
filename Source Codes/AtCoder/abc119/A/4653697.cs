using System;

class M {
  public static void Main(String[] a) {
    var A = Console.ReadLine().Split(' ');
    var C = DateTime.Parse(A[0]);   
    if ( C <= new DateTime(2019,4,30) ) {
      Console.Write("Heisei");
    } else {
      Console.Write("TBD");
    }
      
  }
    
}