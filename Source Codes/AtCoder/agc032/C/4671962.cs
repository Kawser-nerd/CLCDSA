using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
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
        if (calc2()) Console.WriteLine("Yes");
        else Console.WriteLine("No");

    }

    List<int>[] es;

    bool calc2()
    {

        cin = new Scanner();
        int N = cin.nextInt();
        int M = cin.nextInt();
        int[] cnt = new int[N];
        es = new List<int>[N];
        for (int i = 0; i < N; i++)
        {
            es[i] = new List<int>();
        }

        for (int i = 0; i < M; i++)
        {
            int a = cin.nextInt() - 1;
            int b = cin.nextInt() - 1;
            cnt[a]++;
            cnt[b]++;

            es[a].Add(b);
            es[b].Add(a);
        }

        for (int i = 0; i < N; i++)
        {
            if (cnt[i] % 2 == 1) return false;
        }

        List<int> L = new List<int>();

        for (int i = 0; i < N; i++)
        {
            if (cnt[i] >= 6) return true;
            if (cnt[i] == 4) L.Add(i);
        }
        
        if (L.Count >= 3) return true;
        if (L.Count < 2) return false;
        

        int start = L[0];
        foreach (var s2 in es[start])
        {
            int pre = start;
            int now = s2;

            while (true)
            {
                bool ok = false;
                foreach (var next in es[now])
                {
                    if (next == pre) continue;
                    if (next == start) return true;
                    if (es[next].Count >= 4) break;

                    pre = now;
                    now = next;
                    ok = true;
                    break;
                }
                if (!ok) break;
            }
        }
        

        return false;
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