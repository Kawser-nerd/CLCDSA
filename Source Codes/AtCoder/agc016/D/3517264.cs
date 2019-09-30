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


    void calc()
    {
        cin = new Scanner();
        int N = cin.nextInt();
        int[] A = cin.ArrayInt(N);
        int[] B = cin.ArrayInt(N);

        int[] a = new int[N + 1];
        int[] b = new int[N + 1];
        int xa = 0, xb = 0;
        for (int i = 0; i < N; i++)
        {
            xa ^= A[i]; xb ^= B[i];
        }
        a[N] = xa; b[N] = xb;

        List<int> la = new List<int>(A);
        List<int> lb = new List<int>(B);
        la.Add(xa);
        lb.Add(xb);
        la.Sort(); lb.Sort();
        for (int i = 0; i < la.Count; i++)
        {
            if (la[i] != lb[i])
            {
                Console.WriteLine("-1");
                return;
            }
        }


        int nokori = 0;
        bool[] ok = new bool[N];
        Dictionary<int, List<int>> need = new Dictionary<int, List<int>>();
        for (int i = 0; i < N; i++)
        {
            if (A[i] == B[i])
            {
                ok[i] = true;
                continue;
            }
            if (!need.ContainsKey(B[i])) need[B[i]] = new List<int>();
            need[B[i]].Add(i);
            nokori++;
        }

        if (nokori == 0)
        {
            Console.WriteLine(0); return;
        }
        Dictionary<int, int> dic = new Dictionary<int, int>();
        for (int i = 0; i < N; i++)
        {
            if (ok[i]) continue;
            if (!dic.ContainsKey(A[i])) dic[A[i]] = dic.Count;
            if (!dic.ContainsKey(B[i])) dic[B[i]] = dic.Count;
        }
        init(dic.Count);
        for (int i = 0; i < N; i++)
        {
            if (ok[i]) continue;
            connect(dic[A[i]], dic[B[i]]);
        }
        int rootCnt = 0;
        for (int i = 0; i < dic.Count; i++)
        {
            if (root(i) == i) rootCnt++;
        }

        int ans = nokori + rootCnt;
        if (xa != xb || (need.ContainsKey(xa) && need[xa].Count >= 1)) ans--;

        Console.WriteLine(ans);

        //0 1 0
        //1 0 0

        //0 0 0 1 2 3 0
        //0 0 0 0 2 3 1
        //1 0 0 0 2 3 0
        //1 0 0 0 0 3 2
        //1 2 0 0 0 3 0
        //1 2 0 0 0 0 3
        //1 2 3 0 0 0 0

        //1 2 3 0 0 0 0


        //0 0 1 2 3 0
        //0 0 0 2 3 1
        //1 0 0 2 3 0
        //1 0 0 0 3 2
        //1 2 0 0 3 0
        //1 2 0 0 0 3

        //1 2 0 0 0 3


        //0 0 1 2 3 0
        //0 0 1 2 0 3
        //0 0 3 2 0 1
        //1 0 3 2 0 0
        //1 0 3 0 0 2
        //1 2 3 0 0 0

        //1 2 3 0 0 0
    }

    int[] uni;
    void init(int N)
    {
        uni = new int[N];
        for (int i = 0; i < N; i++)
        {
            uni[i] = -1;
        }
    }

    int root(int a)
    {
        if (uni[a] < 0) return a;
        else return uni[a] = root(uni[a]);
    }

    bool connect(int a, int b)
    {
        a = root(a);
        b = root(b);
        if (a == b) return false;
        if (uni[a] > uni[b]) swap(ref a, ref b);
        uni[a] += uni[b];
        uni[b] = a;
        return true;
    }

    void swap<T>(ref T a, ref T b)
    {
        T c = a;
        a = b;
        b = c;
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