using System.Collections.Generic;
using static System.Console;

class Program
{
    static void Main()
    {
        var w = NextString();
        var dic = new Dictionary<char, int>();

        var ans = "Yes";

        foreach (char v in w)
        {
            if (!dic.ContainsKey(v))
                dic[v] = 0;

            dic[v] += 1;
        }

        foreach (int v in dic.Values)
        {
            if (v % 2 != 0)
            {
                ans = "No";
                break;
            }
        }

        WriteLine(ans);
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