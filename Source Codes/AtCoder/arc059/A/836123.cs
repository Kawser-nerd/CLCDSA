using System;
using System.Collections.Generic;
using System.Linq;

class Program {
    static int ReadInt() { return int.Parse(Console.ReadLine()); }
    static int[] ReadInts() { return Console.ReadLine().Split().Select(int.Parse).ToArray(); }
    static string[] ReadStrings() { return Console.ReadLine().Split(); }

    static int Calc(int[] xs) {
        int min = xs.Min();
        int max = xs.Max();

        int ans = int.MaxValue;
        for (int i = min; i <= max; i++) {
            int d = 0;
            for (int j = 0; j < xs.Length; j++) {
                int x = Math.Abs(xs[j] - i);
                d += x * x;
            }
            ans = Math.Min(ans, d);
        }
        return ans;
    }

    static void Main() {
        ReadInt();
        var xs = ReadInts();
        Console.WriteLine(Calc(xs));
    }
}