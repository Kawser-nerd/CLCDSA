using System;
using System.IO;
using System.Collections.Generic;

namespace ABC119A
{
    public partial class Program
    {
        void Solve(StreamScanner ss, StreamWriter sw)
        {
            //---------------------------------
            var S = ss.Next(DateTime.Parse);
            sw.WriteLine(S <= new DateTime(2019, 4, 30) ? "Heisei" : "TBD");
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