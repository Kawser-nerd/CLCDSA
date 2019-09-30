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
        string[] s = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
        int[] ret = new int[s.Length];
        for (int i = 0; i < s.Length; i++) ret[i] = int.Parse(s[i]);
        return ret;
    }

    Myon() { }
    public static void Main()
    {
        new Myon().malti();
    }

    void malti()
    {

        int lll;
        int loopmax = input();
        for (lll = 1; lll <= loopmax; lll++)
        {
            Console.Write("Case #{0}: ", lll);
            calc();
        }
    }


    void calc()
    {
        int a;
        string s = Console.ReadLine();
        int i, j;
        long now = 0;
        List<long> q = new List<long>();
        for (i = 0; i < s.Length; i++)
        {
            int k = s.Length - i - 1;
            if (s[i] == '1')
            {
                now += (long)1 << k;
            }
            else if (s[i] == '?')
            {
                q.Add((long)1 << k);
            }
        }
        long[] qa = q.ToArray();
        int len = qa.Length;
        for (i = 0; i < (1 << len); i++)
        {
            long next = now;
            for (j = 0; j < len; j++)
            {
                if ((i >> j) % 2 == 1)
                {
                    next += qa[j];
                }
            }
            long b = (long)Math.Sqrt(next + 1e-9);
            if (b * b == next)
            {
                //Console.WriteLine(b);
                //Console.WriteLine(next);
                string res = "";
                while (next != 0)
                {
                    res = (next % 2) + res;
                    next /= 2;
                }
                Console.WriteLine(res);
                return;
            }
        }
        
    }

}