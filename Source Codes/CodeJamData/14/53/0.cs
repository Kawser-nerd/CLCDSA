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
        string[] s = new string[N];
        int[] id = new int[N];

        Dictionary<int, int> dic = new Dictionary<int, int>();
        for (int i = 0; i < N; i++)
        {
            s[i] = cin.next();
            id[i] = cin.nextInt();
            if (id[i] == 0) id[i] = -1;
            else
            {
                if (!dic.ContainsKey(id[i])) dic[id[i]] = dic.Count;
                id[i] = dic[id[i]];
            }
        }

        int MAX = (1 << N);
        bool[] dp = new bool[MAX];
        for (int i = 0; i < MAX; i++)
        {
            dp[i] = true;
        }


        for (int i = 0; i < N; i++)
        {


            bool[] nextdp = new bool[MAX];
            if (s[i] == "E")
            {
                for (int j = 0; j < MAX; j++)
                {
                    if (!dp[j]) continue;
                    if (id[i] == -1)
                    {
                        for (int k = 0; k < N; k++)
                        {
                            if ((j >> k) % 2 == 1) continue;
                            nextdp[j + (1 << k)] = true;
                        }
                    }
                    else
                    {
                        int k = id[i];
                        if ((j >> k) % 2 == 1) continue;
                        nextdp[j + (1 << k)] = true;
                    }
                }
            }
            else
            {
                for (int j = 0; j < MAX; j++)
                {
                    if (!dp[j]) continue;
                    if (id[i] == -1)
                    {
                        for (int k = 0; k < N; k++)
                        {
                            if ((j >> k) % 2 == 0) continue;
                            nextdp[j - (1 << k)] = true;
                        }
                    }
                    else
                    {
                        int k = id[i];
                        if ((j >> k) % 2 == 0) continue;
                        nextdp[j - (1 << k)] = true;
                    }
                }
            }
            dp = nextdp;

        }
        int ret = 9999;
        for (int i = 0; i < MAX; i++)
        {
            if (dp[i])
            {
                ret = Math.Min(ret, bitCount(i));
            }
        }
        if (ret == 9999) Console.WriteLine("CRIME TIME");
        else Console.WriteLine(ret);
    }

    int bitCount(long x)
    {
        x = (x & 0x5555555555555555) + (x >> 1 & 0x5555555555555555);
        x = (x & 0x3333333333333333) + (x >> 2 & 0x3333333333333333);
        x = (x & 0x0f0f0f0f0f0f0f0f) + (x >> 4 & 0x0f0f0f0f0f0f0f0f);
        x = (x & 0x00ff00ff00ff00ff) + (x >> 8 & 0x00ff00ff00ff00ff);
        x = (x & 0x0000ffff0000ffff) + (x >> 16 & 0x0000ffff0000ffff);
        return (int)((x & 0x00000000ffffffff) + (x >> 32 & 0x00000000ffffffff));
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
