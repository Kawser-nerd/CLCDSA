using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Contest
{
    class Scanner
    {
        private string[] line = new string[0];
        private int index = 0;
        public string Next()
        {
            if (line.Length <= index)
            {
                line = Console.ReadLine().Split(' ');
                index = 0;
            }
            var res = line[index];
            index++;
            return res;
        }
        public int NextInt()
        {
            return int.Parse(Next());
        }
        public long NextLong()
        {
            return long.Parse(Next());
        }
        public string[] Array()
        {
            line = Console.ReadLine().Split(' ');
            index = line.Length;
            return line;
        }
        public int[] IntArray()
        {
            var array = Array();
            var result = new int[array.Length];
            for (int i = 0; i < array.Length; i++)
            {
                result[i] = int.Parse(array[i]);
            }

            return result;
        }
        public long[] LongArray()
        {
            var array = Array();
            var result = new long[array.Length];
            for (int i = 0; i < array.Length; i++)
            {
                result[i] = long.Parse(array[i]);
            }

            return result;
        }
    }

    class PriorityQueue<T>
    {
        private readonly List<T> heap;
        private readonly Comparison<T> compare;
        private int size;
        public PriorityQueue() : this(Comparer<T>.Default) { }
        public PriorityQueue(IComparer<T> comparer) : this(16, comparer.Compare) { }
        public PriorityQueue(Comparison<T> comparison) : this(16, comparison) { }
        public PriorityQueue(int capacity, Comparison<T> comparison)
        {
            this.heap = new List<T>(capacity);
            this.compare = comparison;
        }
        public void Enqueue(T item)
        {
            this.heap.Add(item);
            var i = size++;
            while (i > 0)
            {
                var p = (i - 1) >> 1;
                if (compare(this.heap[p], item) <= 0)
                    break;
                this.heap[i] = heap[p];
                i = p;
            }
            this.heap[i] = item;

        }
        public T Dequeue()
        {
            var ret = this.heap[0];
            var x = this.heap[--size];
            var i = 0;
            while ((i << 1) + 1 < size)
            {
                var a = (i << 1) + 1;
                var b = (i << 1) + 2;
                if (b < size && compare(heap[b], heap[a]) < 0) a = b;
                if (compare(heap[a], x) >= 0)
                    break;
                heap[i] = heap[a];
                i = a;
            }
            heap[i] = x;
            heap.RemoveAt(size);
            return ret;
        }
        public T Peek() { return heap[0]; }
        public int Count { get { return size; } }
        public bool Any() { return size > 0; }
    }

    class SegTree
    {
        private readonly long[] Array;
        private readonly int N;

        public SegTree(int size)
        {
            N = 1;
            while (N < size)
            {
                N *= 2;
            }
            Array = new long[N * 2];
        }

        public void Update(long item, int index)
        {
            index += N;
            Array[index] = item;
            while (index > 1)
            {
                index /= 2;
                Array[index] = Array[index * 2] + Array[index * 2 + 1];
            }
        }

        private long Q(int left, int right, int k, int l, int r)
        {
            if (left <= l && r <= right)
            {
                return Array[k];
            }
            if (r <= left || right <= l)
            {
                return 0;
            }
            return Q(left, right, k * 2, l, (l + r) / 2) + Q(left, right, k * 2 + 1, (l + r) / 2, r);
        }

        public long Query(int left, int right)
        {
            return Q(left, right, 1, 0, N);
        }

        public long this[int i]
        {
            get { return Array[i + N]; }
            set { Update(value, i); }
        }
    }

    class Program
    {
        private int N;
        private long K;
        private long[] A;
        private void Scan()
        {
            var sc = new Scanner();
            N = sc.NextInt();
            K = sc.NextInt();
            A = new long[N];
            for (int i = 0; i < N; i++)
            {
                A[i] = sc.NextInt();
            }
        }

        public void Solve()
        {
            Scan();
            var c = new long[N + 1];
            for (int i = 1; i <= N; i++)
            {
                c[i] = c[i - 1] + A[i - 1];
            }
            var b = c.Select((l, index) => l - K * index).ToArray();

            long ans = 0;
            var zip = F(b);
            var segTree = new SegTree(N + 1);
            for (int i = 0; i <= N; i++)
            {
                ans += segTree.Query(0, zip[i] + 1);
                segTree[zip[i]]++;
            }
            Console.WriteLine(ans);
        }

        struct S
        {
            public long Num;
            public int Index;

            public S(long num, int index)
            {
                Num = num;
                Index = index;
            }
        }

        private int[] F(long[] array)
        {
            var structArray = new S[array.Length];
            for (int i = 0; i < array.Length; i++)
            {
                structArray[i] = new S(array[i], i);
            }
            Array.Sort(structArray, (a, b) => a.Num.CompareTo(b.Num));
            var result = new int[array.Length];
            int num = 0;
            long p = structArray[0].Num;
            for (int i = 0; i < array.Length; i++)
            {
                if (p == structArray[i].Num)
                {
                    result[structArray[i].Index] = num;
                }
                else
                {
                    p = structArray[i].Num;
                    result[structArray[i].Index] = ++num;
                }
            }
            return result;
        }

        static void Main(string[] args)
        {
            new Program().Solve();
        }
    }
}