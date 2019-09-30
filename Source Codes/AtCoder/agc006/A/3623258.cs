using System.Collections.Generic;
using static System.Console;

class Program {
    static void Main() {
        var n = NextInt();
        var s = NextString();
        var t = NextString();

        var overlap = 0;
        for (var i = n; i >= 0; i--) {
            if (s.Substring(n - i, i) == t.Substring(0, i)) {
                overlap = i;
                break;
            }
        }
        WriteLine(2 * n - overlap);
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