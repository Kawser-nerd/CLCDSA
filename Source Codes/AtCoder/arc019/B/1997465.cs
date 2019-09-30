using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        string s = Console.ReadLine();
        int diff = 0;
        int res = 0;
        for (int i = 0; i < s.Length / 2; i++)
        {
            if (s[i] != s[s.Length - i - 1]) diff++;
        }
        if (diff == 0)
        {
            res = (s.Length / 2) * 2 * 25;
        }
        else if(diff == 1)
        {
            res = (s.Length - 2) * 25 + 2 * 24;
        }
        else
        {
            res = s.Length * 25;
        }
        Console.WriteLine(res);
    }
}