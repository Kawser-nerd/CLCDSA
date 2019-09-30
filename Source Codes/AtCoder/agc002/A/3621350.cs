using System.Collections.Generic;
using static System.Console;

class Program {
    static void Main() {
        var a = NextInt();
        var b = NextInt();

        WriteLine(calc(a, b));
    }

    static string calc(int a, int b) {
        if (a <= 0 && 0 <= b) {
            return "Zero";
        } else if (a < 0 && (b - a) % 2 == 0) {
            return "Negative";
        }
        return "Positive";
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