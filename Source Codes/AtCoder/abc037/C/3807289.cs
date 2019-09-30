using System.Collections.Generic;
using System.Linq;
using static System.Console;

class Program
{
    static void Main()
    {
        var n = NextInt();
        var k = NextInt();
        var a = new int[n];
        foreach (var i in Enumerable.Range(0, n))
        {
            a[i] = NextInt();
        }

        var ans = 0L;
        var cnt = 0L;
        foreach (var i in Enumerable.Range(0, k))
        {
            cnt += a[i];
        }

        foreach (var i in Enumerable.Range(0, n - k + 1))
        {
            if (i != 0)
            {
                cnt += a[i + k - 1] - a[i - 1];
            }
            ans += cnt;
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