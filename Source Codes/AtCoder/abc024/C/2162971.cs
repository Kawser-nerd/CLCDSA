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
            var N = cin.ReadInt();
            var D = cin.ReadInt();
            var K = cin.ReadInt();
            int[] L, R, S, T;
            cin.ReadIntArrays(D, out L, out R);
            cin.ReadIntArrays(K, out S, out T);

            for (int i = 0; i < K; ++i)
            {
                int pos = S[i];
                int j;
                for (j = 0; j < D; ++j)
                {
                    if (L[j] <= pos && pos <= R[j] && L[j] <= T[i] && T[i] <= R[j]) break;
                    else if (L[j] <= pos && pos <= R[j])
                    {
                        if (T[i] < pos) pos = L[j];
                        else pos = R[j];
                    }
                }
                WriteLine(j + 1);
            }
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
        public void ReadIntArrays(long N, out int[] A, out int[] B) { A = new int[N]; B = new int[N]; for (long i = 0; i < N; ++i) { A[i] = ReadInt(); B[i] = ReadInt(); }}
    }
}