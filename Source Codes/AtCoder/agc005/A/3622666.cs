using System;
using System.Collections.Generic;
using static System.Console;

class Program {
    static void Main() {
        var cnt = 0;
        var cntS = 0;
        var X = NextString();

        foreach (var v in X) {
            switch (v) {
                case 'S':
                    cntS++;
                    break;
                case 'T':
                    if (cntS == 0) { cnt++; }
                    cntS = Math.Max(0, cntS - 1);
                    break;
            }
        }
        WriteLine(cnt + cntS);
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