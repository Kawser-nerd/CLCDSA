using System;
using System.Text.RegularExpressions;
using System.Linq;
using System.Collections.Generic;
using System.IO;
using System.Numerics;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            var str = Console.ReadLine().Split();
            var n = Int64.Parse(str[0]);
            var m = Int64.Parse(str[1]);

            var e_typeA = new List<List<int>>();
            var e_typeB = new List<List<int>>();
            for (int i = 0; i < n; i++)
            {
                e_typeA.Add(new List<int>());
                e_typeB.Add(new List<int>());
            }

            var eTyle = new int[m];

            for (int i = 0; i < m; i++)
            {
                str = Console.ReadLine().Split();
                var c = Int32.Parse(str[0]);
                var a = Int32.Parse(str[1]);
                var b = Int32.Parse(str[2]);

                if (c == 0)
                {
                    e_typeA[a].Add(b);
                    e_typeA[b].Add(a);
                }
                else
                {
                    e_typeB[a].Add(b);
                    e_typeB[b].Add(a);
                }
            }

            //Dijkstra
            var que = new PriorityQueue<Path>();
            var min_bnum = new int[n];
            var min_cost = new int[n];
            for (int i = 0; i < n; i++)
            {
                min_bnum[i] = Int32.MaxValue;
                min_cost[i] = Int32.MaxValue;
            }
            que.Push(new Path(0, 0, 0));

            while (que.Count() > 0)
            {
                var path = que.Pop();
                if (NoNeed(path, min_bnum, min_cost)) continue;
                Update(path, min_bnum, min_cost);

                foreach (var typeA in e_typeA[path.Idx])
                {
                    var newPath = new Path(typeA, path.Cost + 1, path.Bnum);
                    if (NoNeed(newPath, min_bnum, min_cost)) continue;
                    que.Push(newPath);
                }

                foreach (var typeB in e_typeB[path.Idx])
                {
                    var newPath = new Path(typeB, path.Cost + path.Bnum + 1, path.Bnum + 1);
                    if (NoNeed(newPath, min_bnum, min_cost)) continue;
                    que.Push(newPath);
                }
            }

            for (int i = 0; i < n; i++)
                Console.WriteLine(min_cost[i]);
        }

        static bool NoNeed(Path path, int[] min_bnum, int[] min_cost)
        {
            if (path.Bnum >= min_bnum[path.Idx] && path.Cost >= min_cost[path.Idx]) return true;
            return false;
        }

        static void Update(Path path, int[] min_bnum, int[] min_cost)
        {
            min_bnum[path.Idx] = Math.Min(min_bnum[path.Idx], path.Bnum);
            min_cost[path.Idx] = Math.Min(min_cost[path.Idx], path.Cost);
        }
    }

    public class Path : IComparable
    {
        public int Idx;
        public int Cost;
        public int Bnum;

        public Path(int idx, int cost, int bnum)
        {
            Idx = idx;
            Cost = cost;
            Bnum = bnum;
        }

        public int CompareTo(object obj)
        {
            var tgt = obj as Path;
            if (Bnum == tgt.Bnum) return Cost.CompareTo(tgt.Cost);
            return Bnum.CompareTo(tgt.Bnum);
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