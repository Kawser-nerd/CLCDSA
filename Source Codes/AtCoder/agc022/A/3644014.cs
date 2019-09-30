using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;
using static System.Convert;
using static System.Math;

class Program
{
    static void Main(string[] args)
    {
        var s = ReadLine();
        var set = new HashSet<char>();
        for (var i = 0; i < s.Length; i++)
            set.Add(s[i]);
        if (set.Count != ALFA.Length)
        {
            for (var i = 0; i < ALFA.Length;i++)
                if (!set.Contains(ALFA[i]))
                {
                    s += ALFA[i];
                    break;
                }
            WriteLine(s);
        }
        else
        {
            var r = -1;
            for (var i = 0; i < s.Length - 1; i++)
            {
                if (s[i] < s[i + 1]) r = i;
            }
            if (r == -1) { WriteLine(-1);return; }
            for (var i = r+1; i < s.Length; i++)
                set.Remove(s[i]);
            var ad = ' ';
            for (var i = ALFA.IndexOf(s[r]) + 1; i < ALFA.Length; i++)
                if (!set.Contains(ALFA[i])) { ad = ALFA[i]; break; }
            s = s.Substring(0, r) + ad;
            WriteLine(s);
        }
    }

    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}