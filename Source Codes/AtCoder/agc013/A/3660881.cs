using System;
using System.Collections.Generic;
using static System.Console;

class Program {
    static void Main() {
        var n = NextInt();
        var way = 0;
        var pre = 0;
        var ans = 1;

        for (var i = 0; i < n; i++) {
            var now = NextInt();
            if (i == 0 || now - pre == 0) {
                //pass
            } else if (way == 0) {
                way = Math.Sign(now - pre);
            } else if (Math.Sign(now - pre) != way) {
                ans++;
                way = 0;
            }
            pre = now;
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