using System;
using System.Linq;
using static System.Console;

class Program
{
    const string atc = "atcoder";

    static void Main()
    {
        var ans = "You can win";

        var s = ReadLine();
        var t = ReadLine();
        foreach (var i in Enumerable.Range(0, s.Length))
        {
            if (s[i] == t[i])
            {
                continue;
            }
            else if (s[i] == '@' || t[i] == '@')
            {
                if (atc.Contains((s[i] + "" + t[i]).Replace("@", "")))
                {
                    continue;
                }
            }
            ans = "You will lose";
        }
        WriteLine(ans);
    }
}