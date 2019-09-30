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
        int A = cin.nextInt() - 1;
        int B = cin.nextInt() - 1;
        int K = cin.nextInt() - 1;

        int MAX = 40;
        int[] a = new int[MAX];
        int[] b = new int[MAX];
        int[] kk = new int[MAX];
        for (int i = 0; i < MAX; i++)
        {
            a[i] = A % 2; A /= 2;
            b[i] = B % 2; B /= 2;
            kk[i] = K % 2; K /= 2;
        }

        long[,,] dp = new long[2, 2, 2];
        dp[1,1,1] = 1;
        for (int t = MAX - 1; t >= 0; t--)
        {
            long[, ,] nextdp = new long[2, 2, 2];
            for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j < 2; j++)
                {
                    for (int k = 0; k < 2; k++)
                    {
                        int maxi = 1;
                        if (a[t] == 1) maxi = 2;
                        if (i == 0) maxi = 2;

                        int maxj = 1;
                        if (b[t] == 1) maxj = 2;
                        if (j == 0) maxj = 2;

                        for (int pi = 0; pi < maxi; pi++)
                        {
                            for (int pj = 0; pj < maxj; pj++)
                            {
                                int pk = pi & pj;
                                if (pk == 1 && kk[t] == 0 && k == 1) continue;

                                int ni = i;
                                if (pi == 0 && a[t] == 1) ni = 0;

                                int nj = j;
                                if (pj == 0 && b[t] == 1) nj = 0;

                                int nk = k;
                                if (pk == 0 && kk[t] == 1) nk = 0;

                                nextdp[ni, nj, nk] += dp[i, j, k];
                            }
                        }

                    }
                }
            }
            dp = nextdp;
        }

        long ret = 0;
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                for (int k = 0; k < 2; k++)
                {
                    ret += dp[i, j, k];
                }
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
