using System;

public class Hello
{
    public static void Main()
    {
        var s = Console.ReadLine().Trim();
        var ret = "";
        var count = 1;
        var pre = s[0];
        for (int i = 1; i < s.Length; i++)
            if (s[i] == pre) count++;
            else
            {
                ret += pre + count.ToString();
                pre = s[i];
                count = 1;
            }
        ret += pre + count.ToString();
        Console.WriteLine(ret);
    }
}