using System;
using System.Linq;

class M{static void Main(string[] _) {
  var I0 = Console.ReadLine().Split(' ');
  var N = int.Parse(I0[0]);
  var M = int.Parse(I0[1]);
  var C = int.Parse(I0[2]);
  
  var I1 = Console.ReadLine().Split(' ');
  var B  = I1.Select(a=>int.Parse(a)).ToList();
  
  int result = 0;
  for(int I=0;I<N;++I) {
    var I2 = Console.ReadLine().Split(' ');
    var A = I2.Select(a=>int.Parse(a)).ToList();    
    int val = C;
    for( int J=0;J<A.Count();++J) {
      int a = A[J];
      int b = B[J];
      val += a * b;
    }
    if ( val > 0 ) {
      result ++;
    }
  }
  
  Console.Write(result);  
}}