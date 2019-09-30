using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static void Main()
    {
        var sx = NextInt();
        var sy = NextInt();
        var tx = NextInt();
        var ty = NextInt();
        var start = new int[] { 1, 1 };
        var target = new int[] { tx - sx + start[0], ty - sy + start[1] };

        var visited = new bool[tx - sx + 3, ty - sy + 3];
        var now = start;
        var dic = new Dictionary<char, int[]>();
        var ans = "";

        dic['U'] = new int[] { 0, 1 };
        dic['D'] = new int[] { 0, -1 };
        dic['L'] = new int[] { -1, 0 };
        dic['R'] = new int[] { 1, 0 };

        foreach (var turn in Enumerable.Range(0, 4))
        {
            int[] goal;
            if (turn % 2 == 0)
            {
                goal = target;
            }
            else
            {
                goal = start;
            }

            while (now[0] != goal[0] || now[1] != goal[1])
            {
                var cnddt = new List<int>();
                foreach (var k in "UDLR")
                {
                    var nxt = new int[] { now[0] + dic[k][0], now[1] + dic[k][1] };
                    if (nxt[0] < 0 || target[0] + 1 < nxt[0]) { }
                    else if (nxt[1] < 0 || target[1] + 1 < nxt[1]) { }
                    else if ((nxt[0] == goal[0] && nxt[1] == goal[1]) || !visited[nxt[0], nxt[1]])
                    {
                        cnddt.Add((diff(nxt, goal) - diff(now, goal) + 1) * 1000 + k);
                    }
                }
                cnddt.Sort();
                var kk = (char)(cnddt[0] % 1000);
                ans += kk;
                var nxxt = new int[] { now[0] + dic[kk][0], now[1] + dic[kk][1] };
                visited[nxxt[0], nxxt[1]] = true;
                now = nxxt;
            }
        }
        Console.WriteLine(ans);
    }

    static int NextInt()
    {
        return int.Parse(NextString());
    }

    static int diff(int[] a, int[] b)
    {
        return Math.Abs(a[0] - b[0]) + Math.Abs(a[1] - b[1]);
    }

    static string NextString()
    {
        var result = new List<char>();
        while (true)
        {
            int next = Console.Read();
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