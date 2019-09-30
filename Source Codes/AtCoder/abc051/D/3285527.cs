using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Competitive
{
    
    // libs ----------
    internal class Solution
    {
        public int N, M;
        public Graph G;
        public void Run()
        {
            // Input
            {
                var line = Input.ReadIntArray();
                N = line[0];
                M = line[1];
            }

            // Graph
            G = new Graph(N);
            for (int i = 0; i < M; i++)
            {
                var line = Input.ReadIntArray();
                int u = line[0] - 1;
                int v = line[1] - 1;
                int c = line[2];

                // ?????
                var e1 = new Edge(u, v, c);
                var e2 = new Edge(v, u, c);
                e1.Rev = e2;
                e2.Rev = e1;
                G[u].Edges.Add(e1);
                G[v].Edges.Add(e2);
            }

            for (int i = 0; i < N; i++)
            {
                Dijkstra(i);
            }

            int ret = 0;
            for (int i = 0; i < N; i++)
            {
                var n = G[i];
                foreach (var ee in n.Edges)
                {
                    if (!ee.Used && !ee.Rev.Used)
                        ret++;
                }
            }

            Console.WriteLine(ret / 2);
        }

        public void Dijkstra(int start)
        {
            var pq = new PriorityQueue<EdgeData>();
            pq.Push(new EdgeData(0, new Edge(-1, start, 0)));

            for (int i = 0; i < N; i++)
            {
                G[i].Dist = int.MaxValue;
            }
            
            while (pq.Count() > 0)
            {
                var d = pq.Pop();
                var n = G[d.Edge.To];
                // Console.Error.WriteLine($"{d.Edge.From} -> {d.Edge.To}, d-dist:{d.Dist} n-dist{n.Dist} ");

                if (n.Dist != int.MaxValue)
                {
                    if (n.Dist == d.Dist)
                    {
                        d.Edge.Used = true;
                        // Console.Error.WriteLine($"{d.Edge.From} -> {d.Edge.To}, d-dist:{d.Dist} n-dist{n.Dist} ");
                    }
                    continue;
                }
                d.Edge.Used = true;
                // Console.Error.WriteLine($"{d.Edge.From} -> {d.Edge.To}, d-dist:{d.Dist} n-dist{n.Dist} ");

                n.Dist = d.Dist;
                foreach (var ee in n.Edges)
                {
                    pq.Push(new EdgeData(d.Dist + ee.Cost, ee));
                }
            }
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
        public Edge Rev;
        public bool Used;

        public Edge(int fr, int to, int cost = 0)
        {
            From = fr;
            To = to;
            Cost = cost;
        }

        public bool IsRev(Edge e)
        {
            return Rev != null && (e == Rev);
        }
    }

    // common ----------

    internal static class Input
    {
        public static string ReadString()
        {
            string line = Console.ReadLine();
            return line;
        }

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

        public static long ReadLong()
        {
            string line = Console.ReadLine();
            return long.Parse(line);
        }

        public static long[] ReadLongArray()
        {
            string line = Console.ReadLine();
            return line.Split(' ').Select(long.Parse).ToArray();
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