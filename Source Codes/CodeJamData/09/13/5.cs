using System;
using System.Collections.Generic;

public class Myon
{
    public Myon() { }
    public static int Main(){
        new Myon().myon();
        return 0;
    }

    bool[,] flag = new bool[11, 10000];

    public void myon()
    {
        int i;
        int m = int.Parse(Console.ReadLine());
        for (int loop=1;loop<=m ;loop++)
        {
            int[] num;
            string[] st = Console.ReadLine().Split(' ');
            num = new int[st.Length];
            for (i = 0; i < st.Length; i++) num[i] = int.Parse(st[i]);
            double res = func(num[0], num[1]);
            Console.WriteLine("Case #{0}: {1}", loop, res);
        }
    }

    public double func(int N, int C)
    {
        double[] res = new double[N + 1];
        int i,j,k;
        res[0] = 0;
        for (i = 1; i <= N; i++)
        {
            double r = 0;
            double[] p = new double[C + 1];
            for (j = 0; j <= C; j++)
            {
                p[j] = 0;
            }
            p[0] = 1;
            for (j = 0; j < C; j++)
            {
                for (k = C-1; k >= 0; k--)
                {
                    double dec = p[k] * (i - k) / (N - j);
                    p[k] -= dec;
                    p[k + 1] += dec;
                }
            }

            for (j = 1; j <= C; j++)
            {
                if (i - j > 0)
                {
                    r += p[j] * (res[i - j]);
                }
            }
            r = r / (1 - p[0]);
            r += 1 / (1 - p[0]);
            res[i] = r;
        }
        return res[N];
    }
}