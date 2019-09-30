using System;
using System.Collections.Generic;
using static System.Console;

class Program {
    static void Main() {
        var q = NextInt();
        var h = NextInt();
        var s = NextInt();
        var d = NextInt();
        var n = (long)NextInt();

        foreach (var v in new int[] { 4 * q, 2 * h }) {
            s = Math.Min(s, v);
        }
        WriteLine(s * (n % 2) + Math.Min(2 * s, d) * (n / 2));
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