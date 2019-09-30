using System;

public class Program {
  public static void Main(string[] args) {
    var str = Console.ReadLine().Split(' ');
    var a = int.Parse(str[0]);
    var b = int.Parse(str[1]);
    if (b % a  == 0) {
      Console.WriteLine(a + b);
    } else {
      Console.WriteLine(b - a);
    }
  }
}