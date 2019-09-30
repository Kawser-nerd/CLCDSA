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
    int[] m;
    int[] t;

    List<int>[] l;

    int[,] dist;

    void run()
    {
        N = cin.nextInt();
        m = new int[N];
        for (int i = 0; i < N; i++)
        {
            m[i] = cin.nextInt();
        }
        l = new List<int>[N];
        for (int i = 0; i < N; i++)
        {
            l[i] = new List<int>();
        }

        dist = new int[N, N];
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                dist[i, j] = 99999999;
            }
            dist[i, i] = 0;
        }

        t = new int[N - 1];
        for (int i = 0; i < N - 1; i++)
        {
            t[i] = cin.nextInt() - 1;
            l[i].Add(t[i]);
            l[t[i]].Add(i);
            dist[i, t[i]] = 1;
            dist[t[i], i] = 1;
        }

        for (int k = 0; k < N; k++)
        {
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    dist[i, j] = Math.Min(dist[i, j], dist[i, k] + dist[k, j]);
                }
            }
        }

        int ret = -99999999;
        for (int i = 0; i < N; i++)
        {
            int tempret = 99999999;
            for (int j = 0; j < N; j++)
            {
                usedmoney = new bool[N];
                useroad = new bool[N, N];
                sa = i;
                sb = j;
                int rett = dfsa(i, j);
                tempret = Math.Min(tempret, rett);
            }
            ret = Math.Max(ret, tempret);
        }
        Console.WriteLine(ret);
    }

    int sa, sb;

    bool[] usedmoney;
    bool[,] useroad;

    int dfsa(int citya, int cityb)
    {
        //Console.WriteLine("cityb : " + cityb);
        int add = 0;
        bool moneyflag = false;
        if (!usedmoney[citya])
        {
            add = m[citya];
            usedmoney[citya] = moneyflag = true;
        }

        bool check = false;

        int tempret = -99999999;
        foreach (var item in l[citya])
        {
            if (!useroad[citya, item])
            {
                check = true;
                useroad[citya,item] = useroad[item,citya] = true;
                tempret = Math.Max(tempret, -dfsb(item, cityb));
                useroad[citya,item] = useroad[item,citya] = false;
            }
        }


        int ret = add;
        if (tempret == -99999999)
        {
            if (!usedmoney[cityb])
            {
                ret -= dfsb(citya, cityb);
            }
            else
            {
                bool check2 = false;
                foreach (var item in l[cityb])
                {
                    if (!useroad[cityb, item])
                    {
                        check2 = true;
                        break;
                    }
                }
                if (check2)
                {
                    ret -= dfsb(citya, cityb);
                }
                else
                {
                    ;
                }
            }
        }
        else
        {
            ret += tempret;
        }


        if (moneyflag) usedmoney[citya] = false;

        return ret;
    }

    int dfsb(int citya, int cityb)
    {
        int add = 0;
        bool moneyflag = false;
        if (!usedmoney[cityb])
        {
            add = m[cityb];
            usedmoney[cityb] = moneyflag = true;
        }
        //Console.WriteLine("test " + cityb + " " + add);

        bool check = false;

        int tempret = -99999999;
        foreach (var item in l[cityb])
        {
            if (!useroad[cityb, item])
            {
                check = true;
                useroad[cityb, item] = useroad[item, cityb] = true;
                tempret = Math.Max(tempret, -dfsa(citya, item));
                useroad[cityb, item] = useroad[item, cityb] = false;
            }
        }


        int ret = add;
        if (tempret == -99999999)
        {
            if (!usedmoney[citya])
            {
                ret -= dfsa(citya, cityb);
            }
            else
            {
                bool check2 = false;
                foreach (var item in l[citya])
                {
                    if (!useroad[citya, item])
                    {
                        check2 = true;
                        break;
                    }
                }
                if (check2)
                {
                    ret -= dfsa(citya, cityb);
                }
                else
                {
                    ;
                }
            }
        }
        else
        {
            ret += tempret;
        }

        if (moneyflag) usedmoney[cityb] = false;

        return ret;
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
