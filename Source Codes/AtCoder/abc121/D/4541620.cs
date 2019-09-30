using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using static System.Math;

namespace ABC121D_2
{
    public partial class Program
    {
        void Solve(StreamScanner ss, StreamWriter sw)
        {
            //---------------------------------
            var A = ss.Next(long.Parse);
            var B = ss.Next(long.Parse);
            sw.WriteLine(F(A - 1) ^ F(B));
            //---------------------------------
        }

        long F(long n)
        {
            var ret = 0L;

            if (n % 4 == 1 || n % 4 == 2) ret++;

            for (var i = 1; i < 50; i++)
            {
                var pot = 1L << i;
                var pos = (n + 1) % (pot << 1);
                if (pos < pot || pos % 2 == 0) continue;
                ret += pot;
            }

            return ret;
        }
    }

    public class StreamScanner
    {
        static readonly char[] Separator = {' '};
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