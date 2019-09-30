using System.Collections.Generic;
using static System.Console;

class Program {
    static void Main() {
        var a = NextLong();
        var b = NextLong();
        var x = NextLong();

        var ans = 0L;
        ans += b / x;
        if (a == 0L) {
            ans++;
        } else {
            ans -= (a - 1) / x;
        }
        WriteLine(ans);
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