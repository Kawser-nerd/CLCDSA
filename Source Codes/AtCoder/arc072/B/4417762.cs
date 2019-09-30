using System;
using System.Linq;
class P { static void Main() { long[] x; Console.WriteLine(Math.Abs((x = Console.ReadLine().Split().Select(long.Parse).ToArray())[0] - x[1]) <= 1 ? "Brown" : "Alice"); } }