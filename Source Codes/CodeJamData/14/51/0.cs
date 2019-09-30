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
        int p = cin.nextInt();
        int q = cin.nextInt();
        int r = cin.nextInt();
        int s = cin.nextInt();

        long[] a = new long[N];
        long sum = 0;
        for (int i = 0; i < N; i++)
        {
            a[i] = ((long)i * p + q) % r + s;
            sum += a[i];
        }

        long min = Math.Max(sum / 3 - 1, 0);
        long max = sum;
        while (max - min > 1)
        {
            long mid = (max + min) / 2;
            long count = 0;
            long now = 0;
            for (int i = 0; i < N && count < 3; i++)
            {
                if (now + a[i] > mid) { count++; now = 0; }
                now += a[i];
                if (now > mid) count = 3;
            }

            if (count >= 3) min = mid;
            else max = mid;
        }

        Console.WriteLine("{0:0.000000000000000}", 1.0 - (double)max / sum);
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
