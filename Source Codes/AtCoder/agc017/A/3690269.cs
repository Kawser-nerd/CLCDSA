using System.Collections.Generic;
using System.Linq;
using static System.Console;

class Program {
    static void Main() {
        var n = NextInt();
        var p = NextInt();
        var odd = 0;
        var even = 0;

        foreach (var i in Enumerable.Range(0, n)) {
            var a = NextInt();
            odd += a % 2;
            even += (a % 2) ^ 1;
        }
        if (odd == 0) {
            WriteLine(Pow(2, even) * Int(p == 0));
        } else {
            WriteLine(Pow(2, odd - 1) * Pow(2, even));
        }
    }

    static long Pow(int a, int b) {
        var result = 1L;
        foreach (var i in Enumerable.Range(0, b)) {
            result *= a;
        }
        return result;
    }

    static int Int(bool ok) {
        if (ok) {
            return 1;
        }
        return 0;
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