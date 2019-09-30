using System;

class Program {
  static void Main() {
    int n = int.Parse(Console.ReadLine());
    if (n <= 59) Console.WriteLine("Bad");
    else if (n <= 89) Console.WriteLine("Good");
    else if (n <= 99) Console.WriteLine("Great");
    else Console.WriteLine("Perfect");
  }
}