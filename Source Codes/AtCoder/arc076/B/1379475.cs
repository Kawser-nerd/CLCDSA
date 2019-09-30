using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Text;
using System.Text.RegularExpressions;
using System.Linq;

class Program
{
    static void Main()
    {
        new Magatro().Solve();
    }
}

struct Node
{
    public int Num, N;
    public Node(int num, int n)
    {
        Num = num;
        N = n;
    }
}

struct W
{
    public int X, Y, D;
    public W(int x, int y, int d)
    {
        X = x;
        Y = y;
        D = d;
    }
}

public class UnionFind
{
    private int[] Par;
    private int[] Rank;

    public UnionFind(int n)
    {
        Par = (new int[n]).Select((i, index) => index).ToArray();
        Rank = new int[n];
    }

    public int Root(int a)
    {
        if (Par[a] == a) return a;
        else return Root(Par[a]);
    }

    public bool Same(int a, int b)
    {
        return Root(a) == Root(b);
    }

    public bool Union(int a, int b)
    {
        a = Root(a);
        b = Root(b);
        if (a != b)
        {
            if (Rank[a] < Rank[b])
            {
                Par[a] = b;
            }
            else
            {
                Par[b] = a;
                if (Rank[a] == Rank[b])
                {
                    Rank[a]++;
                }
            }
            return true;
        }
        else
        {
            return false;
        }
    }
}

class Magatro
{
    private int N;
    private Node[] x, y;

    public void Solve()
    {
        N = int.Parse(Console.ReadLine());
        x = new Node[N];
        y = new Node[N];
        for (int i = 0; i < N; i++)
        {
            var line = Console.ReadLine().Split(' ');
            x[i] = new Node(i, int.Parse(line[0]));
            y[i] = new Node(i, int.Parse(line[1]));
        }

        Array.Sort(x, (a, b) => a.N.CompareTo(b.N));
        Array.Sort(y, (a, b) => a.N.CompareTo(b.N));
        var l = new List<W>();
        for (int i = 1; i < N; i++)
        {
            l.Add(new W(x[i].Num, x[i - 1].Num, x[i].N - x[i - 1].N));
            l.Add(new W(y[i].Num, y[i - 1].Num, y[i].N - y[i - 1].N));
        }
        l.Sort((a, b) => a.D.CompareTo(b.D));
        var uf = new UnionFind(N);
        long ans = 0;
        foreach (var w in l)
        {
            if (uf.Union(w.X, w.Y))
            {
                ans += w.D;
            }
        }
        Console.WriteLine(ans);
    }
}