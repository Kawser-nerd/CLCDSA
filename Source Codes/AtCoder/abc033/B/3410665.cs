using System.Collections.Generic;
using System.Linq;
using static System.Console;

class Program
{
    static void Main()
    {
        int n = NextInt();
        var dic = GetMap(n);

        int DicValuesSum = dic.Values.Sum();
        var ans = "atcoder";

        foreach (var k in dic.Keys)
        {
            if (2 * dic[k] > DicValuesSum)
            {
                ans = k;
                break;
            }
        }
        WriteLine(ans);
    }

    static Dictionary<string, int> GetMap(int N)
    {
        var result = new Dictionary<string, int> { };

        for (var i = 0; i < N; i++)
        {
            string s = NextString();
            int p = NextInt();
            if (result.ContainsKey(s))
                result[s] += p;
            else
                result[s] = p;
        }
        return result;
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

    static int NextInt()
    {
        return int.Parse(NextString());
    }
}