using System;
using System.Collections.Generic;
using System.Linq;

class Myon
{
    public Myon() { }
    public static void Main()
    {
        new Myon().run2();
    }

    Scanner cin;
    public void run2()
    {
        cin = new Scanner();
        int T = cin.nextInt();
        for (int i = 0; i < T; i++)
        {
            Console.Write("Case #{0}: ", i + 1);
            //Console.WriteLine("Case #{0}:", i + 1);

            run();
        }
    }



    void run()
    {
        int N = cin.nextInt();
        int[] num = new int[N];
        for (int i = 0; i < N; i++)
        {
            num[i] = cin.nextInt();
        }
        bool[] used = new bool[N];
        int ret = 0;
        for (int i = 0; i < N; i++)
        {
            int min = (int)1e9 + 7;
            int pos = -1;
            for (int j = 0; j < N; j++)
            {
                if (!used[j] && min > num[j])
                {
                    min = num[j];
                    pos = j;
                }
            }

            int a = 0;
            for (int j = 0; j < pos; j++)
            {
                if (!used[j]) a++;
            }
            int b = 0;
            for (int j = pos + 1; j < N; j++)
            {
                if (!used[j]) b++;
            }
            used[pos] = true;
            ret += Math.Min(a, b);
        }
        Console.WriteLine(ret);
    }

}

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

    public int nextInt()
    {
        return int.Parse(next());
    }

    public long nextLong()
    {
        return long.Parse(next());
    }

    public double nextDouble()
    {
        return double.Parse(next());
    }

}
