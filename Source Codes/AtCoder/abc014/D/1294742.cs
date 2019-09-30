using System;
using System.Collections.Generic;
using System.Linq;

static class Program
{
    static void Main()
    {
        new Magatro().Solve();
    }
}

class Node
{
    public int Num;//?????
    public List<int> Parent = new List<int>();//Parent[i] 2^i??
    public int Depth;
}

class Magatro
{
    private int N;
    List<int>[] R;
    Node[] Tree;
    private int Q;

    private void MakeTree()
    {
        Tree = new Node[N];
        for (int i = 0; i < N; i++)
        {
            Tree[i] = new Node();
            Tree[i].Num = i;
        }
        Tree[0].Num = 0;
        Tree[0].Depth = 0;
        Queue<int> q = new Queue<int>();
        q.Enqueue(0);
        while (q.Count > 0)//?
        {
            int d = q.Dequeue();
            foreach (int i in R[d])
            {
                if (Tree[d].Parent.Count > 0 && i == Tree[d].Parent[0])
                {
                    continue;
                }
                Tree[i].Parent.Add(d);
                Tree[i].Depth = Tree[d].Depth + 1;
                q.Enqueue(i);
            }
        }
        for(int i = 1; i < 20; i++)
        {
            for (int j = 0; j < N; j++)
            {
                int p = 1 << i;
                if (Tree[j].Depth >= p)//2^i??????
                {
                    Tree[j].Parent.Add(Tree[Tree[j].Parent[i-1]].Parent[i-1]);
                }
            }
        }
    }

    private int Query(int a, int b)
    {
        int res = 0;

        if (Tree[a].Depth > Tree[b].Depth)
        {
            a ^= b;
            b ^= a;
            a ^= b;
        }

        int sa = Tree[b].Depth - Tree[a].Depth;
        int ii = 0;
        while (sa > 0)
        {
            if (sa % 2 == 1)
            {
                b = Tree[b].Parent[ii];
                res += 1 << ii;
            }
            ii++;
            sa /= 2;
        }

        if (a == b)
        {
            return res;
        }

        while (true)
        {
            int j = -1;
            for (int i = 0; i < Tree[a].Parent.Count; i++)
            {
                if (Tree[a].Parent[i] == Tree[b].Parent[i])
                {
                    break;
                }
                j = i;
            }
            if (j == -1)
            {
                res += 2;
                break;
            }
            else
            {
                a = Tree[a].Parent[j];
                b = Tree[b].Parent[j];
                res += 1 << (j + 1);
            }
        }

        return res;
    }

    public void Solve()
    {
        N = int.Parse(Console.ReadLine());
        R = new List<int>[N];
        for (int i = 0; i < N; i++)
        {
            R[i] = new List<int>();
        }
        for (int i = 0; i < N - 1; i++)
        {
            var line = Console.ReadLine().Split(' ');
            int x = int.Parse(line[0]) - 1;
            int y = int.Parse(line[1]) - 1;
            R[x].Add(y);
            R[y].Add(x);
        }
        MakeTree();
        Q = int.Parse(Console.ReadLine());
        for (int i = 0; i < Q; i++)
        {
            var line = Console.ReadLine().Split(' ');
            int a = int.Parse(line[0]) - 1;
            int b = int.Parse(line[1]) - 1;
            Console.WriteLine(Query(a, b) + 1);
        }
    }
}