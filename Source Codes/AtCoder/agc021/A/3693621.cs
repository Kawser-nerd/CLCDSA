using System;
using System.Collections.Generic;
using static System.Console;

class Program {
    static void Main() {
        var n = NextString();
        var flg = 0;

        for (var i = 0; i < n.Length; i++) {
            if (i != 0 && n[i] != '9') {
                flg = 1;
            }
        }
        WriteLine(Convert.ToInt32(n[0] + "") + 9 * (n.Length - 1) - flg);
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