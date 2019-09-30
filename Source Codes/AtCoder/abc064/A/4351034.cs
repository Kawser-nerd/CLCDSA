using System;

class Challenge
{
  static void Main()
  {
    var input = Console.ReadLine().Split();
    var r = int.Parse(input[0]);
    var g = int.Parse(input[1]);
    var b = int.Parse(input[2]);
    var result = r*100 + g*10 + b;
    var str = (result % 4 == 0) ? "YES" : "NO";
    Console.WriteLine(str);
  }
}