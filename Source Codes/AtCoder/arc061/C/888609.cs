using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Text;
 
class Myon
{
    public Myon() { }
    public static int Main()
    {
        new Myon().calc();
        return 0;
    }
 
    Scanner cin;
 
    int N, M;
    int[] dist;
    List<Tuple<int, int>>[] es;
    Dictionary<long, int> dic = new Dictionary<long, int>();
    Dictionary<long, List<int>> ees = new Dictionary<long, List<int>>();
    const int MAX = 9999999;
 
    int[] memo;
 
 
    List<int>[] dl;
    int[] ccnt;
    int CMAX = 1000000;
    int[] dlid;
 
    public void calc()
    {
        cin = new Scanner();
        N = cin.nextInt();
        M = cin.nextInt();
        es = new List<Tuple<int, int>>[N];
        for (int i = 0; i < N; i++)
        {
            es[i] = new List<Tuple<int, int>>();
        }
        ccnt = new int[CMAX];
        for (int i = 0; i < M; i++)
        {
            int p = cin.nextInt() - 1;
            int q = cin.nextInt() - 1;
            int c = cin.nextInt() - 1;
            es[p].Add(Tuple.Create(q, c));
            es[q].Add(Tuple.Create(p, c));
 
            if (!ees.ContainsKey(((long)p << 31) + c)) ees[((long)p << 31) + c] = new List<int>();
            if (!ees.ContainsKey(((long)q << 31) + c)) ees[((long)q << 31) + c] = new List<int>();
 
            ees[((long)p << 31) + c].Add(q);
            ees[((long)q << 31) + c].Add(p);
            ccnt[c]++;
        }
 
        dist = new int[N];
        for (int i = 0; i < N; i++)
        {
            dist[i] = MAX;
        }
        dist[0] = 0;
 
        List<int> now = new List<int>();
        now.Add(0);
        int nowdist = 0;
 
        int memocnt = 1;
        memo = new int[N];
 
        dl = new List<int>[CMAX];
        dlid = new int[CMAX];
 
        while (now.Count != 0 && dist[N - 1] == MAX)
        {
            nowdist++;
            List<int> next = new List<int>();
            List<int> clist = new List<int>();
            foreach (int s in now)
            {
                foreach (var p in es[s])
                {
                    int t = p.Item1;
                    int c = p.Item2;
                    if (dist[t] == MAX)
                    {
                        dist[t] = nowdist;
                        next.Add(t);
                    }
 
                    if (dist[t] == nowdist)
                    {
                        long hash = ((long)t << 31) + c;
                        if (!dic.ContainsKey(hash))
                        {
                            dic[hash] = 1;
                            if (dlid[c] != nowdist)
                            {
                                dlid[c] = nowdist;
                                dl[c] = new List<int>();
                                clist.Add(c);
                            }
                            dl[c].Add(t);
                        }
                    }
                }
            }
            if (dist[N - 1] != MAX) break;
 
            foreach (var citem in clist)
            {
                if (dist[N - 1] != MAX) break;
                int comp = citem;
                List<int> list = dl[comp];
                Queue<int> q = new Queue<int>();
                memocnt++;
                foreach (var start in list)
                {
                    q.Enqueue(start);
                    memo[start] = memocnt;
                }
 
                while (q.Count != 0)
                {
                    int s = q.Dequeue();
                    foreach (var p in ees[((long)s << 31) + comp])
                    {
                        int t = p;
                        //int c = p.Item2;
                        //if (c != comp) continue;
 
                        if (dist[t] == MAX)
                        {
                            dist[t] = nowdist;
                            memo[t] = memocnt;
                            next.Add(t);
                            q.Enqueue(t);
                        }
                        else if (dist[t] == nowdist && memo[t] != memocnt)
                        {
                            memo[t] = memocnt;
                            q.Enqueue(t);
                        }
                    }
                }
 
 
            }
            now = next;
        }
        if (dist[N - 1] == MAX) Console.WriteLine(-1);
        else Console.WriteLine(dist[N - 1]);
 
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
        while (i >= s.Length)
        {
            string st = Console.ReadLine();
            while (st == "") st = Console.ReadLine();
            s = st.Split(cs, StringSplitOptions.RemoveEmptyEntries);
            i = 0;
        }
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