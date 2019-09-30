using System;
using System.Linq;
using static System.Console;

class class_A
{
    static void Main()
    {
        var s = ReadLine();
        var pre = '-';
        var cnt = 0;
        var ans = "";

        for (var i = 0; i <= s.Length; i++)
        {
            if (i != 0)
            {
                if (i == s.Length || s[i] != pre)
                {
                    ans += pre + cnt.ToString();
                    cnt = 0;
                }
            }
            cnt++;
            if (i != s.Length)
            {
                pre = s[i];
            }
        }
        WriteLine(ans);
    }
}