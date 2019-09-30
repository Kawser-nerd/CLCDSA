using System;

class Program
{
    static void Main()
    {
        var s = Console.ReadLine();
        long ans = 0;
        for (int i = 0; i < s.Length; i++)
            ans += s[i] == 'U' ? s.Length - 1 + i : 2 * (s.Length - 1) - i;
        Console.WriteLine(ans);
    }
}