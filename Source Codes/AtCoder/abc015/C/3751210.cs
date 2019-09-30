using System.Collections.Generic;
using static System.Console;

class Program
{
    static int n, k;
    static int[,] t;

    static void Main()
    {
        n = NextInt();
        k = NextInt();
        t = new int[n, k];
        for (var i = 0; i < n; i++)
        {
            for (var j = 0; j < k; j++)
            {
                t[i, j] = NextInt();
            }
        }
        if (DFS(0, 0))
        {
            WriteLine("Found");
        }
        else
        {
            WriteLine("Nothing");
        }
    }

    static bool DFS(int i, int v)
    {
        if (i == n)
        {
            return v == 0;
        }
        for (var j = 0; j < k; j++)
        {
            if (DFS(i + 1, t[i, j] ^ v))
            {
                return true;
            }
        }
        return false;
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