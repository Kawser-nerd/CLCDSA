using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Contest
{
    class Scanner
    {
        private string[] line = new string[0];
        private int index = 0;
        public string Next()
        {
            if (line.Length <= index)
            {
                line = Console.ReadLine().Split(' ');
                index = 0;
            }
            var res = line[index];
            index++;
            return res;
        }
        public int NextInt()
        {
            return int.Parse(Next());
        }
        public long NextLong()
        {
            return long.Parse(Next());
        }
        public string[] Array()
        {
            line = Console.ReadLine().Split(' ');
            index = line.Length;
            return line;
        }
        public int[] IntArray()
        {
            var array = Array();
            var result = new int[array.Length];
            for (int i = 0; i < array.Length; i++)
            {
                result[i] = int.Parse(array[i]);
            }

            return result;
        }
        public long[] LongArray()
        {
            var array = Array();
            var result = new long[array.Length];
            for (int i = 0; i < array.Length; i++)
            {
                result[i] = long.Parse(array[i]);
            }

            return result;
        }
    }

    struct S
    {
        public int X, Y;
    }

    class Program
    {
        private int N, M, Q;
        private int[] p, q;

        private long[,] Sum;

        private void Scan()
        {
            var sc = new Scanner();
            N = sc.NextInt();
            M = sc.NextInt();
            Q = sc.NextInt();
            Sum = new long[N + 1, N + 1];
            p = new int[Q];
            q = new int[Q];
            for (int i = 0; i < M; i++)
            {
                int l = sc.NextInt();
                int r = sc.NextInt();
                Sum[l, r]++;
            }

            for (int i = 0; i < Q; i++)
            {
                p[i] = sc.NextInt();
                q[i] = sc.NextInt();
            }
        }

        public void Solve()
        {
            Scan();
            for (int i = 1; i <= N; i++)
            {
                long line = 0;
                for (int j = 1; j <= N; j++)
                {
                    line += Sum[i, j];
                    Sum[i, j] = Sum[i - 1, j] + line;
                }
            }
            var sb = new StringBuilder();
            for (int i = 0; i < Q; i++)
            {
                int pp = p[i];
                int qq = q[i];
                long a = Sum[qq, qq];
                long b = Sum[pp - 1, qq];
                long c = Sum[qq, pp - 1];
                long d = Sum[pp - 1, pp - 1];
                sb.AppendLine((a - b - c + d).ToString());

            }
            Console.Write(sb.ToString());
        }

        static void Main() => new Program().Solve();
    }
}