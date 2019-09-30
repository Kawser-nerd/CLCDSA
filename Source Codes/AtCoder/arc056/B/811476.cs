using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            var str = Console.ReadLine().Split();
            var n = Int32.Parse(str[0]);
            var m = Int32.Parse(str[1]);
            var s = Int32.Parse(str[2]);

            var e = new List<int>[n];
            for (int i = 0; i < n; i++)
            {
                e[i] = new List<int>();
            }

            for (int i = 0; i < m; i++)
            {
                str = Console.ReadLine().Split();
                var u = Int32.Parse(str[0]);
                var v = Int32.Parse(str[1]);
                e[u - 1].Add(v - 1);
                e[v - 1].Add(u - 1);
            }

            Solver.Solve(n, s - 1, e);
        }
    }

    public class Solver
    {
        public static void Solve(int n, int s, List<int>[] e)
        {
            var visit = new bool[n];
            var BN = new int[n];
            for (int i = 0; i < n; i++) BN[i] = -1;

            var que = new SkewHeap<Pair>();    //desc by score
            que.Push(new Pair(s, s));

            BN[s] = s;

            while (que.Count > 0)
            {
                var nextPair = que.Top;
                que.Pop();
                var score = nextPair.Cost;
                var node = nextPair.Pos;

                if (visit[node]) continue;
                visit[node] = true;
                BN[node] = score;

                foreach (var next in e[node])
                {
                    if (score <= BN[next]) continue;

                    BN[next] = Math.Min(next, score);
                    que.Push(new Pair(next, Math.Min(next, score)));
                }

            }

            Console.SetOut(new StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false });
            for (int i = 0; i < n; i++)
            {
                if (BN[i] >= i) Console.WriteLine(i + 1);
            }
            Console.Out.Flush();
//            return Enumerable.Range(1, n).Where(v => dist[v - 1] >= v - 1);
        }
    }

    class Pair : IComparable<Pair>
    {
        public int Pos;
        public int Cost;
        public Pair(int p, int c)
        {
            Pos = p; Cost = c;
        }
        public int CompareTo(Pair t)
        {
            return this.Cost > t.Cost ? -1 : this.Cost < t.Cost ? 1 : 0;
            //return this.Cost > t.Cost ? 1 : this.Cost < t.Cost ? -1 : 0;
        }
    }

    public class SkewHeap<T> where T : IComparable<T>
    {
        public int Count
        {
            get { return cnt; }
            private set { cnt = value; }
        }

        public SkewHeap()
        {
            root = null;
            this.Count = 0;
        }

        public void Push(T v)
        {
            NodeSH<T> p = new NodeSH<T>(v);
            root = NodeSH<T>.Meld(root, p);
            this.Count++;
        }

        public void Pop()
        {
            if (root == null) return;
            root = NodeSH<T>.Meld(root.L, root.R);
            this.Count--;
        }

        public T Top
        {
            get { return root.Val; }
        }

        int cnt;
        NodeSH<T> root;

        class NodeSH<S> where S : IComparable<S>
        {
            public NodeSH<S> L, R;
            public S Val;

            public NodeSH(S v)
            {
                Val = v;
                L = null; R = null;
            }
            public static NodeSH<S> Meld(NodeSH<S> a, NodeSH<S> b)
            {
                if (a == null) return b;
                if (b == null) return a;
                if (a.Val.CompareTo(b.Val) > 0) swap(ref a, ref b);
                a.R = Meld(a.R, b);
                swap(ref a.L, ref a.R);
                return a;
            }

            static void swap<U>(ref U x, ref U y)
            {
                U t = x; x = y; y = t;
            }
        }
    }
}