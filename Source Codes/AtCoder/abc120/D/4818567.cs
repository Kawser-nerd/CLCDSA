using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

public class UnionFind<T>
{
    private int m_height;
    private UnionFind<T> m_parent;

    public T Item { get; private set; }
    public int NumberOfChildren { get; private set; }

    public UnionFind(T item)
    {
        m_height = 0;
        m_parent = this;
        Item = item;
        NumberOfChildren = 1;
    }

    public UnionFind<T> Root()
    {
        if (m_parent == this)
        {
            return this;
        }

        UnionFind<T> parent = m_parent.Root();
        m_parent = parent;
        return parent;
    }

    public static void Unite(UnionFind<T> a, UnionFind<T> b)
    {
        UnionFind<T> p = a.Root();
        UnionFind<T> q = b.Root();
        if (p.m_height < q.m_height)
        {
            p.m_parent = q;
            q.m_height = Math.Max(p.m_height + 1, q.m_height);
            q.NumberOfChildren += p.NumberOfChildren;
        }
        else
        {
            q.m_parent = p;
            p.m_height = Math.Max(q.m_height + 1, p.m_height);
            p.NumberOfChildren += q.NumberOfChildren;
        }
    }
}

class Program
{
    public static void Main(string[] args)
    {
        MainModule(Console.In);
    }

    public static void MainModule(TextReader In)
    {
        var l1 = In.ReadLine().Split(' ').Select(n => int.Parse(n)).ToList();
        int N = l1[0];
        int M = l1[1];

        var makeLinks = new Tuple<int, int>[M];
        for (var i = 0; i < M; i++)
        {
            var line = In.ReadLine();
            var l2 = line.Split(' ').Select(n => int.Parse(n)).ToList();
            int A = l2[0];
            int B = l2[1];
            makeLinks[i] = new Tuple<int, int>(A - 1, B - 1);
        }

        var nodes = new UnionFind<int>[N];
        for (int i = 0; i < N; i++)
            nodes[i] = new UnionFind<int>(i);

        var answers = new List<long>();
        long answer = ((long)N * (N - 1)) / 2;//((long)N * (long)(N - 1)) / 2;
        answers.Add(answer);
        for (int i = M - 1; i > 0; i--)
        {
            var node1 = nodes[makeLinks[i].Item1];
            var node2 = nodes[makeLinks[i].Item2];
            var r1 = node1.Root();
            var r2 = node2.Root();
            
            if (r1 == r2)
            {
            }
            else
            {
                var nc1 = r1.NumberOfChildren;
                var nc2 = r2.NumberOfChildren;
                answer -= nc1 * nc2;

                UnionFind<int>.Unite(r1, r2);
            }
            answers.Add(answer);
        }
        answers.Reverse();
        foreach (var s in answers)
        {
            Console.WriteLine(s);
        }
    }
}