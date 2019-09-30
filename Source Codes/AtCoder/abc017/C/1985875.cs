using System;
using System.Text;
using System.Linq;
using System.Collections;
using System.Collections.Generic;
using static System.Console;
using static System.Math;

namespace AtCoder
{
    public class Program
    {
        public static void Main(string[] args)
        {
            var sw = new System.IO.StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false };
            Console.SetOut(sw);
            new Program().Solve(new MyInputStream(Console.In, ' '));
            Console.Out.Flush();
        }

        public void Solve(MyInputStream cin)
        {
            var N = cin.ReadInt();
            var M = cin.ReadInt();

            var total = 0;
            var imos = new long[M + 2];
            for (int i = 0; i < N; ++i)
            {
                var l = cin.ReadInt();
                var r = cin.ReadInt();
                var s = cin.ReadInt();
                imos[l] += s;
                imos[r + 1] -= s;
                total += s;
            }

            for (int i = 1; i <= M; ++i)
                imos[i] += imos[i - 1];

            var min = (long)int.MaxValue;
            for (int i = 1; i <= M; ++i)
                min = Math.Min(imos[i], min);

            WriteLine(total - min);
        }
    }

    public class MyInputStream
    {
        private readonly System.IO.TextReader _stream;
        private char separator = ' ';
        private Queue<string> inputStream;
        public MyInputStream(System.IO.TextReader s, char separator = ' ')
        {
            this.separator = separator;
            this._stream = s;
            inputStream = new Queue<string>();
        }
        public string Read()
        {
            if (inputStream.Count != 0) return inputStream.Dequeue();
            string[] tmp = _stream.ReadLine().Split(separator);
            for (int i = 0; i < tmp.Length; ++i)
                inputStream.Enqueue(tmp[i]);
            return inputStream.Dequeue();
        }
        public string ReadLine() { return _stream.ReadLine(); }
        public int ReadInt() { return int.Parse(Read()); }
        public long ReadLong() { return long.Parse(Read()); }
        public double ReadDouble() { return double.Parse(Read()); }
        public string[] ReadStrArray(long N) { var ret = new string[N]; for (long i = 0; i < N; ++i) ret[i] = Read(); return ret;}
        public int[] ReadIntArray(long N) { var ret = new int[N]; for (long i = 0; i < N; ++i) ret[i] = ReadInt(); return ret;}
        public long[] ReadLongArray(long N) { var ret = new long[N]; for (long i = 0; i < N; ++i) ret[i] = ReadLong(); return ret;}
    }
}