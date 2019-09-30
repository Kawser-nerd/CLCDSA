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
        int X = cin.nextInt();
        int[] num = new int[N];
        for (int i = 0; i < N; i++)
        {
            num[i] = cin.nextInt();
        }
        Array.Sort(num);

        bool[] used = new bool[N];
        int ret = 0;

        int j = 0;
        for (int i = N - 1; i >= 0; i--)
        {
            if (used[i]) continue;
            if (num[i] + num[j] <= X)
            {
                used[i] = true;
                used[j] = true;
                j++;
                ret++;
            }
            else
            {
                used[i] = true;
                ret++;
            }
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
