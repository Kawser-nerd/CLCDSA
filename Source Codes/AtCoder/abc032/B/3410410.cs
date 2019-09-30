using System.Collections.Generic;
using static System.Console;

class Program
{
    static void Main()
    {
        string s = NextString();
        int k = NextInt();

        var dic = new Dictionary<string, bool> { };

        for (var i = 0; i <= s.Length - k; i++)
        {
            dic[s.Substring(i, k)] = true;
        }

        WriteLine(dic.Count);
    }


    static int NextInt()
    {
        return int.Parse(NextString());
    }

    static string NextString()
    {
        var result = "";
        while (true)
        {
            int tmp0 = Read();
            if (tmp0 < 0)
                break;
            var tmp = (char)tmp0;
            if (!string.IsNullOrWhiteSpace(tmp + ""))
                result += tmp;
            else if (tmp != '\r')
                break;
        }
        return result;
    }
}