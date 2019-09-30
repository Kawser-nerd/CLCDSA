using System.Collections.Generic;
using static System.Console;

class Program {
    static void Main() {
        var S = NextString();
        var x = new HashSet<char>();
        var y = new HashSet<char>();

        foreach (var v in S) {
            switch (v) {
                case 'N':
                    goto case 'S';
                case 'S':
                    y.Add(v);
                    break;
                case 'W':
                    goto case 'E';
                case 'E':
                    x.Add(v);
                    break;
            }
        }
        if (x.Count % 2 == 0 && y.Count % 2 == 0) {
            WriteLine("Yes");
        } else {
            WriteLine("No");
        }
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