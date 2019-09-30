using System;
using System.Collections.Generic;
using static System.Console;

class Program {
    static void Main() {
        var n = NextInt();
        var a = new int[3 * n];
        for (var i = 0; i < 3 * n; i++) {
            a[i] = NextInt();
        }
        Array.Sort(a);
        Array.Reverse(a);

        var ans = 0L;
        for (var i = 0; i < n; i++) {
            ans += a[2 * i + 1];
        }
        WriteLine(ans);
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