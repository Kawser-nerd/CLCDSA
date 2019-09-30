using System.Collections.Generic;
using static System.Console;

class Program
{
    static void Main()
    {
        var n = NextInt();
        var q = NextInt();

        var ans = new int[n];

        for (var i = 0; i < q; i++)
        {
            var l = NextInt();
            var r = NextInt();
            var t = NextInt();

            for (var j = l; j <= r; j++)
            {
                ans[j - 1] = t;
            }
        }
        foreach (var v in ans)
        {
            WriteLine(v);
        }
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