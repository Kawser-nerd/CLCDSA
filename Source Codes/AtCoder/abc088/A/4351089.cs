using System;

class Challenge
{
  static void Main()
  {
    var N = int.Parse(Console.ReadLine());
    var A = int.Parse(Console.ReadLine());
    var answer = (N % 500 <= A) ? "Yes" : "No";
    Console.WriteLine(answer);
  }
}