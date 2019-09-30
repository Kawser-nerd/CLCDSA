using System;
using System.Collections.Generic;
using System.Linq;

class Program {
    static int ReadInt() { return int.Parse(Console.ReadLine()); }
    static int[] ReadInts() { return Console.ReadLine().Split().Select(int.Parse).ToArray(); }
    static string[] ReadStrings() { return Console.ReadLine().Split(); }

    static bool Match(int p, string s, string t) {
        if (p < 0 || p + t.Length > s.Length) return false;

        for (int i = 0; i < t.Length; i++) {
            if (s[p + i] != t[i])
                return false;
        }
        return true;
    }

    static bool Calc(string s) {
        var ts = new[] { "dream", "dreamer", "erase", "eraser" };
        int p = s.Length - 1;
        while (p >= 0) {
            bool found = false;
            foreach (var t in ts) {
                if (Match(p - t.Length + 1, s, t)) {
                    p -= t.Length;
                    found = true;
                    break;
                }
            }
            if (!found) return false;
        }
        return true;
    }

    static void Main() {
        var s = Console.ReadLine();
        Console.WriteLine(Calc(s) ? "YES" : "NO");
    }
}