using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        string s = Console.ReadLine();
        int[][] p = new int[26][];
        bool[][] b = new bool[26][];
        for (int i = 0; i < 26; i++)
        {
            b[i] = new bool[s.Length];
        }
        for (int i = 0; i < s.Length; i++)
        {
            b[s[i] - 'a'][i] = true;
        }
        for (int i = 0; i < 26; i++)
        {
            p[i] = new int[s.Length];
            if (!b[i][s.Length - 1]) p[i][s.Length - 1] = 1;
            for (int j = s.Length - 2; j >= 0; j--)
            {
                if (b[i][j]) p[i][j] = 0;
                else p[i][j] = p[i][j + 1] + 1;
            }
        }
        Console.WriteLine(p.Select(x => x.Max()).Min());
    }
}