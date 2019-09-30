using System;

class Program
{
    static void Main(string[] args)
    {
        var s = Console.ReadLine();
        var t = Console.ReadLine();
        var k = m1(s, t);

        if (k < 0)
        {
            Console.WriteLine("UNRESTORABLE");
            return;
        }

        var left = s.Substring(0, k).Replace('?', 'a');
        var right = s.Substring(k + t.Length).Replace('?', 'a');
        Console.WriteLine(left + t + right);
    }

    static int m1(string s, string t)
    {
        for (int i = s.Length - t.Length; i >= 0; i--)
        {
            var all = true;
            for (int j = 0; j < t.Length; j++)
            {
                all &= s[i + j] == '?' || s[i + j] == t[j];
            }

            if (all)
            {
                return i;
            }
        }

        return -1;
    }
}