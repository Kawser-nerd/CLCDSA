using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace ABC119D
{
    public partial class Program
    {
        void Solve(StreamScanner ss, StreamWriter sw)
        {
            //---------------------------------
            var A = ss.Next(int.Parse);
            var B = ss.Next(int.Parse);
            var Q = ss.Next(int.Parse);
            var S = ss.Next(long.Parse, A);
            var T = ss.Next(long.Parse, B);
            var X = ss.Next(long.Parse, Q);

            var sb = S.ToBinarySearch();
            var tb = T.ToBinarySearch();

            foreach (var x in X)
            {
                var si = sb.LowerBound(x);
                var ti = tb.LowerBound(x);

                var ans = new List<long>();
                if (si != A && ti != B) ans.Add(Math.Max(-(x - S[si]), -(x - T[ti])));//rr
                if (si != A && ti != 0) ans.Add(Math.Min(-(x - S[si]) * 2 + (x - T[ti - 1]), -(x - S[si]) + (x - T[ti - 1]) * 2));//rl
                if (si != 0 && ti != B) ans.Add(Math.Min((x - S[si - 1]) * 2 - (x - T[ti]), (x - S[si - 1]) - (x - T[ti]) * 2));//lr
                if (si != 0 && ti != 0) ans.Add(Math.Max((x - S[si - 1]), (x - T[ti - 1])));//ll

                sw.WriteLine(ans.Min());
            }
            //---------------------------------
        }
    }

    public static partial class BinarySearch
    {
        public static BinarySearch<T> Default<T>(Func<long, T> func, long left, long right) where T : IComparable<T>
        {
            return new BinarySearch<T>().SetFunc(func).SetInterval(left, right);
        }

        public static BinarySearch<T> Array<T>(T[] source) where T : IComparable<T>
        {
            return new BinarySearch<T>().SetFunc(x => source[x]).SetInterval(0, source.Length);
        }

        public static BinarySearch<T> ToBinarySearch<T>(this T[] source) where T : IComparable<T>
        {
            return Array(source);
        }
    }

    public class BinarySearch<T> where T : IComparable<T>
    {
        Func<long, T> Func { get; set; } = null;
        long Left { get; set; } = 0;
        long Right { get; set; } = 0;
        bool IsOrderAscending { get; set; } = true;

        public BinarySearch<T> SetFunc(Func<long, T> func)
        {
            Func = func;
            return this;
        }

        public BinarySearch<T> SetInterval(long left, long right)
        {
            if (left > right) throw new ArgumentException($"{nameof(left)} <= {nameof(right)}");
            Left = left;
            Right = right;
            return this;
        }

        public BinarySearch<T> SetOrder(bool isOrderAscending)
        {
            IsOrderAscending = isOrderAscending;
            return this;
        }

        long BoundToTheRight(Func<long, bool> pred, long left, long right)
        {
            while (true)
            {
                if (left == right) return right;
                var mid = (left + right - 1) >> 1;
                if (pred(mid)) right = mid;
                else left = mid + 1;
            }
        }

        public long LowerBound(T value)
        {
            var sign = IsOrderAscending ? 1 : -1;
            return BoundToTheRight(x => sign * Func(x).CompareTo(value) >= 0, Left, Right);
        }

        public long UpperBound(T value)
        {
            var sign = IsOrderAscending ? 1 : -1;
            return BoundToTheRight(x => sign * Func(x).CompareTo(value) > 0, Left, Right);
        }

        public long Range(T vLeft, T vRight)
        {
            return Math.Max(0, UpperBound(vRight) - LowerBound(vLeft));
        }

        public long Count(T value)
        {
            return Range(value, value);
        }
    }

    public class StreamScanner
    {
        static readonly char[] Separator = { ' ' };
        readonly StreamReader streamReader;

        string[] line = new string[0];
        int index = 0;

        public StreamScanner(Stream stream)
        {
            this.streamReader = new StreamReader(stream);
        }

        public string Next()
        {
            return Next(s => s);
        }

        public string[] Next(int x)
        {
            return Next(s => s, x);
        }

        public string[][] Next(int x, int y)
        {
            return Next(s => s, x, y);
        }

        public T Next<T>(Func<string, T> parser)
        {
            if (index < line.Length) return parser(line[index++]);
            index = 0;
            line = streamReader.ReadLine()?.Split(Separator, StringSplitOptions.RemoveEmptyEntries);
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

    public partial class Program
    {
        static void Main()
        {
            Excute(Console.OpenStandardInput(), Console.OpenStandardOutput());
        }

        public static void Excute(Stream input, Stream output)
        {
            var ss = new StreamScanner(input);
            var sw = new StreamWriter(output);
            new Program().Solve(ss, sw);
            sw.Flush();
        }
    }
}