using System.Collections.Generic;
using System.Linq;
using static System.Console;

class Program
{
    static void Main()
    {
        var n = NextInt();
        var k = NextInt();
        var s = new int[n];
        foreach (var i in Enumerable.Range(0, n))
        {
            s[i] = NextInt();
        }
        var v = 1L;
        var ini = 0;
        var cnt = 0;
        var best = 0;

        if (!s.Contains(0))
        {
            foreach (var si in s)
            {
                v *= si;
                cnt++;

                if (v <= k && cnt > best)
                {
                    // 1.???
                    best = cnt;
                }
                else
                {
                    // 2.???????
                    while (v > k)
                    {
                        v /= s[ini];
                        ini++;
                        cnt--;
                        if (cnt == 0)
                        {
                            // 3.???
                            break;
                        }
                    }
                }
            }
            WriteLine(best);
        }
        else
        {
            WriteLine(n);
        }
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