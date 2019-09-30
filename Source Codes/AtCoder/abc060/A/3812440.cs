using System;
class A{
  static void Main(){
    var s = Console.ReadLine().Split(' ');
    var ans = s[0][s[0].Length-1] == s[1][0] && s[1][s[1].Length-1] == s[2][0]? "YES":"NO";
    Console.WriteLine(ans);
  }
}