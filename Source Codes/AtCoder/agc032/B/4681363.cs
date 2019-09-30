using System;
using System.IO;
using System.Text;

namespace Contest
{

    class Program
    {

        public void Solve()
        {
            var sc = new Scanner();
            int N = sc.NextInt();
            var b = new bool[N + 1, N + 1];
            if (N % 2 == 0)
            {
                for (int i = 1; i <= N; i++)
                {
                    b[N - i + 1, i] = true;
                }
            }
            else
            {
                for (int i = 1; i <= N - 1; i++)
                {
                    b[N - i, i] = true;
                }
            }

            var sb = new StringBuilder();
            int cnt = 0;
            for (int i = 1; i < N; i++)
            {
                for (int j = i + 1; j <= N; j++)
                {
                    if (!b[i, j])
                    {
                        sb.AppendLine($"{i} {j}");
                        cnt++;
                    }
                }
            }
            Console.WriteLine(cnt);
            Console.Write(sb.ToString());
        }

        static void Main(string[] args) => new Program().Solve();
    }

    class Scanner
    {
        private char _separator = ' ';
        private StreamReader _stream = new StreamReader(Console.OpenStandardInput());
        private int _pos = 0;
        private string[] _line = new string[0];
        public string Next()
        {
            if (_pos >= _line.Length)
            {
                _line = _stream.ReadLine().Split(_separator);
                _pos = 0;
            }
            return _line[_pos++];
        }
        public int NextInt() => int.Parse(Next());
        public long NextLong() => long.Parse(Next());
        public double NextDouble() => double.Parse(Next());
        public string[] Array()
        {
            if (_pos >= _line.Length)
                _line = _stream.ReadLine().Split(_separator);
            _pos = _line.Length;
            return _line;
        }
        public int[] IntArray()
        {
            var arr = Array();
            var res = new int[arr.Length];
            for (int i = 0; i < arr.Length; i++)
            {
                res[i] = int.Parse(arr[i]);
            }
            return res;
        }
        public long[] LongArray()
        {
            var arr = Array();
            var res = new long[arr.Length];
            for (int i = 0; i < arr.Length; i++)
            {
                res[i] = long.Parse(arr[i]);
            }
            return res;
        }
        public double[] DoubleArray()
        {
            var arr = Array();
            var res = new double[arr.Length];
            for (int i = 0; i < arr.Length; i++)
            {
                res[i] = double.Parse(arr[i]);
            }
            return res;
        }
    }
}