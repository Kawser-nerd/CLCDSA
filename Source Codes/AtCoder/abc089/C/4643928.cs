using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static void Main(string[] args)
    {
        var n = int.Parse(Console.ReadLine());
        var dict = new Dictionary<char, int>();

        for (int i = 0; i < n; i++)
        {
            var c = Console.ReadLine()[0];
            switch (c)
            {
                case 'M':
                case 'A':
                case 'R':
                case 'C':
                case 'H':
                    if (dict.ContainsKey(c))
                    {
                        dict[c]++;
                    }
                    else
                    {
                        dict[c] = 1;
                    }
                    break;
            }
        }

        var d = dict.Values.ToArray();
        var ans = dfs(0, 3, d);
        Console.WriteLine(ans);
    }

    static long dfs(int i, int n, int[] d)
    {
        if (n == 0)
        {
            return 1;
        }
        var ans = 0L;
        for (; i <= d.Length - n; i++)
        {
            ans += d[i] * dfs(i + 1, n - 1, d);
        }
        return ans;
    }
}