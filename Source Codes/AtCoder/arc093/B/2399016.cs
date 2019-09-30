using System;
using System.IO;
using System.Collections.Generic;

namespace ARC093D
{
    public class Program
    {
        void Solve(StreamScanner ss, StreamWriter sw)
        {
            //---------------------------------
            var A = ss.Next(int.Parse);
            var B = ss.Next(int.Parse);

            var h = 50;
            var w = 100;

            var ret = new char[h, w];

            for (var i = 0; i < h; i++)
            for (var j = 0; j < h; j++)
            {
                ret[i, j] = '#';
                ret[i, j + h] = '.';
            }

            for (var i = 1; i < h - 1; i += 2)
            for (var j = 1; j < h - 1; j += 2)
            {
                A--;
                B--;
                if (A > 0) ret[i, j] = '.';
                if (B > 0) ret[i, j + h] = '#';
            }

            sw.WriteLine($"{h} {w}");
            for (var i = 0; i < h; i++)
            {
                for (var j = 0; j < w; j++) sw.Write(ret[i, j]);
                sw.WriteLine();
            }
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