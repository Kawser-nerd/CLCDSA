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
            var R = cin.ReadInt();
            var C = cin.ReadInt();
            var K = cin.ReadInt();
            var s = cin.ReadStrArray(R);
            var b = new int[R, C];
            for (int c = 0; c < C; ++c)
            {
                var i = 0;
                for (int r = 0; r < R; ++r)
                {
                    if (s[r][c] != 'x') i++;
                    else i = 0;
                    b[r, c] = i;
                }
                i = 0;
                for (int r = R - 1; r >= 0; --r)
                {
                    if (s[r][c] != 'x') i++;
                    else i = 0;
                    b[r, c] = Min(i, b[r, c]);
                }
            }

            /*
            for (int r = 0; r < R; ++r)
            {
                for (int c = 0; c < C; ++c)
                {
                    Write($"{b[r, c]} ");
                }
                WriteLine();
            }
            */

            var cnt = 0;
            for (int r = K - 1; r < R - K + 1; ++r)
            {
                for (int c = K - 1; c < C - K + 1; ++c)
                {
                    var flag = true;
                    for (int k = -K + 1; k < K; ++k)
                    {
                        var nx = c + k;
                        if (nx < 0 || nx >= C) { flag = false; break; }
                        if (K - Math.Abs(k) > b[r, nx]) { flag = false; break; }
                    }
                    if (flag) { Error.WriteLine($"({c}, {r})"); cnt++; }
                }
            }
            WriteLine(cnt);
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