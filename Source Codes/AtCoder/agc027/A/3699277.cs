using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;

class Program {
    static void Main() {
        var n = NextInt();
        var x = NextInt();
        var a = new int[n];
        foreach (var i in Enumerable.Range(0, n)) {
            a[i] = NextInt();
        }
        Array.Sort(a);

        var ans = 0;
        foreach (var i in Enumerable.Range(0, n)) {
            if (x < a[i] || (i == n - 1 && x != a[i])) {
                break;
            }
            ans++;
            x -= a[i];
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