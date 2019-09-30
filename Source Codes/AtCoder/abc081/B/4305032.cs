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
            new Program().Solve(new ConsoleInput(Console.In,' '));
        }

        public void Solve(ConsoleInput cin)
        {
            var min = 30;

            var N = cin.ReadInt;
            for(int i=0;i<N;++i)
            {
                var A = cin.ReadInt;
                var c = 0;
                //??????????1bit????????
                while(A%2==0 && A!=0){A >>= 1; ++c;}

                //??????
                min = Min(min,c);
            }
            WriteLine(min);
        }
    }

    public class ConsoleInput
    {
        private readonly System.IO.TextReader _stream;
        private char _separator = ' ';
        private Queue<string> inputStream;
        public ConsoleInput(System.IO.TextReader stream,char separator = ' ')
        {
            this._separator = separator;
            this._stream = stream;
            inputStream = new Queue<string>();
        }

        public string Read
        {
            get
            {
                if(inputStream.Count != 0) return inputStream.Dequeue();
                string[] tmp = _stream.ReadLine().Split(_separator);
                for(int i = 0;i < tmp.Length;i++)
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
    }

}