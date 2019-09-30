using System;
using static System.Console;

class Program
{
    static void Main()
    {
        var N = int.Parse(NextStr());
        var T = int.Parse(NextStr());
        var pre = int.MinValue / 2;
        var ans = 0;

        for (var i = 0; i < N; i++)
        {
            var Ai = int.Parse(ReadLine());
            ans += Math.Min(Ai - pre, T);
            pre = Ai;
        }
        WriteLine(ans);
    }

    static string NextStr()
    {
        string result = "";
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