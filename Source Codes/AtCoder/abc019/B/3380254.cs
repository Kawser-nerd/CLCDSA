using System;
using System.Linq;
using static System.Console;

class Program
{
    static void Main(string[] args)
    {
        var s = ReadLine();
        var pre = '-';
        var cnt = 0;
        var ans = "";

        foreach (var item in ($"{s} ").Select((v, i) => new { v, i }))
        {
            if (item.i != 0)
            {
                if (item.i == s.Length || item.v != pre)
                {
                    ans += pre + cnt.ToString();
                    cnt = 0;
                }
            }
            cnt++;
            pre = item.v;
        }
        WriteLine(ans);
    }
}