using System;
class A{
  static void Main(){
    var s = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
    Console.WriteLine(s[2] >= s[0] && s[2] <= s[1]?"Yes":"No");
  }
}