using System;
using System.Collections.Generic;
using static System.Console;

class Program {
    static void Main() {
        var n = NextInt();
        var c = NextInt();
        var k = NextInt();
        var t = new int[n];
        var ans = 0;
        var waitStart = 0;
        var waitPeople = 0;

        for (var i = 0; i < n; i++) {
            t[i] = NextInt();
        }
        Array.Sort(t);

        for (var i = 0; i < n; i++) {
            if (t[i] - waitStart > k || waitPeople == c) {
                waitPeople = 0;
            }
            waitPeople++;

            if (waitPeople == 1) {
                waitStart = t[i];
                ans++;
            }
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