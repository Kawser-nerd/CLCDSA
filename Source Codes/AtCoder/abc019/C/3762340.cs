using System.Collections.Generic;
using System.Linq;
using static System.Console;

class Program
{
    static void Main()
    {
        var n = NextInt();
        var dic = new HashSet<int>();

        foreach (var i in Enumerable.Range(0, n))
        {
            var a = NextInt();
            while (a % 2 == 0)
            {
                a /= 2;
            }
            dic.Add(a);
        }
        WriteLine(dic.Count);
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