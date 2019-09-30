using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;
using static System.Math;

namespace atcoder
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length > 0 && args[0] == "Debug")
            {
                while (true)
                    new Program().Solve(new ConsoleInput(In));
            }
            else new Program().Solve(new ConsoleInput(In));
        }

        public void Solve(ConsoleInput input)
        {
            var a = input.ReadLong;
            var b = input.ReadLong;

            WriteLine($"{F(a - 1) ^ F(b)}");
        }

        private long F(long n)
        {
            if (n % 2 == 0) return ((n + 1) / 2 % 2) ^ n;
            else return ((n + 1) / 2 % 2);
        }
    }

    class Math
    {
        public static int Min(params int[] a)
        {
            if (a.Length == 0) return 0;

            var min = a[0];
            for (int i = 1; i < a.Length; i++)
            {
                if (min > a[i]) min = a[i];
            }
            return min;
        }

        public static int Max(params int[] a)
        {
            if (a.Length == 0) return 0;

            int max = a[0];
            for (int i = 1; i < a.Length; i++)
            {
                if (max < a[i]) max = a[i];
            }
            return max;
        }

        public static int Lcm(int a, int b)
        {
            return a * b / Gcd(a, b);
        }

        public static int Gcd(int a, int b)
        {
            if (a < b)
                return Gcd(b, a);
            while (b != 0)
            {
                var remainder = a % b;
                a = b;
                b = remainder;
            }
            return a;
        }
    }

    class UnionFind
    {
        private int[] parent;
        private int[] rank;
        private long[] size;

        public UnionFind(int count)
        {
            parent = new int[count];
            rank = new int[count];
            size = new long[count];
            for (var i = 0; i < count; i++)
            {
                parent[i] = i;
                rank[i] = 0;
                size[i] = 1;
            }
        }

        public int Root(int x)
        {
            if (parent[x] != x)
            {
                parent[x] = Root(parent[x]);
            }
            return parent[x];
        }

        public void Unite(int a, int b)
        {
            var ra = Root(a);
            var rb = Root(b);

            if (Size(ra) < Size(rb))
            {
                parent[ra] = rb;
                size[rb] += size[ra];
            }
            else
            {
                parent[rb] = ra;
                size[ra] += size[rb];
            }
            if (rank[ra] == rank[rb]) rank[ra]++;
        }

        public bool Same(int a, int b)
        {
            return Root(a) == Root(b);
        }

        public long Size(int x)
        {
            return size[Root(x)];
        }
    }

    class ConsoleInput
    {
        private readonly System.IO.TextReader _stream;
        private readonly char _separator;
        private Queue<string> inputStream;
        public ConsoleInput(System.IO.TextReader stream, char separator = ' ')
        {
            _separator = separator;
            _stream = stream;
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