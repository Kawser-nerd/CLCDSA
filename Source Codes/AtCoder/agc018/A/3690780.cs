using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;

class Program {
    static void Main() {
        var n = NextInt();
        var k = NextInt();
        var g = 0;
        var m = 0;

        foreach (var i in Enumerable.Range(0, n)) {
            var a = NextInt();
            if (i == 0) {
                g = a;
                m = a;
            }
            g = gcd(g, a);
            m = Math.Max(m, a);
        }
        if (k % g == 0 && k <= m) {
            WriteLine("POSSIBLE");
        } else {
            WriteLine("IMPOSSIBLE");
        }
    }

    static int gcd(int x, int y) {
        while (y != 0) {
            x %= y;
            var tmp = x;
            x = y;
            y = tmp;
        }
        if (x < 0) {
            x *= -1;
        }
        return x;
    }

    static int NextInt() {
        return int.Parse(NextString());
    }

    static string NextString() {
        var result = new List<char>();
        while (true) {
            int next = Read();
            if (next < 0)
                break;
            var nextChar = (char)next;
            if (!char.IsWhiteSpace(nextChar))
                result.Add(nextChar);
            else if (nextChar != '\r')
                break;
        }
        return string.Join("", result);
    }
}