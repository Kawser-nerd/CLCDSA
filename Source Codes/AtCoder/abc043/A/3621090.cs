using System;
using System.Linq;
 
class Program {
  static void Main() {
    int n = int.Parse(Console.ReadLine());
    int ans = 0;
    for(int i = 1; i <= n; i++){
      ans += i;
    }
    Console.WriteLine(ans);
  }
}