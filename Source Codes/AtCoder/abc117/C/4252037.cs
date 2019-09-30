using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;
using static System.Math;

namespace atcoder
{
    class Program
    {
        static void Main(string[] args)
        {
            new Program().Solve(new ConsoleInput(In));
        }

        public long Min(params long[] a)
        {
            var min = a[0];
            for (int i = 1; i < a.Length; i++)
            {
                if (min > a[i]) min = a[i];
            }
            return min;
        }

        public long Max(params long[] a)
        {
            var max = a[0];
            for (int i = 1; i < a.Length; i++)
            {
                if (max < a[i]) max = a[i];
            }
            return max;
        }

        public void Solve(ConsoleInput input)
        {
            var n = input.ReadInt;
            var m = input.ReadInt;
            var x = input.ReadIntArray(m);

            var xsorted = x.OrderBy(i => i).ToArray();
            var dx = new int[m - 1];
            for (var i = 0; i < m - 1; i++)
            {
                dx[i] = xsorted[i + 1] - xsorted[i];
            }

            WriteLine($"{dx.OrderByDescending(i => i).Skip(n - 1).Sum()}");

            //Solve(input);
        }
    }

    public class ConsoleInput
    {
        private readonly System.IO.TextReader _stream;
        private readonly char _separator = ' ';
        private Queue<string> inputStream;
        public ConsoleInput(System.IO.TextReader stream, char separator = ' ')
        {
            _separator = separator;
            _stream = stream;
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
        public string ReadLine { get { return _stream.ReadLine(); } }
        public int ReadInt { get { return int.Parse(Read); } }
        public long ReadLong { get { return long.Parse(Read); } }
        public double ReadDouble { get { return double.Parse(Read); } }
        public string[] ReadStrArray(long N) { var ret = new string[N]; for (long i = 0; i < N; ++i) ret[i] = Read; return ret; }
        public int[] ReadIntArray(long N) { var ret = new int[N]; for (long i = 0; i < N; ++i) ret[i] = ReadInt; return ret; }
        public long[] ReadLongArray(long N) { var ret = new long[N]; for (long i = 0; i < N; ++i) ret[i] = ReadLong; return ret; }
    }
}