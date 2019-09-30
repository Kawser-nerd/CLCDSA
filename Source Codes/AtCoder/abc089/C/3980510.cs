using System;
using System.Diagnostics;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        var dic = new Dictionary<char, int>();
        for (int i = 0; i < n; i++)
        {
            string s = Console.ReadLine();
            if (s[0] == 'M' || s[0] == 'A' || s[0] == 'R' || s[0] == 'C' || s[0] == 'H')
            {
                // ?????++???????1???
                if (dic.ContainsKey(s[0])) dic[s[0]]++;
                else dic[s[0]] = 1;
            }
        }
        long ans = 0;
        for (int i = 0; i < 1 << dic.Count; i++)
        {
            // ??????3??????????
            var bits = new bool[dic.Count];
            int m = 0;
            for (int j = 0; j < dic.Count; j++)
            {
                if ((i >> j & 1) == 1)
                {
                    bits[j] = true;
                    m++;
                }
            }
            if (m == 3)
            {
                long tmp = 1;
                for (int j = 0; j < dic.Count; j++)
                {
                    if (bits[j]) tmp *= dic.ElementAt(j).Value;
                }
                ans += tmp;
            }
        }
        Console.WriteLine(ans);
    }
}