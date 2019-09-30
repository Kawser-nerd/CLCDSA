using System.Collections.Generic;
using static System.Console;
using static System.Math;

class Program {
    static void Main() {
        var a = NextLong();
        var b = NextLong();
        var c = NextLong();

        var s = Min(a, Min(b, c));
        var l = Max(a, Max(b, c));
        var m = a + b + c - s - l;

        foreach (var v in new long[] { s, m, l }) {
            if (v % 2 == 0) {
                WriteLine(0);
                return;
            }
        }
        WriteLine(s * m);
    }

    static long NextLong() {
        return long.Parse(NextString());
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