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

    class Program
    {
        private int N, K;

        private void Scan()
        {
            var sc = new Scanner();
            N = sc.NextInt();
            K = sc.NextInt();
        }

        public void Solve()
        {
            Scan();
            long ans = 0;
            for (int b = K + 1; b <= N; b++)
            {
                int n = N / b;
                int plus = 0;
                plus += n * (b - K);
                if (N % b != 0)
                {
                    if (K == 0)
                    {
                        plus += N % b;
                    }
                    else
                    {
                        plus += Math.Max(N % b - K + 1, 0);
                    }
                }

                //Console.WriteLine($"{b} {plus}");
                ans += plus;
            }
            Console.WriteLine(ans);
        }

        static void Main() => new Program().Solve();
    }
}