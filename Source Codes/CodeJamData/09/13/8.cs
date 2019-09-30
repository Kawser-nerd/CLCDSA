using System;
using System.IO;
class Program
{
    private double[,] C;
    private int maxn = 41;
    private int all;
    private int N;
    private double[] dp;
    void solve()
    {
        StreamReader fin = new StreamReader("input.txt");
        StreamWriter fout = new StreamWriter("C.out");
        C = new double[maxn,maxn];
        for(int i=0;i<maxn;i++)
        {
            C[i, 0] = 1;
            for (int j = 1; j <= i; j++)
                C[i, j] = C[i - 1, j - 1] + C[i - 1, j];
        }

        int testCase = int.Parse(fin.ReadLine());
        for (int test = 1; test <= testCase; test++)
        {
            fout.Write("Case #" + test + ": ");
            string s = fin.ReadLine();
            all = int.Parse(s.Split(' ')[0]);
            N = int.Parse(s.Split(' ')[1]);
            double ret;
            dp=new double[all+1];
            for (int i = 0; i <= all; i++)
                dp[i] = -1;
                if (N >= all)
                    ret = 1;
                else
                {
                    ret = go(all);
                }
            fout.WriteLine(ret);
        }

        fin.Close();
        fout.Close();
    }

    private double go(int need)
    {
        if (dp[need] != -1)
            return dp[need];
        if (need == 0)
            return dp[need] = 0;
        double next = 0;
        double c = 0;
        for(int i=1;i<=need && i<=N;i++)
        {
            double p = (C[need, i]*C[all - need, N - i])/C[all, N];
            next += p*(1.0 + go(need - i));
            c += p;
        }
        double ret = (next + 1 - c)/c;
        return dp[need] = ret;
    }
    static void Main(string[] args)
    {
        Program prog = new Program();
        prog.solve();
    }
}



