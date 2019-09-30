using System;
using System.Collections.Generic;
using static System.Console;

class Program {
    static void Main() {
        var n = (long)NextInt();
        var a = NextInt();
        var b = NextInt();
        WriteLine(Math.Max(0, (b - a) * (n - 2) + 1));
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