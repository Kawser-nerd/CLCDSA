using System.Collections.Generic;
using System.Linq;
using static System.Console;

class Program {
    static void Main() {
        var n = NextLong();
        var m = NextLong();
        var s = NextString();
        var t = NextString();
        var l = LCM(n, m);
        var dic = new Dictionary<long, char>();

        foreach (var i in Enumerable.Range(0, s.Length)) {
            var j = i * l / n;
            dic[j] = s[i];
        }

        foreach (var i in Enumerable.Range(0, t.Length)) {
            var j = i * l / m;
            if (dic.ContainsKey(j) && dic[j] != t[i]) {
                WriteLine(-1);
                return;
            }
        }
        WriteLine(l);
    }

    static long LCM(long x, long y) {
        return x * y / GCD(x, y);
    }

    static long GCD(long x, long y) {
        if (x < y) {
            return GCD(y, x);
        } else if (y == 0) {
            return x;
        }
        return GCD(y, x % y);
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