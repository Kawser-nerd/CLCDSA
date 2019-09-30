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

            var e = new List<List<int>>();
            for (int i = 0; i < n; i++)
            {
                e.Add(new List<int>());
            }

            for (int i = 0; i < m; i++)
            {
                str = Console.ReadLine().Split();
                var u = Int32.Parse(str[0]);
                var v = Int32.Parse(str[1]);
                e[u - 1].Add(v - 1);
                e[v - 1].Add(u - 1);
            }

            Console.SetOut(new StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false });
            foreach (var r in Solver.Solve(n, s - 1, e))
            {
                Console.WriteLine(r);
            }
            Console.Out.Flush();
        }
    }

    public class Solver
    {
        public static IEnumerable<int> Solve(int n, int s, List<List<int>> e)
        {
            var dist = new int[n];
            for (int i = 0; i < n; i++) dist[i] = -1;

            var que = new PriorityQueue<ComparablePair<int, int>>();    //desc by score
            que.Push(new ComparablePair<int, int>(s, s));

            while (que.Count() > 0)
            {
                var nextPair = que.Pop();
                var score = nextPair.Item1;
                var node = nextPair.Item2;
                if (dist[node] >= score) continue;

                dist[node] = score;

                foreach (var next in e[node])
                    que.Push(new ComparablePair<int, int>(Math.Min(next, score), next));
            }

            return Enumerable.Range(1, n).Where(v => dist[v - 1] >= v - 1);
        }
    }

    public class ComparablePair<T, U> : IComparable where T : IComparable<T>
    {
        public readonly T Item1;
        public readonly U Item2;

        public int CompareTo(object obj)
        {
            ComparablePair<T, U> castedObj = (ComparablePair<T, U>)obj;
            return castedObj.Item1.CompareTo(this.Item1);
        }

        public ComparablePair(T t, U u)
        {
            Item1 = t;
            Item2 = u;
        }
    }

    public class PriorityQueue<T> where T : IComparable
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
}