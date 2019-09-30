using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Text;
using System.Globalization;
using System.Diagnostics;



class Myon
{
    public Myon() { }
    public static int Main()
    {
        new Myon().calc();
        return 0;
    }
    

    Scanner cin;


    void calc()
    {
        cin = new Scanner();
        setFact(300000);
        int N = cin.nextInt();
        int[] x = new int[2 * N];
        int[] y = new int[2 * N];
        for (int i = 0; i < 2 * N; i++)
        {
            x[i] = cin.nextInt() - 1;
            y[i] = cin.nextInt() - 1;
        }

        List<int>[] X = new List<int>[N];
        List<int>[] Y = new List<int>[N];
        for (int i = 0; i < N; i++)
        {
            X[i] = new List<int>();
            Y[i] = new List<int>();
        }

        int[] Xcnt = new int[N];
        int[] Ycnt = new int[N];

        for (int i = 0; i < 2 * N; i++)
        {
            X[x[i]].Add(i);
            Y[y[i]].Add(i);
            Xcnt[x[i]]++;
            Ycnt[y[i]]++;
        }
        
        for (int i = 0; i < N; i++)
        {
            if(X[i].Count == 0 || Y[i].Count == 0)
            {
                Console.WriteLine(0); return;
            }
        }

        bool[] checkX = new bool[N];
        bool[] checkY = new bool[N];

        bool[] used = new bool[2 * N];
        long ans = 1;
        long mod = 1000000007;

        int[] color = new int[2 * N];
        List<int>[] es = new List<int>[2 * N];
        List<int>[] esp = new List<int>[2 * N];
        int[] escount = new int[2 * N];
        long[] dp = new long[2 * N];
        int[] dp2 = new int[2 * N];

        int nowSum = 0;
        for (int i = 0; i < x.Length; i++)
        {
            if (used[i]) continue;
            Queue<int> q = new Queue<int>();
            List<int> id = new List<int>();
            id.Add(i);
            q.Enqueue(i);
            used[i] = true;
            int checkXcnt = 0;
            int checkYcnt = 0;

            while (q.Count != 0)
            {
                int now = q.Dequeue();
                if (!checkX[x[now]])
                {
                    checkX[x[now]] = true;
                    checkXcnt++;
                }
                if (!checkY[y[now]])
                {
                    checkY[y[now]] = true;
                    checkYcnt++;
                }
                foreach (var next in X[x[now]])
                {
                    if (used[next]) continue;
                    used[next] = true;
                    q.Enqueue(next);
                    id.Add(next);
                    continue;
                }
                foreach (var next in Y[y[now]])
                {
                    if (used[next]) continue;
                    used[next] = true;
                    q.Enqueue(next);
                    id.Add(next);
                    continue;
                }
            }

            //if(checkXcnt != checkYcnt)
            //{
            //    Console.WriteLine("0"); return;
            //}
            if(checkXcnt + checkYcnt != id.Count)
            {
                Console.WriteLine("0"); return;
            }

            //?????DP?????

            long TempAns = 0;

            for (int turn = 0; turn < 2; turn++)
            {
                foreach (var now in id)
                {
                    Xcnt[x[now]] = X[x[now]].Count;
                    Ycnt[y[now]] = Y[y[now]].Count;
                    color[now] = -1;
                    es[now] = new List<int>();
                    esp[now] = new List<int>();
                    escount[now] = 0;
                    dp[now] = 1;
                    dp2[now] = 0;
                }
                

                q = new Queue<int>();
                foreach (var now in id)
                {
                    if (Xcnt[x[now]] == 1)
                    {
                        color[now] = 0;
                        q.Enqueue(now);
                    }
                    else if(Ycnt[y[now]] == 1)
                    {
                        color[now] = 1;
                        q.Enqueue(now);
                    }
                }
                
                bool flag = false;
                for (int t = 0; t < 2; t++)
                {
                    while (q.Count != 0)
                    {
                        int now = q.Dequeue();
                        Xcnt[x[now]]--;
                        Ycnt[y[now]]--;
                        if (color[now] == 0)
                        {
                            if (Ycnt[y[now]] == 1)
                            {
                                foreach (var next in Y[y[now]])
                                {
                                    if (color[next] == -1)
                                    {
                                        color[next] = 1;
                                        q.Enqueue(next);
                                    }
                                }
                            }

                        }
                        else
                        {
                            if (Xcnt[x[now]] == 1)
                            {
                                foreach (var next in X[x[now]])
                                {
                                    if (color[next] == -1)
                                    {
                                        color[next] = 0;
                                        q.Enqueue(next);
                                    }
                                }
                            }
                        }
                    }
                    if (t == 1) break;
                    foreach (var now in id)
                    {
                        if(color[now] == -1)
                        {
                            flag = true;
                            color[now] = turn;
                            q.Enqueue(now);
                            break;
                        }
                    }
                }
                if (!flag && turn == 1) break;
                
                foreach (var now in id)
                {
                    if(color[now] == 0)
                    {
                        /*
                        int near = -1;
                        int nearID = -1;

                        foreach (var next in X[x[now]])
                        {
                            if(y[now] > y[next] && color[now] == color[next] && y[next] > near)
                            {
                                near = y[next];
                                nearID = next;
                            }
                        }

                        if(nearID != -1)
                        {
                            es[now].Add(nearID);
                            esp[nearID].Add(now);
                            escount[now]++;
                        }
                        
                        foreach (var next in X[x[now]])
                        {
                            if (y[now] > y[next] && color[now] != color[next] && y[next] > near)
                            {
                                es[now].Add(next);
                                esp[next].Add(now);
                                escount[now]++;
                            }
                        }
                        */
                        
                        foreach (var next in X[x[now]])
                        {
                            if (y[now] > y[next])
                            {
                                es[now].Add(next);
                                esp[next].Add(now);
                                escount[now]++;
                            }
                        }
                        
                    }
                    else
                    {
                        /*
                        int near = -1;
                        int nearID = -1;

                        foreach (var next in Y[y[now]])
                        {
                            if (x[now] > x[next] && color[now] == color[next] && x[now] > near)
                            {
                                near = x[next];
                                nearID = next;
                            }
                        }

                        if (nearID != -1)
                        {
                            es[now].Add(nearID);
                            esp[nearID].Add(now);
                            escount[now]++;
                        }

                        foreach (var next in Y[y[now]])
                        {
                            if (x[now] > x[next] && color[now] != color[next] && x[next] > near)
                            {
                                es[now].Add(next);
                                esp[next].Add(now);
                                escount[now]++;
                            }
                        }
                        */

                        
                        foreach (var next in Y[y[now]])
                        {
                            if (x[now] > x[next])
                            {
                                es[now].Add(next);
                                esp[next].Add(now);
                                escount[now]++;
                            }
                        }
                        
                    }
                }

                q = new Queue<int>();
                foreach (var now in id)
                {
                    //Console.WriteLine($"escount[{now}] = {escount[now]} color[{now}] = {color[now]}");
                    if (escount[now] == 0) q.Enqueue(now);
                }

                int nowCnt = 0;
                long Tmp = 1;
                while(q.Count != 0)
                {
                    int now = q.Dequeue();
                    //Console.WriteLine("nowID: " + now);
                    
                    foreach (var next in es[now])
                    {
                        dp[now] *= dp[next];
                        dp[now] %= mod;
                        dp2[now] += dp2[next];
                        dp[now] *= getC(dp2[now], dp2[next]);
                        dp[now] %= mod;
                    }

                    dp2[now]++;
                    if (esp[now].Count == 0)
                    {
                        Tmp *= dp[now];
                        Tmp %= mod;
                        nowCnt += dp2[now];
                        Tmp *= getC(nowCnt, dp2[now]);
                        Tmp %= mod;
                        //Console.WriteLine(Tmp);
                    }
                    else
                    {
                        foreach (var next in esp[now])
                        {
                            escount[next]--;
                            if (escount[next] == 0) q.Enqueue(next);
                        }
                    }
                }
                TempAns += Tmp;
                TempAns %= mod;
                //Console.WriteLine(id.Count + " " + nowCnt + " " + Tmp);
            }
            ans *= TempAns;
            ans %= mod;
            nowSum += id.Count;
            ans *= getC(nowSum, id.Count);
            ans %= mod;
            //Console.WriteLine(ans);
        }
        Console.WriteLine(ans);

    }

    long mod = 1000000007;
    long powmod(long a, long p)
    {
        long ans = 1;
        long mul = a;
        for (; p > 0; p >>= 1, mul = (mul * mul) % mod)
        {
            if ((p & 1) == 1) ans = (ans * mul) % mod;
        }
        return ans;
    }


    long[] fact; //??
    long[] revFact; //?????
    void setFact(int N)
    {
        fact = new long[N];
        revFact = new long[N];
        fact[0] = 1;
        for (int i = 1; i < N; i++)
        {
            fact[i] = fact[i - 1] * i;
            fact[i] %= mod;
        }
        revFact[N - 1] = powmod(fact[N - 1], mod - 2);
        for (int i = N - 2; i >= 0; i--)
        {
            revFact[i] = revFact[i + 1] * (i + 1);
            revFact[i] %= mod;
        }
    }


    long getC(int a, int b)
    {
        return (((fact[a] * revFact[b]) % mod) * revFact[a - b]) % mod;
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
        if (s.Length == 0) return next();
        i = 0;
        return s[i++];
    }

    public int nextInt()
    {
        return int.Parse(next());
    }
    public int[] ArrayInt(int N, int add = 0)
    {
        int[] Array = new int[N];
        for (int i = 0; i < N; i++)
        {
            Array[i] = nextInt() + add;
        }
        return Array;
    }

    public long nextLong()
    {
        return long.Parse(next());
    }

    public long[] ArrayLong(int N, long add = 0)
    {
        long[] Array = new long[N];
        for (int i = 0; i < N; i++)
        {
            Array[i] = nextLong() + add;
        }
        return Array;
    }

    public double nextDouble()
    {
        return double.Parse(next());
    }


    public double[] ArrayDouble(int N, double add = 0)
    {
        double[] Array = new double[N];
        for (int i = 0; i < N; i++)
        {
            Array[i] = nextDouble() + add;
        }
        return Array;
    }
}