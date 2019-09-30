using System;
using System.Linq;
class c
{
    static void Main()
    {
        var inp = Console.ReadLine().ToCharArray();
        int ans = int.MaxValue;
        for (char c = 'a'; c <= 'z'; c++)
        {
            if (!inp.Contains(c)) continue;
            var s = new string(inp).ToCharArray();
            while (s.Distinct().Count() > 1)
            {
                for (int i = 0; i < s.Length - 1; i++)
                {
                    if (s[i + 1] == c) s[i] = c;
                }
                s = s.Where((f, g) => g < s.Length - 1).ToArray();
            }
            ans = Math.Min(ans, inp.Length - s.Length);
        }
        Console.WriteLine(ans);
    }
}