using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

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
            return Array().Select(int.Parse).ToArray();
        }
        public long[] LongArray()
        {
            return Array().Select(long.Parse).ToArray();
        }
    }

    class Program
    {
        private int N, K;
        private int[] X, Y;
        private void Scan()
        {
            var sc = new Scanner();
            N = sc.NextInt();
            K = sc.NextInt();
            X = new int[N];
            Y = new int[N];
            for (int i = 0; i < N; i++)
            {
                int x = sc.NextInt();
                int y = sc.NextInt();
                string c = sc.Next();
                if (c == "W")
                {
                    x += K;
                }
                x %= 2 * K;
                y %= 2 * K;
                X[i] = x;
                Y[i] = y;
            }
        }

        public void Solve()
        {
            Scan();
            var imos = new int[3 * K + 1, 3 * K + 1];
            for (int i = 0; i < N; i++)
            {
                imos[2 * K - X[i], 2 * K - Y[i]]++;
                imos[2 * K - X[i], 3 * K - Y[i]]--;
                imos[3 * K - X[i], 2 * K - Y[i]]--;
                imos[3 * K - X[i], 3 * K - Y[i]]++;
            }

            for (int i = 0; i <= 3 * K; i++)
            {
                for (int j = 1; j <= 3 * K; j++)
                {
                    imos[i, j] += imos[i, j - 1];
                }
            }
            for (int i = 1; i <= 3 * K; i++)
            {
                for (int j = 0; j <= 3 * K; j++)
                {
                    imos[i, j] += imos[i - 1, j];
                }
            }

            var ans = new int[2 * K, 2 * K];
            for (int i = 0; i < 3 * K; i++)
            {
                for (int j = 0; j < 3 * K; j++)
                {
                    ans[i % (2 * K), j % (2 * K)] += imos[i, j];
                }
            }

            int max = 0;
            for (int i = 0; i < K; i++)
            {
                for (int j = 0; j < 2 * K; j++)
                {
                    int p = 0;
                    p += ans[i, j];
                    p += ans[i + K, (j + K) % (2 * K)];
                    max = Math.Max(p, max);
                }
            }
            Console.WriteLine(max);
        }

        static void Main(string[] args)
        {
            new Program().Solve();
        }
    }
}