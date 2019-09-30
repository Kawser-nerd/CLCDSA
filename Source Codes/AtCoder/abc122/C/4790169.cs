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

        public void Solve(ConsoleInput cin)
        {
            var FirstLine = cin.ReadLine.Split(' ');
            int N = int.Parse(FirstLine[0]);
            int Q = int.Parse(FirstLine[1]);
            var S = cin.ReadLine;
            List<int> resultList = new List<int>();

            List<int> targetSums = new List<int>();
            int len = S.Length;
            int ATcounter = 0;
            for (int i = 0; i < len; i++)
            {
                targetSums.Add(ATcounter);
                if (len - 1 == i)
                {                    
                    break;
                }
                if (S[i] == 'A' && S[i+1] == 'C')
                {
                    ++ATcounter;
                }
            }
            for (int i = 0; i <= Q - 1; i++)
            {
                var temp = cin.ReadLine.Split(' ');
                int l = int.Parse(temp[0]);
                int r = int.Parse(temp[1]);
                var tempStr = targetSums[r-1]-targetSums[l-1];

                resultList.Add(tempStr);
            }
            foreach (var result in resultList)
            {
                Console.WriteLine(result);
            }
        }
    }
    public class deci
    {
        public bool IsFinish { get; set; } = false;
        public int Len { get; set; }
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