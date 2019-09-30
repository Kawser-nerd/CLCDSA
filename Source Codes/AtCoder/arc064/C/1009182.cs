using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Text;
using System.Globalization;

class Myon
{
    static Scanner cin;
    public Myon() { }
    public static int Main()
    {
        //Console.SetOut(new Printer(Console.OpenStandardOutput()));
        cin = new Scanner();
        new Myon().calc();
        return 0;
    }


    public void calc()
    {
        double xs, ys, xt, yt;
        xs = cin.nextDouble();
        ys = cin.nextDouble();
        xt = cin.nextDouble();
        yt = cin.nextDouble();
        double ans = hypot(xs - xt, ys - yt);
        int N = cin.nextInt();
        bool[] used = new bool[N];
        double[] dist = new double[N];
        double[] x = new double[N];
        double[] y = new double[N];
        double[] r = new double[N];
        for (int i = 0; i < N; i++)
        {
            x[i] = cin.nextDouble();
            y[i] = cin.nextDouble();
            r[i] = cin.nextDouble();
        }


        for (int i = 0; i < N; i++)
        {
            dist[i] = hypot(xs - x[i], ys - y[i]) - r[i];
            if (dist[i] < 0) dist[i] = 0;
        }

        for (int i = 0; i < N; i++)
        {
            int best = -1;
            double bestdist = double.MaxValue;
            for (int j = 0; j < N; j++)
            {
                if (!used[j] && bestdist > dist[j])
                {
                    best = j;
                    bestdist = dist[j];
                }
            }
            int start = best;
            for (int j = 0; j < N; j++)
            {
                double add = hypot(x[start] - x[j], y[start] - y[j]) - r[start] - r[j];
                if (add < 0) add = 0;
                dist[j] = Math.Min(dist[j], dist[start] + add);
            }
            used[start] = true;
            ans = Math.Min(ans, dist[start] + Math.Max(0, hypot(xt - x[start], yt - y[start]) - r[start]));
        }
        
        Console.WriteLine("{0:0.0000000000000000}", ans);
    }

    double hypot(double x, double y)
    {
        return Math.Sqrt(x * x + y * y);
    }


}

class Printer : StreamWriter
{
    public override IFormatProvider FormatProvider { get { return CultureInfo.InvariantCulture; } }
    public Printer(Stream stream) : base(stream, new UTF8Encoding(false, true)) { }
    public Printer(Stream stream, Encoding encoding) : base(stream, encoding) { }
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
        while (i >= s.Length)
        {
            string st = Console.ReadLine();
            while (st == "") st = Console.ReadLine();
            s = st.Split(cs, StringSplitOptions.RemoveEmptyEntries);
            i = 0;
        }
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