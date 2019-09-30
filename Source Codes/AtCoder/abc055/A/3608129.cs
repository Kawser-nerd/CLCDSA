using System;

class prog{
  static void Main(){
    int n = int.Parse(Console.ReadLine());
    Console.WriteLine(800 * n - 200 * (n / 15));
  }
}