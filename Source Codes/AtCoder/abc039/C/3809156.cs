//using System;
using System.Collections.Generic;
using static System.Console;

class Program
{
    static void Main()
    {
        var DRMi = "SiDo--Re--MiFa--So--La--";
        var Si = "WWBWBWW";
        var S = NextString();
        for (var i = 0; ; i++)
        {
            if (Si == S.Substring(i, Si.Length))
            {
                WriteLine(DRMi.Substring((-i * 2 + DRMi.Length) % DRMi.Length, 2));
                break;
            }
        }
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