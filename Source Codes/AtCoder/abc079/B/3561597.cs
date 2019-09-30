using System;
using System.Linq;

class prog{
  
  static void Main(){
    int N = int.Parse(Console.ReadLine());
    long[] lucas = new long[N + 1];
    
    lucas[0] = 2;
    lucas[1] = 1;
    for(int i = 2; i <= N; i++){
      lucas[i] = lucas[i - 1] + lucas[i - 2];
    }
    
    Console.WriteLine(lucas[N]);
  }
}