using System.Collections.Generic;
using static System.Console;

class Program
{
    static void Main()
    {
        var h1 = NextInt();
        var w1 = NextInt();
        var h2 = NextInt();
        var w2 = NextInt();

        var first = new int[] { h1, w1 };
        var second = new int[] { h2, w2 };

        var ans = "NO";

        foreach (var f in first)
        {
            foreach (var s in second)
            {
                if (f == s)
                    ans = "YES";
            }
        }
        WriteLine(ans);
    }

    static string NextString()
    {
        var result = new List<char>();
        while (true)
        {
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

    static int NextInt()
    {
        return int.Parse(NextString());
    }
}