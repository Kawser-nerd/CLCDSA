using System;
class A{
  static void Main(){
    var s = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
    Console.WriteLine(s[2] - s[1] <= 0? "delicious": s[2] - s[1] <= s[0]?"safe":"dangerous");
  }
}