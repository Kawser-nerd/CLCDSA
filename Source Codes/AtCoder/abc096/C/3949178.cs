using System;
using System.Diagnostics;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static void Main()
    {
        string[] cin = Console.ReadLine().Split();
        int h = int.Parse(cin[0]);
        int w = int.Parse(cin[1]);
        string[] s = new string[h];
        for (int i = 0; i < h; i++)
        {
            s[i] = Console.ReadLine();
        }
        bool flag = false;
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (s[i][j] == '#')
                {
                    if (Check(s, i, j)) flag = true;
                }
                if (flag) break;
            }
            if (flag) break;
        }
        if (flag) Console.WriteLine("No");
        else Console.WriteLine("Yes");
    }

    static bool Check(string[] s, int i, int j)
    {
        if (i != 0)
            if (s[i - 1][j] == '#') return false;
        if (i != s.Length - 1)
            if (s[i + 1][j] == '#') return false;
        if (j != 0)
            if (s[i][j - 1] == '#') return false;
        if (j != s[i].Length - 1)
            if (s[i][j + 1] == '#') return false;
        return true;
    }
}