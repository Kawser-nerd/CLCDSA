using System;
using System.Collections.Generic;
using static System.Console;

class Program
{
    static void Main()
    {
        var a = NextInt();
        var b = NextInt();
        var c = NextInt();

        long ans = 1;

        foreach (var v in new int[] { a, b, c })
        {
            ans = (ans * v) % (Pow(10, 9) + 7);
        }
        WriteLine(ans);
    }

    static int Pow(int a, int b)
    {
        int result = 1;
        for (var i = 0; i < b; i++)
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
                break;
            var nextChar = (char)next;
            if (!char.IsWhiteSpace(nextChar))
                result.Add(nextChar);
            else if (nextChar != '\r')
                break;
        }
        return string.Join("", result);
    }
}