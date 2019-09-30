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
    Random rnd;
    Myon() { }

    public static void Main()
    {
        new Myon().multi();
    }

    void multi()
    {
        cin = new Scanner();
        rnd = new Random();
        int T = cin.nextInt();
        for (int c = 1; c <= T; c++)
        {
            Console.Write("Case #{0}: ", c);
            calc();
        }
    }

    void calc()
    {
        int n = cin.nextInt();
        int[] x = new int[n + 1];
        int[] y = new int[n + 1];
        int[] m = new int[n + 1];
        long[] ar = new long[n + 1];
        ar[0] = toLong(1000, 1000, 0);
        for (int i = 0; i < n; i++)
        {
            ar[i + 1] = toLong(cin.nextInt() + 1000, cin.nextInt() + 1000, cin.nextInt());

        }
        Array.Sort(ar, 1, n);
        n++;
        for (int i = 0; i < n; i++)
        {
            x[i] = (int)(ar[i] % 3000); ar[i] /= 3000;
            y[i] = (int)(ar[i] % 3000); ar[i] /= 3000;
            m[i] = (int)(ar[i]);
            //Console.WriteLine("test {0} {1} {2}",x[i], y[i],m[i]);
        }
        int ret = 0;
        int[] time = new int[n];
        int MAX = int.MaxValue;
        for (int i = 0; i < n; i++)
		{
            time[i] = MAX;
        }
        time[0] = 0;
        for (int k = 0; k < n; k++)
        {
            int[] ntimes = new int[n];
            for (int i = 0; i < n; i++)
            {
                ntimes[i] = MAX;
            }
            for (int i = 1; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (i == j) continue;
                    if (time[j] == MAX) continue;
                    int zombitime = 750;
                    if (j == 0) zombitime = 0;
                    int nexttime = time[j] + Math.Max(zombitime, Math.Max(Math.Abs(x[i] - x[j]), Math.Abs(y[i] - y[j])) * 100);
                    if (nexttime <= m[i] + 1000)
                    {
                        nexttime = Math.Max(nexttime, m[i]);
                        ntimes[i] = Math.Min(nexttime, ntimes[i]);
                        ret = k + 1;
                    }
                }
            }
            time = ntimes;
        }
        Console.WriteLine(ret);

    }

    long toLong(int x, int y, int m)
    {
        long ret = m;
        ret *= 3000;
        ret += x;
        ret *= 3000;
        ret += y;
        return ret;
    }
}
