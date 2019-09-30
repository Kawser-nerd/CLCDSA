using System;
using System.IO;
using System.Collections.Generic;

namespace AGC032B
{
    public partial class Program
    {
        void Solve(StreamScanner ss, StreamWriter sw)
        {
            //---------------------------------
            var N = ss.Next(int.Parse);
            var sub = N + 1 - N % 2;
            var res = new List<string>();

            for (var i = 1; i < N; i++)
            for (var j = i + 1; j <= N; j++)
            {
                if (i + j == sub) continue;
                res.Add($"{i} {j}");
            }

            sw.WriteLine(res.Count);
            sw.WriteLine(string.Join("\n", res));
            //---------------------------------
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