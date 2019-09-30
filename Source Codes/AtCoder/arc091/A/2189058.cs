using System;
using System.IO;
using System.Collections.Generic;

namespace ARC091
{
    public class Program
    {
        void Solve(StreamScanner ss, StreamWriter sw)
        {
            //---------------------------------
            var H = ss.Next(Long);
            var W = ss.Next(Long);

            if (H == 1 && W == 1)
            {
                sw.WriteLine(1);
                return;
            }

            if (H == 1)
            {
                sw.WriteLine(W - 2);
                return;
            }

            if (W == 1)
            {
                sw.WriteLine(H - 2);
                return;
            }

            sw.WriteLine((H - 2) * (W - 2));
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
        static readonly Func<string, int> Int = int.Parse;
        static readonly Func<string, long> Long = long.Parse;
        static readonly Func<string, double> Double = double.Parse;
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