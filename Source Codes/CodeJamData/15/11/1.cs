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
        init();
        cin = new Scanner();
        int T = cin.nextInt();
        for (int i = 0; i < T; i++)
        {
            Console.Write("Case #{0}: ", i + 1);

            run();
        }
    }


    void init()
    {

    }


    void run()
    {
        int ret1 = 0;
        int ret2 = 0;
        int N = cin.nextInt();
        int[] x = new int[N];
        for (int i = 0; i < N; i++)
        {
            x[i] = cin.nextInt();
        }

        int mineat = 0;
        for (int i = 0; i < N - 1; i++)
        {
            if (x[i] > x[i + 1])
            {
                ret1 += x[i] - x[i + 1];
                mineat = Math.Max(mineat, x[i] - x[i + 1]);
            }
        }

        for (int i = 0; i < N-1; i++)
        {
            int eat = Math.Min(mineat, x[i]);
            ret2 += eat;
        }
        Console.WriteLine("{0} {1}", ret1, ret2);
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
        string st = Console.ReadLine();
        while (st == "") st = Console.ReadLine();
        s = st.Split(cs, StringSplitOptions.RemoveEmptyEntries);
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
