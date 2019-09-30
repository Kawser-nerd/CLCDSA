using System;
using System.Linq;

class prog{
  static void Main(){
    
    string N = Console.ReadLine();
    int sum = 0;
    foreach(var s in N){
      sum += int.Parse(s.ToString());
    }
    
    int n = int.Parse(N);
    Console.WriteLine(n % sum == 0 ? "Yes" : "No");
    
  }
}