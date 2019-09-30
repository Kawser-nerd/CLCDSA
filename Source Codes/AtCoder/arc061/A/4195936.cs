using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Text;
using System.Linq;
class Program
{
    static void Main()
    {
        string s = Console.ReadLine();
        int n = s.Length - 1;
        ulong ans = 0;
        for (uint i = 0; i < (uint)Math.Pow(2, n); i++)
        {
            long v = (int)Char.GetNumericValue(s[0]);
            for (int j = 0; j < n; j++)
            {
                if ((i >> j & 1) == 0)
                {
                    v *= 10;
                    v += (int)Char.GetNumericValue(s[j + 1]);
                }
                else
                {
                    ans += (ulong)v;
                    v = (int)Char.GetNumericValue(s[j + 1]);
                }
            }
            ans += (ulong)v;
        }
        Console.WriteLine(ans);
    }
}