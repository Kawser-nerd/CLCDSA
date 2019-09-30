using System.Collections.Generic;
using System.Linq;
using static System.Console;

class Program {
    static void Main() {
        var h = NextInt();
        var w = NextInt();

        var cnt = 0;
        foreach (var i in Enumerable.Range(0, h)) {
            var a = NextString();
            foreach (var c in a) {
                if (c == '#') { cnt++; }
            }
        }
        if (cnt == h + w - 1) {
            WriteLine("Possible");
        } else {
            WriteLine("Impossible");
        }
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