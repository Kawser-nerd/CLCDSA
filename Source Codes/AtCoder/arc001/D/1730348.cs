using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Text;
using System.Globalization;
using System.Diagnostics;
using static System.Console;
//using System.Numerics;
//using static System.Math;
using pair = Pair<int, int>;

class Program
{
    static void Main()
    {
        //SetOut(new StreamWriter(OpenStandardOutput()) { AutoFlush = false });
        new Program().solve();
        Out.Flush();
    }
    Scanner cin = new Scanner();
    readonly int[] dd = { 0, 1, 0, -1, 0 }; //????
    readonly int mod = 1000000007;

    const int N = 8;
    bool ok = false;
    void solve()
    {
        var H = new char[N][];
        for (int i = 0; i < N; i++)
        {
            H[i] = cin.next.ToCharArray();
        }
        var G = new List<int>();
        var A = new bool[N];

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (H[i][j] == 'Q')
                {
                    A[i] = true;
                    if (!check(i, j, H))
                    {
                        WriteLine("No Answer");
                        return;
                    }
                }

            }
        }


        for (int i = 0; i < N; i++)
        {
            if (!A[i]) G.Add(i);
        }
        var Q = new List<pair>();
        dfs(0, Q, H, G);
        if (ok) return;
        WriteLine("No Answer");
    }
    bool check(int a, int b, char[][] H)
    {

        for (int i = 0; i < N; i++)
        {
            if (i == b) continue;
            if (H[a][i] == 'Q') return false;

        }

        for (int i = 0; i < N; i++)
        {
            if (i == a) continue;
            if (H[i][b] == 'Q') return false;

        }
        int min = Math.Min(a, b);
        for (int i = 0; i < N; i++)
        {
            int y = a - min + i;
            int x = b - min + i;
            if (y >= N || x >= N) break;
            if (y == a && x == b) continue;
            if (H[y][x] == 'Q') return false;

        }
        min = Math.Min(a, 7 - b);
        for (int i = 0; i < N; i++)
        {
            int y = a - min + i;
            int x = b + min - i;
            if (y < 0 || y >= N || x < 0 || x >= N) continue;
            if (y == a && x == b) continue;
            if (H[y][x] == 'Q') return false;

        }
        return true;
    }
    void dfs(int k, List<pair> L, char[][] H, List<int> A)
    {
        if (ok) return;
        if (k == 5)
        {
            var P = new char[N][];
            for (int i = 0; i < N; i++)
            {
                P[i] = new char[N];
                Array.Copy(H[i], P[i], N);
            }

            for (int i = 0; i < 5; i++)
            {
                int y = L[i].f;
                int x = L[i].s;
                P[y][x] = 'Q';
                if (!check(y, x, P)) return;
            }
            foreach (var item in P)
            {
                WriteLine(new string(item));
            }
            ok = true;
            return;
        }
        for (int i = 0; i < N; i++)
        {
            L.Add(new pair(A[k], i));
            dfs(k + 1, L, H, A);
            L.RemoveAt(k);
        }

    }


}

class Pair<T, U> : IComparable<Pair<T, U>> where T : IComparable<T> where U : IComparable<U>
{
    public T f;
    public U s;
    public Pair(T f, U s)
    {
        this.f = f;
        this.s = s;
    }
    public int CompareTo(Pair<T, U> a)
    {
        return f.CompareTo(a.f) != 0 ? f.CompareTo(a.f) : s.CompareTo(a.s);
    }
    public override string ToString()
    {
        return f + " " + s;
    }
}
class Scanner
{
    string[] s; int i;
    char[] cs = new char[] { ' ' };
    public Scanner() { s = new string[0]; i = 0; }
    public string[] scan { get { return ReadLine().Split(); } }
    public int[] scanint { get { return Array.ConvertAll(scan, int.Parse); } }
    public long[] scanlong { get { return Array.ConvertAll(scan, long.Parse); } }
    public double[] scandouble { get { return Array.ConvertAll(scan, double.Parse); } }
    public string next
    {
        get
        {
            if (i < s.Length) return s[i++];
            string st = ReadLine();
            while (st == "") st = ReadLine();
            s = st.Split(cs, StringSplitOptions.RemoveEmptyEntries);
            i = 0;
            return next;
        }
    }
    public int nextint { get { return int.Parse(next); } }
    public long nextlong { get { return long.Parse(next); } }
    public double nextdouble { get { return double.Parse(next); } }
}