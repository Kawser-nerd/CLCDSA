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

            return;
        }

        public void Solve(ConsoleInput cin)
        {

            var N = cin.ReadInt;
            var M = cin.ReadInt;

            char[, ] A = new char[N, N];
            char[, ] B = new char[M, M];

            for (int i = 0; i < N; i++){
                var readRow = cin.ReadLine.ToCharArray();
                for (int j = 0; j < N; j++){
                    A[i, j] = readRow[j];
                }
            }

            for (int i = 0; i < M; i++){
                var readRow = cin.ReadLine.ToCharArray();
                for (int j = 0; j < M; j++){
                    B[i, j] = readRow[j];
                }
            }

            bool ans = false;
            var widthRange = N - M + 1;
            var heightRange = N - M + 1;
            for (int i = 0; i < widthRange; i++){
                for (int j = 0; j < heightRange; j++){
                    for (int k = 0; k < M; k++){
                        for (int l = 0; l < M; l++){
                            if(A[k + i, l + j] != B[k, l]){
                                goto LOOPEND;
                            }
                        }
                    }
                    ans = true;
                    LOOPEND:;
                }
            }

            if(ans){
                WriteLine("Yes");
            }else{
                WriteLine("No");
            }

        }
    }

    public static class Extensions
    {
        public static string Reverse(this string sourse)
        {
            char[] chrAry = sourse.ToCharArray();
            Array.Reverse(chrAry);
            return new string(chrAry);
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
    }
}