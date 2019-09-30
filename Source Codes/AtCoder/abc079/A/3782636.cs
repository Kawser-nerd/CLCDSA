using System;
class A{
  public static void Main(){
    var s = Console.ReadLine();
    Console.WriteLine(s[1] == s[2] && (s[1] == s[0] || s[1] == s[3])? "Yes":"No");
  }
}