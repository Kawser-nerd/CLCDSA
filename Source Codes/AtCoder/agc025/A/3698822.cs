using System;
using System.Collections.Generic;
using static System.Console;

class Program {
    static void Main() {
        var n = NextInt();
        var ans = int.MaxValue;

        for (var a = 1; a < n; a++) {
            var b = n - a;
            ans = Math.Min(ans, DigitsSum(a) + DigitsSum(b));
        }
        WriteLine(ans);
    }

    static int DigitsSum(int x) {
        var result = 0;
        while (x != 0) {
            result += x % 10;
            x /= 10;
        }
        return result;
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