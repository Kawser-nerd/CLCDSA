using System;
class A{
  static void Main(){
    var s = Console.ReadLine().Split();
    Console.WriteLine(int.Parse($"{s[1]}{s[2]}") % 4 == 0 ? "YES" : "NO");
  }
}