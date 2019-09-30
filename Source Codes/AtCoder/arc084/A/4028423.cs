using System;
using System.IO;
using System.Collections.Generic;

namespace ARC084C
{
    public class Program
    {
        void Solve(StreamScanner ss, StreamWriter sw)
        {
            //---------------------------------
            var N = ss.Next(int.Parse);
            var A = ss.Next(long.Parse, N);
            var B = ss.Next(long.Parse, N);
            var C = ss.Next(long.Parse, N);

            Array.Sort(A);
            Array.Sort(B);
            Array.Sort(C);

            var bcSum = new long[N + 1];
            for (var i = N - 1; i >= 0; i--)
            {
                var cnt = N - C.UpperBound(B[i]);
                bcSum[i] = bcSum[i + 1] + cnt;
            }

            var abcSum = new long[N + 1];
            for (var i = N - 1; i >= 0; i--)
            {
                var cnt = bcSum[B.UpperBound(A[i])];
                abcSum[i] = abcSum[i + 1] + cnt;
            }

            sw.WriteLine(abcSum[0]);
            //---------------------------------
        }

        static void Main()
        {
            var ss = new StreamScanner(new StreamReader(Console.OpenStandardInput()));
            var sw = new StreamWriter(Console.OpenStandardOutput()) {AutoFlush = false};
            new Program().Solve(ss, sw);
            sw.Flush();
        }
    }

    public static partial class BinarySearch
    {
        static long BoundToTheRight(Func<long, bool> pred, long left, long right)
        {
            if (left > right) throw new ArgumentException("left must <= right");

            while (true)
            {
                if (left == right) return right;
                var mid = (left + right - 1) / 2;
                if (pred(mid)) right = mid;
                else left = mid + 1;
            }
        }

        public static long LowerBound<T>(Func<long, T> func, T value, long left, long right) where T : IComparable<T>
        {
            return BoundToTheRight(x => func(x).CompareTo(value) >= 0, left, right);
        }

        public static long UpperBound<T>(Func<long, T> func, T value, long left, long right) where T : IComparable<T>
        {
            return BoundToTheRight(x => func(x).CompareTo(value) > 0, left, right);
        }

        public static int LowerBound<T>(this T[] source, T value) where T : IComparable<T>
        {
            return (int)LowerBound(x => source[x], value, 0, source.Length);
        }

        public static int UpperBound<T>(this T[] source, T value) where T : IComparable<T>
        {
            return (int)UpperBound(x => source[x], value, 0, source.Length);
        }

        public static int Range<T>(this T[] source, T vLeft, T vRight) where T : IComparable<T>
        {
            return source.UpperBound(vRight) - source.LowerBound(vLeft);
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