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
        int i, j;
        int[] ar = inputarray();
        int n = ar[0];
        int MAX = 10005;
        if (n == 0)
        {
            Console.WriteLine(0);
            return;
        }
        int res = 99999;
        int[] num = new int[MAX];
        for (i = 1; i < ar.Length; i++)
        {
            num[ar[i]]++;
        }
        List<int> now = new List<int>();
        for (i = 0; i < MAX; i++)
        {
            List<int> next = new List<int>();
            for (j = 0; j < num[i] - now.Count; j++) next.Add(1);
            int count = 0;
            foreach (int a in now)
            {
                if (count < num[i])
                {
                    next.Add(a + 1);
                    count++;
                }
                else
                {
                    res = Math.Min(res, a);
                }
            }
            now = next;
        }
        Console.WriteLine(res);
    }
}