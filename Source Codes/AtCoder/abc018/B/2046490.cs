using System;

public class Hello
{
    public static void Main()
    {
        var s = Console.ReadLine().Trim();
        var n = int.Parse(Console.ReadLine().Trim());
        for (int i = 0; i < n; i++)
        {
            string[] line = Console.ReadLine().Trim().Split(' ');
            var L = int.Parse(line[0]);
            var r = int.Parse(line[1]);
            s = getString(s, L, r);
        }
        Console.WriteLine(s);
    }
    public static string getString (string s, int L , int r)
    {
        var s0 = s.Substring(0, L - 1);
        var s1 = s.Substring(L - 1, r - L + 1);
        var s2 = s.Substring(r);
        var w = s1.ToCharArray();
        Array.Reverse(w);
        return s0 + new string(w) + s2;
    }
}