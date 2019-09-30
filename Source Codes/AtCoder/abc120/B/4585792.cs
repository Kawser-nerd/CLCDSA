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
        }
        
        public int gcd(int a, int b)
        {
            if (a == b) return a;
            else
            {
                return gcd(Abs(a - b), Min(a, b));
            }
        }
        public SortedSet<int> Frac_(int t)
        {
            var s = new SortedSet<int>();
            for (int i = 1; i <= Sqrt(t); i++)
            {
                if((t % i) == 0)
                {
                    s.Add(i);
                    s.Add(t / i);
                }
            }
            return s;
        }
        public void Solve(ConsoleInput cin)
        {
            var a = cin.ReadIntArray(3);
            var g = gcd(a[0], a[1]);
            var s = Frac_(g).Reverse();
            int i = 0;
            foreach (var item in s)
            {
                i++;
                if (i == a[2])
                {
                    Console.WriteLine(item);
                    return;
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
        public string ReadLine { get { return _stream.ReadLine(); } }
        public int ReadInt { get { return int.Parse(Read); } }
        public long ReadLong { get { return long.Parse(Read); } }
        public double ReadDouble { get { return double.Parse(Read); } }
        public string[] ReadStrArray(long N) { var ret = new string[N]; for (long i = 0; i < N; ++i) ret[i] = Read; return ret; }
        public int[] ReadIntArray(long N) { var ret = new int[N]; for (long i = 0; i < N; ++i) ret[i] = ReadInt; return ret; }
        public long[] ReadLongArray(long N) { var ret = new long[N]; for (long i = 0; i < N; ++i) ret[i] = ReadLong; return ret; }
        public double[] ReadDoubleArray(long N) { var ret = new double[N]; for (long i = 0; i < N; ++i) ret[i] = ReadDouble; return ret; }
    }
}