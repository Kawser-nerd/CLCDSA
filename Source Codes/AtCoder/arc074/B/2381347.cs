using System;
using System.Collections;
using System.IO;
using System.Collections.Generic;
using System.Linq;

namespace ARC074D
{
    public class Program
    {
        void Solve(StreamScanner ss, StreamWriter sw)
        {
            //---------------------------------
            var N = ss.Next(int.Parse);
            var A = ss.Next(long.Parse, N * 3);

            var frontSum = new long[N + 1];
            var rearSum = new long[N + 1];

            var frontPq = new PriorityQueueForARC074D();
            var rearPq = new PriorityQueueForARC074D();

            for (var i = 0; i < N; i++)
            {
                frontPq.InitPush(A[i]);
                rearPq.InitPush(-A[N * 3 - i - 1]);
            }

            frontSum[0] = frontPq.Sum;
            rearSum[N] = -rearPq.Sum;

            for (var i = 0; i < N; i++)
            {
                frontSum[i + 1] = frontPq.Push(A[N + i]);
                rearSum[N - i - 1] = -rearPq.Push(-A[N * 2 - i - 1]);
            }

            sw.WriteLine(Enumerable.Range(0, N + 1).Max(i => frontSum[i] - rearSum[i]));
            //---------------------------------
        }

        static void Main()
        {
            var ss = new StreamScanner(new StreamReader(Console.OpenStandardInput()));
            var sw = new StreamWriter(Console.OpenStandardOutput()) {AutoFlush = false};
            new Program().Solve(ss, sw);
            sw.Flush();
        }

        static readonly Func<string, string> String = s => s;
    }

    public class PriorityQueueForARC074D
    {
        readonly PriorityQueue<long> pq = new PriorityQueue<long>();

        public long Sum { get; private set; }

        public void InitPush(long value)
        {
            Sum += value;
            pq.Enqueue(value);
        }

        public long Push(long value)
        {
            InitPush(value);
            Sum -= pq.Dequeue();
            return Sum;
        }
    }

    public class PriorityQueue<T> : IEnumerable<T> where T : IComparable<T>
    {
        public int Count { get { return list.Count; } }

        readonly List<T> list = new List<T>();

        IEnumerator<T> IEnumerable<T>.GetEnumerator()
        {
            return list.GetEnumerator();
        }

        IEnumerator IEnumerable.GetEnumerator()
        {
            return list.GetEnumerator();
        }

        public void Clear()
        {
            list.Clear();
        }

        public bool Contains(T value)
        {
            return list.Contains(value);
        }

        public T Peek()
        {
            return list[0];
        }

        public void Enqueue(T value)
        {
            list.Add(value);
            PushHeap();
        }

        public T Dequeue()
        {
            var ret = list[0];
            list[0] = list[Count - 1];
            list.RemoveAt(Count - 1);
            PopHeap();
            return ret;
        }

        void PushHeap()
        {
            var i = Count - 1;
            while (i != 0)
            {
                var p = (i - 1) / 2;
                if (list[i].CompareTo(list[p]) > 0) return;

                SwapIndex(i, i = p);
            }
        }

        void PopHeap()
        {
            var i = 0;
            while (true)
            {
                var l = 2 * i + 1;
                var r = l + 1;

                var maxi = i;
                if (l < Count && list[maxi].CompareTo(list[l]) > 0) maxi = l;
                if (r < Count && list[maxi].CompareTo(list[r]) > 0) maxi = r;
                if (maxi == i) return;

                SwapIndex(i, i = maxi);
            }
        }

        void SwapIndex(int left, int right)
        {
            var tmp = list[left];
            list[left] = list[right];
            list[right] = tmp;
        }
    }

    public class StreamScanner
    {
        static readonly char[] Sep = {' '};
        readonly Queue<string> buffer = new Queue<string>();
        readonly TextReader textReader;

        public StreamScanner(TextReader textReader)
        {
            this.textReader = textReader;
        }

        public T Next<T>(Func<string, T> parser)
        {
            if (buffer.Count != 0) return parser(buffer.Dequeue());
            var nextStrings = textReader.ReadLine().Split(Sep, StringSplitOptions.RemoveEmptyEntries);
            foreach (var nextString in nextStrings) buffer.Enqueue(nextString);
            return Next(parser);
        }

        public T[] Next<T>(Func<string, T> parser, int x)
        {
            var ret = new T[x];
            for (var i = 0; i < x; ++i) ret[i] = Next(parser);
            return ret;
        }

        public T[][] Next<T>(Func<string, T> parser, int x, int y)
        {
            var ret = new T[y][];
            for (var i = 0; i < y; ++i) ret[i] = Next(parser, x);
            return ret;
        }
    }
}