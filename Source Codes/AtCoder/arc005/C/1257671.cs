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
            var str = Console.ReadLine().Split();
            var h = Int32.Parse(str[0]);
            var w = Int32.Parse(str[1]);
            var map = new string[h];
            for (int i = 0; i < h; i++)
            {
                map[i] = Console.ReadLine();
            }

            if (Possible(map))
            {
                Console.WriteLine("YES");
            }
            else
            {
                Console.WriteLine("NO");
            }
        }

        public static bool Possible(string[] map)
        {
            int sX = 0, sY = 0, gX = 0, gY = 0;
            for (int x = 0; x < map.Length; x++)
            {
                for (int y = 0; y < map[0].Length; y++)
                {
                    if (map[x][y] == 's')
                    {
                        sX = x;
                        sY = y;
                    }
                    if (map[x][y] == 'g')
                    {
                        gX = x;
                        gY = y;
                    }
                }
            }

            var costs = new int[map.Length, map[0].Length];
            for (int i = 0; i < costs.GetLength(0); i++ ) for (int j = 0; j < costs.GetLength(1); j++)
            {
                costs[i, j] = Int32.MaxValue;
            }

            var que = new PriorityQueue<ComparablePair<int, int, int>>();
            que.Push(new ComparablePair<int, int, int>(0, sX, sY));

            var dirs = new int[][]{
                new int[] { 1, 0 },
                new int[] { -1, 0 },
                new int[] { 0, -1 },
                new int[] { 0, 1 },
            };

            while (que.Count() > 0)
            {
                var next = que.Pop();
                var cost = next.Item1;
                var x = next.Item2;
                var y = next.Item3;

                if (costs[x, y] <= cost) continue;
                costs[x, y] = cost;

                if (cost > 2) continue;
                if (x != gX || y != gY)
                {
                    for (int i = 0; i < 4; i++)
                    {
                        var nX = x + dirs[i][0];
                        var nY = y + dirs[i][1];

                        if (nX >= 0 && nX < map.Length && nY >= 0 && nY < map[0].Length)
                        {
                            var newCost = cost + (map[nX][nY] == '#' ? 1 : 0);

                            if (costs[nX, nY] > newCost)
                            {
                                que.Push(new ComparablePair<int, int, int>(newCost, nX, nY));
                            }
                        }
                    }
                }
                else
                {
                    if (cost <= 2) return true;
                }
            }

            return costs[gX, gY] <= 2;
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

    public class ComparablePair<T, U, V> : IComparable where T : IComparable<T>
    {
        public readonly T Item1;
        public readonly U Item2;
        public readonly V Item3;

        public int CompareTo(object obj)
        {
            ComparablePair<T, U, V> castedObj = (ComparablePair<T, U, V>)obj;
            return this.Item1.CompareTo(castedObj.Item1);
        }

        public ComparablePair(T t, U u, V v)
        {
            Item1 = t;
            Item2 = u;
            Item3 = v;
        }
    }


#if DEBUG
    [TestClass]
    public class Test
    {
        [TestMethod]
        public void TestMethod()
        {

        }
    }
#endif
}