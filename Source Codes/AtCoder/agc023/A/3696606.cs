using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;

class Program {
    static void Main() {
        var n = NextInt();
        var s = new long[n + 1];

        foreach (var i in Enumerable.Range(0, n)) {
            var a = NextInt();
            s[i + 1] = s[i] + a;
        }
        Array.Sort(s);
        var ans = 0L;
        var cnt = 0;
        foreach (var i in Enumerable.Range(0, s.Length - 1)) {
            if (s[i] == s[i + 1]) {
                cnt++;
            } else {
                cnt = 0;
            }
            ans += cnt;
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