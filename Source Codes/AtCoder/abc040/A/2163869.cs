using System;
using System.Linq;

class Program {
    static void Main() {
        int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int n = a[0];
        int x = a[1];
        Console.WriteLine(Math.Min(x - 1, n - x));
    }
}