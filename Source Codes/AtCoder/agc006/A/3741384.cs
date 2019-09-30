using System;
class c
{
    static void Main()
    {
        Console.ReadLine();
        var s = Console.ReadLine();
        var t = Console.ReadLine();
        int ans = int.MaxValue;
        for (int i = 0; i < s.Length; i++)
        {
            for (int j = 0; j < s.Length; j++)
            {
                if (s[i + j] != t[j]) break;
                else if (i + j == s.Length - 1)
                {
                    ans = Math.Min(ans, s.Length + i);
                    break;
                }
            }
        }
        Console.WriteLine(ans == int.MaxValue ? 2 * s.Length : ans);
    }
}