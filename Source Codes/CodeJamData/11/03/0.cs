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


    int count;
    char[] car;
    Dictionary<string, char> dicc;
    Dictionary<string, char> dicr;


    void calc()
    {
        int lll;
        int loopmax = input();
        for (lll = 1; lll <= loopmax; lll++)
        {
            long ret = 0;
            int check = 0;
            int min = 99999999;
            bool flag = true;
            int n = input();
            int[] num = inputarray();
            foreach (int a in num)
            {
                ret += a;
                check ^= a;
                min = Math.Min(a, min);
            }
            if (num.Length <= 1) flag = false;
            if (check != 0) flag = false;
            ret -= min;

            if (flag)
            {
                Console.WriteLine("Case #{0}: {1}", lll, ret);
            }
            else
            {
                Console.WriteLine("Case #{0}: {1}", lll, "NO");
            }

        }
    }
}