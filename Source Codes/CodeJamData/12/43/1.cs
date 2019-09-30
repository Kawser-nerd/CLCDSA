using System;
using System.Collections.Generic;


class Scanner
{
    string[] s;
    int i;

    char[] cs = new char[] { ' ' };

    public Scanner()
    {
        s = new string[0];
        i = 0;
    }

    public string next()
    {
        if (i < s.Length) return s[i++];
        s = Console.ReadLine().Split(cs, StringSplitOptions.RemoveEmptyEntries);
        i = 0;
        return s[i++];
    }

    public double nextDouble()
    {
        return double.Parse(next());
    }

    public int nextInt()
    {
        return int.Parse(next());
    }

    public long nextLong()
    {
        return long.Parse(next());
    }

}


class Myon
{
    Scanner cin;
    Myon() { }

    public static void Main()
    {
        new Myon().multi();
    }

    void multi()
    {
        int c;
        cin = new Scanner();
        int T = cin.nextInt();
        for (c = 1; c <= T; c++)
        {
            Console.Write("Case #{0}: ", c);
            calc();
        }
    }

    void calc()
    {
        int n = cin.nextInt();
        int[] high = new int[n];
        int[] num = new int[n - 1];
        for (int i = 0; i < n - 1; i++)
        {
            num[i] = cin.nextInt() - 1;
        }
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < num[i]; j++)
            {
                if (num[j] > num[i])
                {
                    Console.WriteLine("Impossible");
                    return;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            high[i] = (int)1e9;
        }
        int[] ar = new int[n - 1];
        for (int i = 0; i < n - 1; i++)
        {
            ar[i] = (num[i] - i) * 3000 + i;

        }
        Array.Sort(ar);
        Array.Reverse(ar);
        bool flag = true;
        while (flag)
        {
            flag = false;
            for (int i = 0; i < ar.Length; i++)
            {
                int start = ar[i] % 3000;
                int goal = start + ar[i] / 3000;
                if (goal != n - 1)
                {
                    int tmp = (int)(high[num[start]] - ((high[num[goal]] - high[goal]) / (double)(num[goal] - goal) * (goal - start)) - 0.1);
                    if (high[start] > tmp)
                    {
                        high[start] = tmp;
                        flag = true;
                    }
                }
                for (int j = start + 1; j < goal; j++)
                {
                    int tmp2 = (int)(high[start] + ((high[goal] - high[start]) / (double)(goal - start) * (j - start)) - 0.1);
                    if (high[j] > tmp2)
                    {
                        high[j] = tmp2;
                        flag = true;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            Console.Write(high[i] + " ");
        }
        Console.WriteLine();
    }



}
