using System;
using System.Collections.Generic;
using System.Linq;

class Program {
    static string ReadLine() { return Console.ReadLine(); }
    static int ReadInt() { return int.Parse(ReadLine()); }
    static int[] ReadInts() { return ReadLine().Split().Select(int.Parse).ToArray(); }
    static string[] ReadStrings() { return ReadLine().Split(); }

    static double F(double p, double x) {
        return x + p / Math.Pow(2, x / 1.5);
    }

    static double Calc(double p) {
        double lo = 0;
        double hi = p;

        while (true) {
            if (Math.Abs(hi - lo) < 1e-8) {
                return F(p, (lo + hi) / 2);
            }

            double x1 = lo + (hi - lo) / 3; // (hi + lo * 2) / 3
            double x2 = hi - (hi - lo) / 3; // (hi * 2 + lo) / 3
            if (F(p, x1) >= F(p, x2)) {
                lo = x1;
            }
            else {
                hi = x2;
            }
        }
    }

    static void Main() {
        var s = ReadLine();
        double p = double.Parse(s);
        Console.WriteLine(Calc(p));
    }
}