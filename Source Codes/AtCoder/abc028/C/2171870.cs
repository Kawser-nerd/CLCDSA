using System;
using System.Text;
using System.Linq;
using System.Collections;
using System.Collections.Generic;
using static System.Console;
using static System.Math;

namespace NotFounds
{
    public class Program
    {
        public static void Main(string[] args)
        {
            var sw = new System.IO.StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false };
            Console.SetOut(sw);
            new Program().Solve(new ConsoleInput(Console.In, ' '));
            Console.Out.Flush();
        }

        public void Solve(ConsoleInput cin)
        {
            var A = cin.ReadIntArray(5).Combinations(3).Select(x => x.Sum()).OrderByDescending(x => x).ToList();
            WriteLine(A[2]);
        }
    }

    public static class MyEnumerableExtentions
    {
        public static IEnumerable<IEnumerable<T>> Combinations<T>(this IEnumerable<T> source, int r)
        {
            if (source.Count() == 0) yield return new T[0];
            else
            {
                if (r == 1) foreach (var e in source) yield return new T[] {e};
                else if (r > 1)
                {
                    var x = new T[] { source.First() };
                    foreach (var e in source.Skip(1).Combinations(r - 1))
                        yield return x.Concat(e);
                    if (source.Count() > r)
                        foreach (var e in source.Skip(1).Combinations(r))
                            yield return e;
                }
            }
        }
    }

    public class ConsoleInput
    {
        private readonly System.IO.TextReader _stream;
        private char _separator = ' ';
        private Queue<string> inputStream;
        public ConsoleInput(System.IO.TextReader stream, char separator = ' ')
        {
            this._separator = separator;
            this._stream = stream;
            inputStream = new Queue<string>();
        }
        public string Read
        {
            get
            {
                if (inputStream.Count != 0) return inputStream.Dequeue();
                string[] tmp = _stream.ReadLine().Split(_separator);
                for (int i = 0; i < tmp.Length; ++i)
                    inputStream.Enqueue(tmp[i]);
                return inputStream.Dequeue();
            }
        }
        public string ReadLine { get { return _stream.ReadLine(); }}
        public int ReadInt { get { return int.Parse(Read); }}
        public long ReadLong { get { return long.Parse(Read); }}
        public double ReadDouble { get { return double.Parse(Read); }}
        public string[] ReadStrArray(long N) { var ret = new string[N]; for (long i = 0; i < N; ++i) ret[i] = Read; return ret;}
        public int[] ReadIntArray(long N) { var ret = new int[N]; for (long i = 0; i < N; ++i) ret[i] = ReadInt; return ret;}
        public long[] ReadLongArray(long N) { var ret = new long[N]; for (long i = 0; i < N; ++i) ret[i] = ReadLong; return ret;}
        public void ReadIntArrays(long N, out int[] A, out int[] B) { A = new int[N]; B = new int[N]; for (long i = 0; i < N; ++i) { A[i] = ReadInt; B[i] = ReadInt; }}
    }
}