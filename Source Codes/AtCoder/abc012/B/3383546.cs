using System;

class Program {
  static void Main() {
    int n = int.Parse(Console.ReadLine());
    int h = n / 3600;
    int m = n % 3600 / 60;
    int s = n % 60;
    Console.WriteLine($"{h:00}:{m:00}:{s:00}");
  }
}