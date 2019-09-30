using System;
class A{
  public static void Main(){
    var s = Console.ReadLine().Split(' ');
    Console.WriteLine(s[0] == s[1]? "=": s[0][0]-'0' > s[1][0]-'0'?">":"<");
  }
}