using System;
using System.Collections.Generic;
using static System.Console;

class Program
{
    static void Main()
    {
        var n = NextInt();
        var m = pow(10, n.ToString().Length);
        var a = new long[n];
        for (var i = 0; i < n; i++)
        {
            a[i] = NextInt() * m + i + 1;
        }
        Array.Sort(a);
        Array.Reverse(a);
        foreach (var v in a)
        {
            WriteLine(v % m);
        }
    }

    static long pow(int a, int x)
    {
        var result = 1;
        for (var i = 0; i < x; i++)
        {
            result *= a;
        }
        return result;
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