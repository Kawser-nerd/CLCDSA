using System;

class Program {
  static void Main() {
    int A = 1, B = 1, C = 1;
    int a = int.Parse(Console.ReadLine());
    int b = int.Parse(Console.ReadLine());
    int c = int.Parse(Console.ReadLine());
    if (a < b) A++;
    if (a < c) A++;
    if (b < a) B++;
    if (b < c) B++;
    if (c < a) C++;
    if (c < b) C++;
    Console.WriteLine("{0}\n{1}\n{2}", A, B, C);
  }
}