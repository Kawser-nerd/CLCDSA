using System;
using System.Collections.Generic;

class Myon
{
    int input()
    {
        return int.Parse(Console.ReadLine());
    }

    int[] inputarray()
    {
        string[] s = Console.ReadLine().Split(' ');
        int[] ret = new int[s.Length];
        for (int i = 0; i < s.Length; i++) ret[i] = int.Parse(s[i]);
        return ret;
    }

    Myon() { }
    public static void Main()
    {
        new Myon().calc();
    }

    void calc()
    {
        int lll;
        int loopmax = input();
        for (lll = 1; lll <= loopmax; lll++)
        {
            int res = 0;
            int i;
            int n = input();
            int[] num = inputarray();
            for (i = 0; i < n; i++)
            {
                if (num[i] != i + 1) res++;
            }
            string ret = res.ToString() + ".000000";
            Console.WriteLine("Case #{0}: {1}", lll, ret);  
        }
    }
}