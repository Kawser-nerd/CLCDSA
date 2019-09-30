using System;
using System.Linq;
using System.Diagnostics;
using System.Collections.Generic;

public class Test
{
    public static void Main()
    {
        int[][] table = 
        {
            new int[] {2,2 },
            new int[] {1,3 }
        };

        Console.ReadLine();
        string s = Console.ReadLine();
        string t = Console.ReadLine();
        List<int> type = new List<int>();
        for (int i = 0; i < s.Length; i++)
        {
            if (s[i] == t[i])
            {
                type.Add(0);
            }
            else
            {
                type.Add(1);
                i++;
            }
        }
        long res;
        if (type[0] == 0)
        {
            res = 3;
        }
        else
        {
            res = 6;
        }
        for (int i = 1; i < type.Count; i++)
        {
            res = (res * table[type[i - 1]][type[i]]) % 1000000007;
        }
        Console.WriteLine(res);
    }
}