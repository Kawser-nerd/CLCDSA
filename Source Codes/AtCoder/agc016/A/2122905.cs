using System;

public class Hello
{
    public static void Main()
    {
        var aL = "abcdefghijklmnopqrstuvwxyz";
        var s = Console.ReadLine().Trim();
        var ret = 999999999;
        for (int i = 0; i < aL.Length; i++)
            ret = Math.Min(ret, getChange(s, aL[i]));
        Console.WriteLine(ret);
    }
    public static int getChange(string s, char c)
    {
        var ret = 0;
        while (true)
        {
            var cc = s.Replace(c.ToString(), "").Length;
            if (cc == 0) return ret;
            var ns = "";
            for (int i = 0; i < s.Length - 1; i++)
                if (s[i] == c | s[i + 1] == c) ns += c;
                else ns += s[i];
            ret++;
            s = ns;
        }
    }
}