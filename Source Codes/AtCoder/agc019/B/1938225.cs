using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        string s = Console.ReadLine();
        long res = 1;
        long[] a = new long[26];
        foreach (var i in s)
        {
            a[i - 'a']++;
        }
        for (int i = 1; i < 26; i++)
        {
            for (int j = 0; j < i; j++)
            {
                res += a[j] * a[i];
            }
        }
        Console.WriteLine(res);
    }
}