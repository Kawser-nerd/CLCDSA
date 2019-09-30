using System.Collections.Generic;
using System.Linq;
using static System.Console;

class Program {
    static void Main() {
        var n = NextInt();
        var m = 0;
        foreach (var i in Enumerable.Range(1, 9)) {
            foreach (var j in Enumerable.Range(1, 9)) {
                m += i * j;
            }
        }

        foreach (var i in Enumerable.Range(1, 9)) {
            foreach (var j in Enumerable.Range(1, 9)) {
                if (i * j == m - n) {
                    WriteLine(i + " x " + j);
                }
            }
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