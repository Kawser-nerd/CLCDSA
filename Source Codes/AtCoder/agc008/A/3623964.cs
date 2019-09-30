using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;

class Program {
    static void Main() {
        var x = NextInt();
        var y = NextInt();
        var ans = int.MaxValue;

        foreach (var i in Enumerable.Range(0, 4)) {
            ans = Math.Min(ans, solve(i, x, y));
        }
        WriteLine(ans);
    }

    static int solve(int i, int x, int y) {
        var t = 0;

        if (i % 2 > 0) {
            x *= -1;
            t++;
        }
        if (i / 2 > 0) {
            y *= -1;
            t++;
        }
        if (x <= y) {
            t += y - x;
            return t;
        }
        return int.MaxValue;
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