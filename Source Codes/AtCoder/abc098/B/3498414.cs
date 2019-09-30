using System;
using System.Linq;

class Program{
  static void Main(){
    
    Console.ReadLine();
    string input = Console.ReadLine();
    int ans = 0;
    
    for(int i = 0; i < input.Length; i++){
      ans = Math.Max(ans, input.Substring(0,i).Intersect(input.Substring(i)).Count());
    }
    
    Console.WriteLine(ans);
    
  }
}