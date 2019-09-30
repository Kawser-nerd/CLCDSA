using System;

class Program
{
    static void Main(string[] args)
    {
        var s = Console.ReadLine().ToCharArray();

        var f1 = s[0] == 'A';
        s[0] = 'a';

        var f2 = 0;
        var i = 2;
        for (; i <= s.Length - 2; i++)
        {
            if (s[i] == 'C')
            {
                s[i] = 'c';
                f2++;
            }
        }

        var f3 = true;
        for (int j = 0; j < s.Length; j++)
        {
            f3 &= char.IsLower(s[j]);
        }

        Console.WriteLine(f1 && f2 == 1 && f3 ? "AC" : "WA");
    }
}