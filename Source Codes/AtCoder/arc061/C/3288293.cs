using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Competitive
{
    // http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_12_C
    internal class Solution
    {
        public int N, M;
        public Graph G;
        public Dictionary<long, int> map;
        public int[] P, Q, C;
        public void Run()
        {
            {
                var line = Input.ReadIntArray();
                N = line[0];
                M = line[1];
            }

            P = new int[M];
            Q = new int[M];
            C = new int[M];
            {
                for (int i = 0; i < M; i++)
                {
                    var line = Input.ReadIntArray();
                    int p = line[0] - 1;
                    int q = line[1] - 1;
                    int c = line[2] + 1;
                    P[i] = p;
                    Q[i] = q;
                    C[i] = c;
                }
            }

            G = new Graph(0);
            map = new Dictionary<long, int>();

            // (i, 0) ???
            for (int i = 0; i < N; i++)
            {
                long x = i;
                int id = G.AddNode();
                map.Add(x, id);
            }

            // (p, c), (q, c)???
            // (p, c) <-> (q, c)
            // (p, c) <-> (p, 0)
            // (q, c) <-> (q, 0)
            for (int i = 0; i < M; i++)
            {
                long x1 = C[i] * 100000000L + P[i];
                long x2 = C[i] * 100000000L + Q[i];

                if (!map.ContainsKey(x1))
                {
                    int id = G.AddNode();
                    map.Add(x1, id);
                }

                if (!map.ContainsKey(x2))
                {
                    int id = G.AddNode();
                    map.Add(x2, id);
                }

                int idx1 = map[x1];
                int idx2 = map[x2];
                int i1 = map[P[i]];
                int i2 = map[Q[i]];

                G[idx1].Edges.Add(new Edge(idx1, idx2, 0));
                G[idx2].Edges.Add(new Edge(idx2, idx1, 0));

                G[i1].Edges.Add(new Edge(i1, idx1, 1));
                G[idx1].Edges.Add(new Edge(idx1, i1, 0));
                G[i2].Edges.Add(new Edge(i2, idx2, 1));
                G[idx2].Edges.Add(new Edge(idx2, i2, 0));
            }

            int start = 0;
            int goal = N - 1;
            var pq = new PriorityQueue<EdgeData>();
            pq.Push(new EdgeData(0, new Edge(-1, start, 0)));

            while (pq.Count() > 0)
            {
                var d = pq.Pop();
                var n = G[d.Edge.To];
                if (n.Dist != int.MaxValue) continue;

                n.Dist = d.Dist;
                foreach (var ee in n.Edges)
                {
                    pq.Push(new EdgeData(d.Dist + ee.Cost, ee));
                }
            }

            int ret = G[goal].Dist;
            if (ret == int.MaxValue)
                ret = -1;
            Console.WriteLine(ret);
        }

    }

    // ???IComparable?????
    class EdgeData : IComparable<EdgeData>, IComparable
    {
        public int Dist;
        public Edge Edge;
        public EdgeData(int dist, Edge edge)
        {
            Dist = dist;
            Edge = edge;
        }

        public int CompareTo(EdgeData other)
        {
            return Dist.CompareTo(other.Dist);
        }

        public int CompareTo(object obj)
        {
            if (obj == null) return 1;
            if (GetType() != obj.GetType()) throw new ArgumentException();
            return CompareTo((EdgeData)obj);
        }
    }

    internal class Graph
    {
        public List<Node> Nodes;

        public Node this[int i]
        {
            set { Nodes[i] = value; }
            get { return Nodes[i]; }
        }

        public Graph(int N)
        {
            Nodes = new List<Node>();
            for (int i = 0; i < N; i++)
            {
                Nodes.Add(new Node(i));
            }
        }

        public int AddNode()
        {
            int i = Nodes.Count;
            Nodes.Add(new Node(i));
            return i;
        }

    }

    internal class Node
    {
        public List<Edge> Edges;
        public int Dist;
        public int No;

        public Node(int no)
        {
            this.No = no;
            Dist = int.MaxValue;
            Edges = new List<Edge>();
        }
    }

    internal class Edge
    {
        public int From;
        public int To;
        public int Cost;

        public Edge(int fr, int to, int cost = 0)
        {
            From = fr;
            To = to;
            Cost = cost;
        }

    }

    public class PriorityQueue<T> where T : IComparable<T>
    {
        private IComparer<T> _comparer = null;
        private int _type = 0;

        private T[] _heap;
        private int _sz = 0;

        private int _count = 0;

        /// <summary>
        /// Priority Queue with custom comparer
        /// </summary>
        public PriorityQueue(IComparer<T> comparer)
        {
            _heap = new T[128];
            _comparer = comparer;
        }

        /// <summary>
        /// Priority queue
        /// </summary>
        /// <param name="type">0: asc, 1:desc</param>
        public PriorityQueue(int type = 0)
        {
            _heap = new T[128];
            _type = type;
        }

        private int Compare(T x, T y)
        {
            if (_comparer != null) return _comparer.Compare(x, y);
            return _type == 0 ? x.CompareTo(y) : y.CompareTo(x);
        }

        public void Push(T x)
        {
            _count++;
            if (_count > _heap.Length)
            {
                var newheap = new T[_heap.Length * 2];
                for (int n = 0; n < _heap.Length; n++) newheap[n] = _heap[n];
                _heap = newheap;
            }

            //node number
            var i = _sz++;

            while (i > 0)
            {
                //parent node number
                var p = (i - 1) / 2;

                if (Compare(_heap[p], x) <= 0) break;

                _heap[i] = _heap[p];
                i = p;
            }

            _heap[i] = x;
        }

        public T Pop()
        {
            _count--;

            T ret = _heap[0];
            T x = _heap[--_sz];

            int i = 0;
            while (i * 2 + 1 < _sz)
            {
                //children
                int a = i * 2 + 1;
                int b = i * 2 + 2;

                if (b < _sz && Compare(_heap[b], _heap[a]) < 0) a = b;

                if (Compare(_heap[a], x) >= 0) break;

                _heap[i] = _heap[a];
                i = a;
            }

            _heap[i] = x;

            return ret;
        }

        public int Count()
        {
            return _count;
        }

        public T Peek()
        {
            return _heap[0];
        }

        public bool Contains(T x)
        {
            for (int i = 0; i < _sz; i++) if (x.Equals(_heap[i])) return true;
            return false;
        }

        public void Clear()
        {
            while (this.Count() > 0) this.Pop();
        }

        public IEnumerator<T> GetEnumerator()
        {
            var ret = new List<T>();

            while (this.Count() > 0)
            {
                ret.Add(this.Pop());
            }

            foreach (var r in ret)
            {
                this.Push(r);
                yield return r;
            }
        }

        public T[] ToArray()
        {
            T[] array = new T[_sz];
            int i = 0;

            foreach (var r in this)
            {
                array[i++] = r;
            }

            return array;
        }
    }


    internal static class Input
    {
        public static int ReadInt()
        {
            string line = Console.ReadLine();
            return int.Parse(line);
        }

        public static int[] ReadIntArray()
        {
            string line = Console.ReadLine();
            return line.Split(' ').Select(int.Parse).ToArray();
        }

        public static double[] ReadDoubleArray()
        {
            string line = Console.ReadLine();
            return line.Split(' ').Select(double.Parse).ToArray();
        }
    }

    internal class Program
    {
        public static void Main(string[] args)
        {
            var s = new Solution();
            s.Run();
        }
    }
}