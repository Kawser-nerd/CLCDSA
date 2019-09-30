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
            new Program().Solve(new ConsoleInput(Console.In, ' '));
            Console.ReadLine();
        }

        public void Solve(ConsoleInput cin)
        {
            long a = cin.ReadLong;
            long b = cin.ReadLong;
            long x = cin.ReadLong;

            long m = a == 0 ? -1 : (a - 1) / x;
            long sum = (b / x) - m ;

            Console.WriteLine(sum);
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
        public string ReadLine { get { return _stream.ReadLine(); } }
        public int ReadInt { get { return int.Parse(Read); } }
        public long ReadLong { get { return long.Parse(Read); } }
        public double ReadDouble { get { return double.Parse(Read); } }
        public string[] ReadStrArray(long num) { var ret = new string[num]; for (long i = 0; i < num; ++i) ret[i] = Read; return ret; }
        public int[] ReadIntArray(long num) { var ret = new int[num]; for (long i = 0; i < num; ++i) ret[i] = ReadInt; return ret; }
        public long[] ReadLongArray(long num) { var ret = new long[num]; for (long i = 0; i < num; ++i) ret[i] = ReadLong; return ret; }
    }
}