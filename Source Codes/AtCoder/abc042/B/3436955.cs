using System;
using System.Collections.Generic;
using static System.Console;

class Program
{
    static void Main()
    {
        var N = NextInt();
        var L = NextInt();
        var S = new string[] { };

        for (var i = 0; i < N; i++)
        {
            Array.Resize(ref S, S.Length + 1);
            S[S.Length - 1] = ReadLine();
        }
        Array.Sort(S);
        WriteLine(string.Join("", S));
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