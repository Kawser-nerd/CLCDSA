using System.Collections.Generic;
using static System.Console;

class Program
{
    static void Main()
    {
        var s = NextString();
        var ans = new List<char>();

        foreach (char v in s)
        {
            if (v == 'B')
            {
                if (ans.Count != 0)
                    ans.RemoveAt(ans.Count - 1);
            }
            else
                ans.Add(v);
        }
        WriteLine(string.Join("", ans));
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