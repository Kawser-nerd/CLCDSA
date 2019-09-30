using System;
class A{
  public static void Main(){
    var s = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
    Console.WriteLine((Math.Abs(s[0]-s[2])<=s[3] || (Math.Abs(s[0] - s[1]) <= s[3] && Math.Abs(s[2] - s[1]) <= s[3])?"Yes":"No"));
  }
}