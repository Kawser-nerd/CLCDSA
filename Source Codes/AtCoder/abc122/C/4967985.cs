using System;
using System.Text;
using System.Linq;
using System.Collections;
using System.Collections.Generic;
using static System.Console;
using static System.Math;
using System.IO;

namespace AtCoder
{
    public class Program
    {
        public static void Main(string[] args)
        {
            var sw = new StreamWriter(Console.OpenStandardOutput()){AutoFlush = false};
            Console.SetOut(sw);
            new Program().Solve(new ConsoleInput(Console.In, ' '));
            Console.Out.Flush();
        }

        public void Solve(ConsoleInput cin)
        {
            // ????????
            var n = cin.ReadInt;
            var q = cin.ReadInt;
            var s = cin.Read;
            var counts = new List<int>();
            counts.Add(0);
            var sumval = 0;

            for (var i = 0; i < s.Length-1; i++) {
                if (s[i].ToString() == "A" && s[i+1].ToString() == "C") {
                    sumval++;
                } 
                counts.Add(sumval);
            }
            
            for (var i = 0; i < q; i++) {
                var l = cin.ReadInt;
                var r = cin.ReadInt;
                var ans = counts[r-1]-counts[l-1];
                WriteLine(ans);
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
        public string ReadLine { get { return _stream.ReadLine(); }}
        public int ReadInt { get { return int.Parse(Read); }}
        public long ReadLong { get { return long.Parse(Read); }}
        public double ReadDouble { get { return double.Parse(Read); }}
        public string[] ReadStrArray(long N) { var ret = new string[N]; for (long i = 0; i < N; ++i) ret[i] = Read; return ret;}
        public int[] ReadIntArray(long N) { var ret = new int[N]; for (long i = 0; i < N; ++i) ret[i] = ReadInt; return ret;}
        public long[] ReadLongArray(long N) { var ret = new long[N]; for (long i = 0; i < N; ++i) ret[i] = ReadLong; return ret;}
    }
}