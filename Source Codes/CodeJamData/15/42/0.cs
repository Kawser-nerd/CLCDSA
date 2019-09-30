using System;
using System.Collections.Generic;
using System.Linq;

using System.Threading;
using System.Threading.Tasks;


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
        XRand r = new XRand();

        cin = new Scanner();
        int T = cin.nextInt();
        init();
        
        for (int i = 1; i <= T; i++)
        {
            Console.Write("Case #{0}: ", i);
            calc();
        }
    }


    void init()
    {
        
    }


    double eps = 1e-14;

    Tuple<double, double>[] p;

    void calc()
    {
        int N = cin.nextInt();
        double V = cin.nextDouble(); 
        double T = cin.nextDouble();
        p = new Tuple<double, double>[N];
        for (int i = 0; i < N; i++)
        {
            double v = cin.nextDouble();
            double t = cin.nextDouble();
            p[i] = Tuple.Create(t, v);
        }
        Array.Sort(p);

        double mintime = 0;
        double maxtime = 1e15;
        for (int i = 0; i < 300; i++)
        {
            double time = (mintime + maxtime) / 2;
            if (ok(V, time, T)) maxtime = time;
            else mintime = time;
        }


        if (maxtime == 1e15) Console.WriteLine("IMPOSSIBLE");
        else Console.WriteLine("{0:0.0000000000000000}", mintime);

    }

    bool ok(double V, double Time, double T)
    {
        double mi = minTemp(V, Time);
        double ma = maxTemp(V, Time);
        //Console.WriteLine("{0:0.000000000000} {1:0.000000000000} {2:0.000000000000} {3:0.000000000000} ", mi, ma, Time, T);
        if (mi - eps > T) return false;
        if (ma + eps < T) return false;
        return true;
    }

    double minTemp(double V, double Time)
    {
        int N = p.Length;
        double sum = 0;
        double Vsum = 0;
        for (int i = 0; i < N; i++)
        {
            if (V <= 0) break;
            double add = Math.Min(V, Time * p[i].Item2);
            double t = add / p[i].Item2;
            V -= add;
            Vsum += add;
            sum += add * p[i].Item1;
        }
        if (V > eps) return 1e30;
        else return sum / Vsum;
    }

    double maxTemp(double V, double Time)
    {
        int N = p.Length;
        double sum = 0;
        double Vsum = 0;
        for (int i = N - 1; i >= 0; i--)
        {
            if (V <= 0) break;
            double add = Math.Min(V, Time * p[i].Item2);
            double t = add / p[i].Item2;
            V -= add;
            Vsum += add;
            sum += add * p[i].Item1;
        }
        if (V > eps) return -1e30;
        else return sum / Vsum;
    }



}

class XRand
{
    uint x, y, z, w;


    public XRand()
    {
        init();
    }

    public XRand(uint s)
    {
        init();
        init_xor128(s);
    }

    void init()
    {
        x = 314159265; y = 358979323; z = 846264338; w = 327950288;

    }

    public void init_xor128(uint s)
    {
        z ^= s;
        z ^= z >> 21; z ^= z << 35; z ^= z >> 4;
        z *= 736338717;
    }

    uint next()
    {
        uint t = x ^ x << 11; x = y; y = z; z = w; return w = w ^ w >> 19 ^ t ^ t >> 8;
    }

    public long nextLong(long m)
    {
        return (long)((((ulong)next() << 32) + next()) % (ulong)m);
    }

    public int nextInt(int m)
    {
        return (int)(next() % m);
    }

    public int nextIntP(int a)
    {
        return (int)Math.Pow(a, nextDouble());
    }

    public int nextInt(int min, int max)
    {
        return min + nextInt(max - min + 1);
    }


    public double nextDouble()
    {
        return (double)next() / uint.MaxValue;
    }

    public double nextDoubleP(double a)
    {
        return Math.Pow(a, nextDouble());
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
