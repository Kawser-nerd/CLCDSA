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
        private int N, M;
        private int[] A;
        private void Scan()
        {
            var sc = new Scanner();
            N = sc.NextInt();
            M = sc.NextInt();
            A = sc.IntArray();
        }

        public void Solve()
        {
            Scan();
            var sum = new int[N + 1];
            for (int i = 0; i < N; i++)
            {
                sum[i + 1] = sum[i] + A[i];
                sum[i + 1] %= M;
            }

            Dictionary<int, long> cnt = new Dictionary<int, long>();
            foreach (int i in sum)
            {
                long o;
                cnt.TryGetValue(i, out o);
                cnt[i] = o + 1;
            }

            long ans = 0;
            foreach (var i in cnt.Values)
            {
                ans += i * (i - 1) / 2;
            }
            Console.WriteLine(ans);
        }

        static void Main() => new Program().Solve();
    }
}