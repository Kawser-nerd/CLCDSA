using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Competitive
{
    internal class Solution
    {
        public int N;
        public long MOD = 1000000007;
        public long[] A;

        public void Run()
        {
            N = Input.ReadInt();
            A = Input.ReadLongArray();

            long[] L = new long[N + 1];
            long[] R = new long[N + 1];

            {
                // ????????
                long s = 0;
                var q = new PriorityQueue<long>();
                for (int i = 0; i < N; i++)
                {
                    q.Push(A[i]);
                    s += A[i];
                }

                L[0] = s;

                for (int i = N; i < 2 * N; i++)
                {
                    q.Push(A[i]);
                    s += A[i];
                    s -= q.Pop();
                    L[i - N + 1] = s;
                }
            }

            {
                // ????????
                long s = 0;
                var q = new PriorityQueue<long>(1);
                for (int i = 0; i < N; i++)
                {
                    q.Push(A[3 * N - 1 - i]);
                    s += A[3 * N - 1 - i];
                }

                R[0] = s;

                for (int i = N; i < 2 * N; i++)
                {
                    q.Push(A[3 * N - 1 - i]);
                    s += A[3 * N - 1 - i];
                    s -= q.Pop();
                    R[i - N + 1] = s;
                }
            }

            long ret = long.MinValue;
            for (int i = 0; i <= N ; i++)
            {
                ret = Math.Max(L[i] - R[N - i], ret);
            }

            Console.WriteLine(ret);
        }
    }

    // libs ----------

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