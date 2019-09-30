using System.Collections.Generic;
using static System.Console;

class Program
{
    static void Main()
    {
        var x = NextInt();
        for (var n = 1; n <= x; n++)
        {
            if (Pow(n, 4) == x)
            {
                WriteLine(n);
                break;
            }
        }
    }

    static int Pow(int a, int b)
    {
        var result = 1;
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