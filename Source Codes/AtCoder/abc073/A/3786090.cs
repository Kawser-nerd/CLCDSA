using System;
class A{
  public static void Main(){
    var s = Console.ReadLine();
    Console.WriteLine(s[0] == '9' || s[1] == '9'? "Yes":"No");
  }
}