using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Text;
using System.Globalization;
using System.Diagnostics;
using System.Threading.Tasks;



class Myon
{
    public Myon() { }
    public static int Main()
    {
        new Myon().calc();
        return 0;
    }
    

    Scanner cin;
    List<int>[] es;
    int[] cnt;
    int[] depth;

    void calc()
    {
        cin = new Scanner();
        int N = cin.nextInt();
        int[] A = new int[N];
        A[0] = -1;
        for (int i = 1; i < N; i++)
        {
            A[i] = cin.nextInt() - 1;
        }
        
        es = new List<int>[N];
        depth = new int[N];
        cnt = new int[N];
        for (int i = 0; i < N; i++)
        {
            es[i] = new List<int>();
        }
        for (int i = 1; i < N; i++)
        {
            es[A[i]].Add(i);
            cnt[A[i]]++;
        }

        Queue<int> q = new Queue<int>();
        for (int i = 0; i < N; i++)
        {
            if (cnt[i] == 0) q.Enqueue(i);
        }

        while (q.Count >= 1)
        {
            int now = q.Dequeue();

            List<int> l = new List<int>();
            foreach (var p in es[now])
            {
                l.Add(depth[p]);
            }
            l.Sort(); l.Reverse();
            int ans = 0;
            for (int i = 0; i < l.Count; i++)
            {
                ans = Math.Max(l[i] + i + 1, ans);
            }
            depth[now] = ans;

            if (now != 0)
            {
                cnt[A[now]]--;
                if(cnt[A[now]] == 0)
                {
                    q.Enqueue(A[now]);
                }
            }
        }
        Console.WriteLine(depth[0]);
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