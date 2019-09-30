using System.Collections.Generic;
using System.Linq;
using static System.Console;

class Program
{
    static void Main()
    {
        var n = NextInt();
        var ans = 0L;
        var cnt = 0;
        var pre = 0;

        foreach (var i in Enumerable.Range(0, n))
        {
            var a = NextInt();
            cnt++;
            if (i == 0 || pre >= a)
            {
                cnt = 1;
            }
            ans += cnt;
            pre = a;
        }
        WriteLine(ans);
    }

    static int NextInt()
    {
        return int.Parse(NextString());
    }

    static string NextString()
    {
        var result = new List<char>();
        while (true)
        {
            int next = Read();
            if (next < 0)
            {
                break;
            }
            var nextChar = (char)next;
            if (!char.IsWhiteSpace(nextChar))
            {
                result.Add(nextChar);
            }
            else if (nextChar != '\r')
            {
                break;
            }
        }
        return string.Join("", result);
    }
}