using System;
using System.Linq;
using System.Diagnostics;
using System.Collections.Generic;
class P
{
    static void Main()
    {
        string s = Console.ReadLine();
        int[] count = new int[26];
        for (int i = 0; i < s.Length; i++) count[s[i] - 'a']++;
        int oddcount = count.Count(x => x % 2 == 1);
        int res;
        if (oddcount != 0) res = (((s.Length - oddcount) / 2) / oddcount) * 2 + 1;
        else res = s.Length;
        Console.WriteLine(res);
    }   
}