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


    List<int>[] to;

    void run()
    {
        N = cin.nextInt();
        M = cin.nextInt();
        int[] id = new int[N];
        for (int i = 0; i < N; i++)
        {
            id[i] = cin.nextInt();
        }

        to = new List<int>[N];
        for (int i = 0; i < N; i++)
        {
            to[i] = new List<int>();
        }

        for (int i = 0; i < M; i++)
        {
            int a = cin.nextInt() - 1;
            int b = cin.nextInt() - 1;
            to[a].Add(b);
            to[b].Add(a);
        }

        string ret = "";

        int[] sortid = new int[N];
        for (int i = 0; i < N; i++)
        {
            sortid[i] = id[i] * 100 + i;
        }
        Array.Sort(sortid);

        stock = new int[N];
        ng = new bool[N];

        for (int i = 0; i < N; i++)
        {
            int first = sortid[i] % 100;
            stock[0] = first;
            stocknum = 1;
            ng[first] = true;

            if (ok())
            {
                ret += id[first];

                while (true)
                {
                    int nowstock = stocknum;

                    int bestnextpos = 0;
                    int bestnextroute = 100000;
                    int bestnextstock = 0;

                    for (stocknum = nowstock; stocknum > 0; stocknum--)
                    {
                        if (!ok()) break;
                        foreach (var next in to[stock[stocknum - 1]])
                        {
                            if (ng[next]) continue;
                            if (id[next] < bestnextroute)
                            {
                                bestnextpos = next;
                                bestnextroute = id[next];
                                bestnextstock = stocknum;
                            }
                        }
                    }
                    if (bestnextroute == 100000) break;

                    stocknum = bestnextstock;
                    stock[stocknum] = bestnextpos;
                    ng[bestnextpos] = true;
                    ret += bestnextroute;
                    stocknum++;
                }
                break;

            }
            ng[first] = false;
        }
        Console.WriteLine(ret);
    }

    int N, M;
    
    int[] stock;
    int stocknum;

    bool[] ng;

    bool ok()
    {
        bool[] check = new bool[N];
        for (int i = 0; i < stocknum; i++)
        {
            Queue<int> q = new Queue<int>();
            q.Enqueue(stock[i]);
            while (q.Count != 0)
            {
                int now = q.Dequeue();
                check[now] = true;
                foreach (var next in to[now])
                {
                    if (ng[next]) continue;
                    if (check[next]) continue;
                    check[next] = true;
                    q.Enqueue(next);
                }
            }
        }

        for (int i = 0; i < N; i++)
        {
            if (!check[i] && !ng[i]) return false;
        }
        return true;
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
