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
        var t = ReadLine();
        var dics = new Dictionary<char, char>();
        var dict = new Dictionary<char, char>();
        for(var i = 0; i < s.Length; i++)
        {
            if (!dics.ContainsKey(s[i]))
                dics[s[i]] = t[i];
            else if(dics[s[i]]!=t[i])
            {
                WriteLine("No");
                return;
            }
            if (!dict.ContainsKey(t[i]))
                dict[t[i]] = s[i];
            else if(dict[t[i]]!=s[i])
            {
                WriteLine("No");
                return;
            }
        }
        WriteLine("Yes");
    }
    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}