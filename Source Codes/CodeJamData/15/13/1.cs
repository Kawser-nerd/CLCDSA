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
        
        init();
        cin = new Scanner();
        int T = cin.nextInt();
        int[] N = new int[T];
        long[][] x = new long[T][];
        long[][] y = new long[T][];
        int[][] ret = new int[T][];
        for (int i = 0; i < T; i++)
        {
            N[i] = cin.nextInt();
            //N[i] = 3000;
            x[i] = new long[N[i]];
            y[i] = new long[N[i]];
            for (int j = 0; j < N[i]; j++)
            {
                x[i][j] = cin.nextInt();
                y[i][j] = cin.nextInt();
                //x[i][j] = r.nextInt(-1000000, 1000000);
                //y[i][j] = r.nextInt(-1000000, 1000000);
                
            }
        }


        Parallel.For(0, T, i =>
            {
                ret[i] = new Nyan().run(N[i], x[i], y[i]);
            }
            );
        
        for (int i = 0; i < T; i++)
        {
            Console.WriteLine("Case #{0}: ", i + 1);
            for (int j = 0; j < ret[i].Length; j++)
            {
                Console.WriteLine(ret[i][j]);
            }
        }
    }


    void init()
    {
        
    }


    class Nyan
    {
        public Nyan() { }

        int N;
        long[] x, y;
        public int[] run(int N, long[] x, long[] y)
        {
            this.N = N;
            this.x = x;
            this.y = y;

            int[] ret = new int[N];
            for (int i = 0; i < N; i++)
            {
                ret[i] = Math.Max(0, N - 3);
            }
            for (int i = 0; i < N; i++)
            {
                double[] p = new double[N - 1];
                int count = 0;
                for (int j = 0; j < N; j++)
                {
                    if (i == j) continue;
                    p[count++] = Math.Atan2(y[i] - y[j], x[i] - x[j]);
                }
                Array.Sort(p);

                int k = 1;
                double pre = 100;
                for (int j = 0; j < N - 1; j++)
                {
                    k--;
                    while (pre != p[j] && k < N - 1)
                    {
                        double dp = p[(k + j) % (N - 1)] - p[j];
                        while (dp < 0) dp += 2 * Math.PI;
                        if (dp > Math.PI - 1e-12) break;
                        k++;
                    }
                    ret[i] = Math.Min(ret[i], k - 1);
                    pre = p[j];
                }
            }
            return ret;
        }


        long calc(int a, int b, int c)
        {
            return calc(x[a] - x[b], x[a] - x[c], y[a] - y[b], y[a] - y[c]);
        }

        long calc(long x1, long x2, long y1, long y2)
        {
            return (x1 * y2) - (x2 * y1);
        }
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
