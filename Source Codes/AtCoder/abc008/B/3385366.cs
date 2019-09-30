using static System.Console;
using System.Collections.Generic;

class Program
{
    static void Main()
    {
        var N = int.Parse(ReadLine());
        var dic = new Dictionary<string, int>();

        for (var i = 0; i < N; i++)
        {
            var S = ReadLine();
            if (dic.ContainsKey(S))
                dic[S] += 1;
            else
                dic[S] = 1;
        }

        var best = 0;
        var ans = "";
        foreach (var k in dic.Keys)
        {
            var v = dic[k];
            if (v > best)
            {
                best = v;
                ans = k;
            }
        }
        WriteLine(ans);
    }
}