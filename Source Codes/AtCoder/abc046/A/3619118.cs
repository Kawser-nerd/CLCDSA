using System;
using System.Linq;
 
class P{
  static void Main(){
    
    string[] n = Console.ReadLine().Split().ToArray();
    Console.WriteLine(n.Distinct().Count());
    
  }
}