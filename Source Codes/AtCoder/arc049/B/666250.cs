using System;
using System.Collections.Generic;
using System.Linq;

class Program {
    static string ReadLine() { return Console.ReadLine(); }
    static int ReadInt() { return int.Parse(ReadLine()); }
    static int[] ReadInts() { return ReadLine().Split().Select(int.Parse).ToArray(); }
    static string[] ReadStrings() { return ReadLine().Split(); }

    static double CalcX(double x, List<int[]> xs) {
        double ret = 0;
        foreach (var t in xs) {
            ret = Math.Max(ret, Math.Abs(x - t[0]) * t[2]);
        }
        return ret;
    }

    static double CalcY(double y, List<int[]> xs) {
        double ret = 0;
        foreach (var t in xs) {
            ret = Math.Max(ret, Math.Abs(y - t[1]) * t[2]);
        }
        return ret;
    }

    static double Calc(List<int[]> xs) {
        int minX = xs.Select(e => e[0]).Min();
        int maxX = xs.Select(e => e[0]).Max();
        int minY = xs.Select(e => e[1]).Min();
        int maxY = xs.Select(e => e[1]).Max();

        double ansX = int.MaxValue;
        double left = minX;
        double right = maxX;
        while (true) {
            if (Math.Abs(right - left) < 1e-6) {
                ansX = CalcX((left + right) / 2, xs);
                break;
            }

            // Console.WriteLine("lt {0} rt {1}", left, right);

            var lt = left + (right - left) / 3;
            var rt = right - (right - left) / 3;

            if (CalcX(lt, xs) > CalcX(rt, xs))
                left = lt;
            else
                right = rt;
        }

        double ansY = int.MaxValue;
        left = minY;
        right = maxY;
        while (true) {
            if (Math.Abs(right - left) < 1e-6) {
                ansY = CalcY((left + right) / 2, xs);
                break;
            }

            var lt = left + (right - left) / 3;
            var rt = right - (right - left) / 3;

            if (CalcY(lt, xs) > CalcY(rt, xs))
                left = lt;
            else
                right = rt;
        }
        return Math.Max(ansX, ansY);
    }

    static void Main() {
        int n = ReadInt();
        var xs = new List<int[]>();
        for (int i = 0; i < n; i++) {
            xs.Add(ReadInts());
        }
        Console.WriteLine(Calc(xs));
    }
}