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


    int N;
    int[] need, get, miss;
    int[] hp, money;
    void run()
    {
        int P = cin.nextInt();
        int Q = cin.nextInt();
        N = cin.nextInt();
        hp = new int[N];
        money = new int[N];

        for (int i = 0; i < N; i++)
        {
            hp[i] = cin.nextInt();
            money[i] = cin.nextInt();
        }

        need = new int[N];
        get = new int[N];
        miss = new int[N];
        for (int i = 0; i < N; i++)
        {
            miss[i] = (hp[i] + Q - 1) / Q;
            int now = hp[i];

            while ((now % Q > P || now % Q == 0) && now > P && Q > P)
            {
                now -= P;
                need[i]++;
            }

            if (now > 0)
            {
                get[i] = (now - 1) / Q;
                need[i]++;
            }
            //Console.WriteLine(get[i] + " " + need[i] + " " + miss[i]);
        }

        dp = new long[N, 3001];
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < 3001; j++)
            {
                dp[i, j] = -1;
            }
        }

        Console.WriteLine(dfs(0, 1));
    }

    long[,] dp;

    long dfs(int p, int nokori)
    {
        if (p == N) return 0;
        if (nokori >= 3001) nokori = 3000;
        if (dp[p, nokori] != -1) return dp[p, nokori];
        long ret = 0;

        if (nokori - need[p] + get[p] >= 0)
        {
            ret = money[p] + dfs(p + 1, nokori - need[p] + get[p]);
        }
        ret = Math.Max(ret, dfs(p + 1, nokori + miss[p]));

        //Console.WriteLine(p + " " + nokori + " " + ret);

        return dp[p, nokori] = ret;
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
