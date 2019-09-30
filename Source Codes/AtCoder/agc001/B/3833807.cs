using System;
using System.Linq;
using System.Collections.Generic;

class Program{
  static long Get(long n, long x, long result)
  {
    //Console.WriteLine($"{n} {x} {result}");
    if(x == 0) return result;
    if(n < x) return Get(x, n, result);
    return Get(x, n % x, result + n / x * x * 3);
  }
  static void Main()
  {
    string[] inputs = Console.ReadLine().Split();
    long n = long.Parse(inputs[0]);
    long x = long.Parse(inputs[1]);
    Console.WriteLine(Get(n -x, x, 0));
  }
}