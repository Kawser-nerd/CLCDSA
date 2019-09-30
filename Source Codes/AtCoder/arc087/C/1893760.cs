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


    void solve()
    {
        int N = cin.nextint;
        var L = cin.nextlong;

        var V = new List<Node>();
        V.Add(new Node(0));

        for (int i = 0; i < N; i++)
        {
            int now = 0;
            var S = ReadLine();
            for (int j = 0; j < S.Length; j++)
            {
                if (S[j] == '0')
                {
                    if (V[now].left == -1)
                    {
                        V[now].left = V.Count;
                        V.Add(new Node(j + 1));
                        now = V[now].left;
                    }
                    else
                    {
                        now = V[now].left;
                    }
                }
                else
                {
                    if (V[now].right == -1)
                    {
                        V[now].right = V.Count;
                        V.Add(new Node(j + 1));
                        now = V[now].right;
                    }
                    else
                    {
                        now = V[now].right;
                    }
                }
                if (j == S.Length - 1)
                {
                    V[now].exist = true;
                }
            }
        }
        long ans = 0;
        foreach (var u in V)
        {
            if (u.exist) continue;
            if (u.left == -1 || u.right == -1)
            {
                ans ^= (L - u.depth) & (u.depth - L);
            }
        }
        if (ans != 0)
        {
            WriteLine("Alice");
        }
        else
        {
            WriteLine("Bob");
        }
    }

}

class Node
{
    public int depth, left, right;
    public bool exist;
    public Node()
    {
        depth = left = right = -1;
        exist = false;
    }
    public Node(int d)
    {
        depth = left = right = -1;
        exist = false;
        depth = d;
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