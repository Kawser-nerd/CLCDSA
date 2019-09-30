using System.Collections.Generic;
using System.Linq;
using static System.Console;

class Program {
    static void Main() {
        var N = NextInt();
        var sw = 0;
        foreach (var i in Enumerable.Range(0, N)) {
            var A = NextInt();
            sw = sw ^ A % 2;
        }
        if (sw == 0) {
            WriteLine("YES");
        } else {
            WriteLine("NO");
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