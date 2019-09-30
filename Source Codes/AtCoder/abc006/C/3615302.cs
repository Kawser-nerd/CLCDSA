using System.Collections.Generic;
using static System.Console;

class Program {
    static void Main() {
        var n = NextInt();
        var m = NextInt();

        for (var oldMan = 0; oldMan <= 1; oldMan++) {
            for (var babies = 0; babies <= n - oldMan; babies++) {
                var grownUps = n - babies - oldMan;
                if (grownUps * 2 + oldMan * 3 + babies * 4 == m) {
                    WriteLine(grownUps + " " + oldMan + " " + babies);
                    return;
                }
            }
        }
        WriteLine("-1 -1 -1");
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