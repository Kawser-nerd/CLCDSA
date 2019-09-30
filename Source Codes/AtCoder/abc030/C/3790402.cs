using System.Collections.Generic;
using System.Linq;
using static System.Console;

class Program
{
    static void Main()
    {
        var n = NextInt();
        var m = NextInt();
        var x = NextInt();
        var y = NextInt();

        var a = new int[n];
        foreach (var i in Enumerable.Range(0, n))
        {
            a[i] = NextInt();
        }
        var b = new int[m];
        foreach (var j in Enumerable.Range(0, m))
        {
            b[j] = NextInt();
        }

        var ii = 0;
        var jj = 0;
        var t = 0;
        var cnt = 0;

        while (true)
        {
            if (cnt % 2 == 0)
            {
                while (ii < a.Length && a[ii] < t)
                {
                    ii++;
                }
                if (ii == a.Length)
                {
                    break;
                }
                t = a[ii] + x;
            }
            else
            {
                while (jj < b.Length && b[jj] < t)
                {
                    jj++;
                }
                if (jj == b.Length)
                {
                    break;
                }
                t = b[jj] + y;
            }
            cnt++;
        }
        WriteLine(cnt / 2);
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