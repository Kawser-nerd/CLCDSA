using System;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Linq;

namespace B
{
    public class Program
    {
        public static void Main(string[] args)
        {
            new Program().Solve(new Input(Console.In));
        }

        void Solve(Input cin)
        {
            var H = cin.ReadInt;
            var W = cin.ReadInt;
            var S = cin.ReadStrArray(H).Select(x => x.ToCharArray()).ToArray();

            for (var top = 0; top < H; top++)
            {
                for (var left = 0; left < W; left++)
                {
                    if (S[top][left] != '.') continue;
                    var count = 0;

                    bool left_ok = left != 0, right_ok = left != W - 1;

                    if (top - 1 >= 0)
                    {
                        if (left_ok && S[top - 1][left - 1] == '#') count++;
                        if (S[top - 1][left] == '#') count++;
                        if (right_ok && S[top - 1][left + 1] == '#') count++;
                    }

                    if (left_ok && S[top][left - 1] == '#') count++;
                    if (right_ok && S[top][left + 1] == '#') count++;

                    if (top + 1 < H)
                    {
                        if (left_ok && S[top + 1][left - 1] == '#') count++;
                        if (S[top + 1][left] == '#') count++;
                        if (right_ok && S[top + 1][left + 1] == '#') count++;
                    }

                    S[top][left] = count.ToString()[0];
                }
            }

            foreach (var array in S) {
                Console.WriteLine(new string(array));
            }
        }

        

    }
    public class Input

    {
        private readonly System.IO.TextReader _stream;
        private readonly char _separator;
        private readonly Queue<string> _input;

        public Input(System.IO.TextReader reader, char separator = ' ')
        {
            this._separator = separator;
            this._stream = reader;
            this._input = new Queue<string>();
        }

        public string Read
        {
            get {
                if (this._input.Count != 0) return this._input.Dequeue();

                // ReSharper disable once PossibleNullReferenceException
                var tmp = this._stream.ReadLine().Split(this._separator);
                foreach (var val in tmp) {
                    this._input.Enqueue(val);
                }

                return this._input.Dequeue();
            }
        }

        public string ReadLine => _stream.ReadLine();

        public int ReadInt => int.Parse(Read);

        public long ReadLong => long.Parse(Read);

        public double ReadDouble => double.Parse(Read);

        public string[] ReadStrArray(long n)
        {
            var ret = new string[n];
            for (long i = 0; i < n; ++i) ret[i] = Read;
            return ret;
        }

        public int[] ReadIntArray(long n)
        {
            var ret = new int[n];
            for (long i = 0; i < n; ++i) ret[i] = ReadInt;
            return ret;
        }

        public long[] ReadLongArray(long n)
        {
            var ret = new long[n];
            for (long i = 0; i < n; ++i) ret[i] = ReadLong;
            return ret;
        }
    }
}