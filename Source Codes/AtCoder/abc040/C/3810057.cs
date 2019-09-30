using System;
using System.Collections.Generic;
using static System.Console;

class Program
{
    static int n = NextInt();
    static int[] a = new int[n];
    static int[] visited = new int[n];

    static int BFS()
    {
        var q = new Queue<int>();
        q.Enqueue(0);

        while (q.Count != 0)
        {
            var x = q.Dequeue();
            if (x == n - 1)
            {
                return visited[x];
            }
            foreach (var k in new int[] { x + 1, x + 2 })
            {
                if (k < n)
                {
                    var tmp = visited[x] + Math.Abs(a[k] - a[x]);
                    if (visited[k] == 0 || tmp < visited[k])
                    {
                        visited[k] = tmp;
                        q.Enqueue(k);
                    }
                }
            }
        }
        return -1;
    }

    static void Main()
    {
        for (var i = 0; i < n; i++)
        {
            a[i] = NextInt();
        }
        WriteLine(BFS());
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