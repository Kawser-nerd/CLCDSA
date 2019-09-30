#if DEBUG
using Microsoft.VisualStudio.TestTools.UnitTesting;
#endif

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Globalization;
using System.Numerics;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            var n = Int32.Parse(Console.ReadLine());
            var x = new List<int>();
            var y = new List<int>();
            var t = new List<int>();
            var r = new List<int>();

            for (int i = 0; i < n; i++)
            {
                var s = Console.ReadLine().Split();
                x.Add(Int32.Parse(s[0]));
                y.Add(Int32.Parse(s[1]));
                t.Add(Int32.Parse(s[2]));
                r.Add(Int32.Parse(s[3]));
            }

            Console.WriteLine(GetAns(n, x, y, t, r));
        }

        public static double GetAns(int n, List<int> x, List<int> y, List<int> t, List<int> r)
        {
            var costs = new double[n];
            for (int i = 0; i < n; i++)
            {
                costs[i] = double.MaxValue;
            }

            var que = new PriorityQueue<ComparablePair<double, int>>();
            que.Push(new ComparablePair<double, int>(0, 0));

            while (que.Count() > 0)
            {
                var i = que.Pop();
                var cost = i.Item1;
                var idx = i.Item2;

                if (cost >= costs[idx]) continue;
                costs[idx] = cost;

                for (int tgt = 0; tgt < n; tgt++)
                {
                    if (idx == tgt) continue;
                    var nextCost = cost + GetCost(idx, tgt, x, y, t, r);

                    if (costs[tgt] <= nextCost) continue;
                    que.Push(new ComparablePair<double, int>(nextCost, tgt));
                }
            }

            costs = costs.OrderByDescending(c => c).ToArray();
            for (int i = 0; i < n - 1; i++) costs[i] += i;
            return costs.Max();
        }

        static double GetCost(int i1, int i2, List<int> x, List<int> y, List<int> t, List<int> r)
        {
            var dist = Math.Sqrt(Math.Pow(x[i1] - x[i2], 2) + Math.Pow(y[i1] - y[i2], 2));
            var speed = (double)Math.Min(t[i1], r[i2]);
            return dist / speed;
        }
    }

    public class ComparablePair<T, U> : IComparable where T : IComparable<T>
    {
        public readonly T Item1;
        public readonly U Item2;

        public int CompareTo(object obj)
        {
            ComparablePair<T, U> castedObj = (ComparablePair<T, U>)obj;
            return this.Item1.CompareTo(castedObj.Item1);
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

#if DEBUG
    [TestClass]
    public class Test
    {
        [TestMethod]
        public void TestMethod()
        {
            var n = 4;
            var x = new List<int> { 0, 0, 0, 0 };
            var y = new List<int> { 0, 100, 200, 300 };
            var t = new List<int> { 300, 10, 10, 10 };
            var r = new List<int> { 10, 100, 200, 300 };

            Assert.AreEqual(3, Program.GetAns(n, x, y, t, r));

            n = 1;
            x = new List<int> { 0 };
            y = new List<int> { 0 };
            t = new List<int> { 300 };
            r = new List<int> { 10 };

            Assert.AreEqual(0, Program.GetAns(n, x, y, t, r));
        }
    }
#endif
}