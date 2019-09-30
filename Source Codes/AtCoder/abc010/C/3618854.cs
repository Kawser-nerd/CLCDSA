using System.Collections.Generic;
using static System.Console;
using static System.Math;

class Program {
    static void Main() {
        var txa = NextDouble();
        var tya = NextDouble();
        var txb = NextDouble();
        var tyb = NextDouble();
        var t = NextDouble();
        var v = NextDouble();
        var n = NextInt();
        var flg = false;

        for (var i = 0; i < n; i++) {
            var x = NextDouble();
            var y = NextDouble();
            var d = 0.0;

            d += Sqrt(Pow(txa - x, 2.0) + Pow(tya - y, 2.0));
            d += Sqrt(Pow(txb - x, 2.0) + Pow(tyb - y, 2.0));

            if (d <= t * v) { flg = true; }
        }
        if (flg) {
            WriteLine("YES");
        } else {
            WriteLine("NO");
        }
    }

    static double NextDouble() {
        return float.Parse(NextString());
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