using System.Collections.Generic;
using System;

public class Hello
{
    public static void Main()
    {
        Console.ReadLine();
        var s1 = Console.ReadLine().Trim();
        var s2 = Console.ReadLine().Trim();
        var d1 = setDic(s1);
        var d2 = setDic(s2);
        var ret = 0;
        foreach (var x in d1)
        {
            if (!d2.ContainsKey(x.Key)) { Console.WriteLine(-1); goto end; }
            else
            {
                var w = (x.Value + d2[x.Key] - 1) / d2[x.Key];
                ret = Math.Max(ret, w);
            }
        }
        Console.WriteLine(ret);
        end:;
    }
    public static Dictionary<char,int >  setDic ( string s)
    {
        var d = new Dictionary<char, int>();
        for (int i = 0; i < s.Length; i++)
        {
            if (d.ContainsKey(s[i])) d[s[i]]++;
            else d[s[i]] = 1;
        }
        return d;
    }
}