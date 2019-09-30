using System;
using System.Linq;

class prog{
  static void Main(){
    
    int N = int.Parse(Console.ReadLine());
    int K = int.Parse(Console.ReadLine());
    
    int number = 1;
    for(int count = N; count > 0; count--) {
      if(number <= K) number *= 2;
      else number += K;
    }
    
    Console.WriteLine(number);
    
  }
}