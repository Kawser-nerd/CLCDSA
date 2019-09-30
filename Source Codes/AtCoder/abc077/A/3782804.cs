using System;
class A{
  public static void Main(){
    var s = Console.ReadLine();
    var r = Console.ReadLine();
    Console.WriteLine(s[0] == r[2] && s[1] == r[1] && s[2] == r[0]? "YES":"NO");
  }
}