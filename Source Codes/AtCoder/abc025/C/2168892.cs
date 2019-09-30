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
            new Program().Solve(new MyInputStream(Console.In, ' '));
            Console.Out.Flush();
        }

        public void Solve(MyInputStream cin)
        {
            var sum = 0;
            var b = new int[2, 3];
            for (int i = 0; i < 2; ++i)
                for (int j = 0; j < 3; ++j)
                    sum += b[i, j] = cin.ReadInt;

            var c = new int[3, 2];
            for (int i = 0; i < 3; ++i)
                for (int j = 0; j < 2; ++j)
                    sum += c[i, j] = cin.ReadInt;

            var map = new int[3, 3];

            Func<int> Eval = () => {
                var score = 0;
                for (int i = 0; i < 2; ++i)
                    for (int j = 0; j < 3; ++j)
                        if (map[i, j] == map[i + 1, j]) score += b[i, j];
                        else score -= b[i, j];
                for (int i = 0; i < 3; ++i)
                    for (int j = 0; j < 2; ++j)
                        if (map[i, j] == map[i, j + 1]) score += c[i, j];
                        else score -= c[i, j];
                return score;
            };

            Func<int, int> func = null;
            func = (int n) => {
                if (n == 9) return Eval();
                var ret = int.MinValue;
                for (int i = 0; i < 3; ++i)
                    for (int j = 0; j < 3; ++j)
                        if (map[i, j] == 0)
                        {
                            map[i, j] = n % 2 + 1;
                            ret = Max(func(n + 1) * (n % 2 == 0 ? 1 : -1), ret);
                            map[i, j] = 0;
                        }
                return ret * (n % 2 == 0 ? 1 : -1);
            };

            var ans = func(0);
            WriteLine((sum + ans) >> 1);
            WriteLine((sum - ans) >> 1);
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
        public string Read
        {
            get
            {
                if (inputStream.Count != 0) return inputStream.Dequeue();
                string[] tmp = _stream.ReadLine().Split(separator);
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