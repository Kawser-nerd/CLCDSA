using System;


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

        public ulong NextUlong()
        {
            return ulong.Parse(Next());
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
        private int H, W, K;
        private const int Mod = (int)1e9 + 7;
        private long[,] Memo;
        void Scan()
        {
            var sc = new Scanner();
            H = sc.NextInt();
            W = sc.NextInt();
            K = sc.NextInt() - 1;
        }

        public void Solve()
        {
            Scan();
            Memo = new long[H + 1, W];
            for (int i = 0; i <= H; i++)
            {
                for (int j = 0; j < W; j++)
                {
                    Memo[i, j] = -1;
                }
            }
            Console.WriteLine(Calc(0, 0));
        }

        private long Calc(int height, int start)
        {
            if (Memo[height, start] != -1) return Memo[height, start];
            if (height == H)
            {
                return start == K ? 1 : 0;
            }
            int[] fib = new int[] { 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };
            long ans = 0;
            if (start < W - 1)
            {

                ans += Calc(height + 1, start + 1) * fib[start] * fib[W - start - 2];
                ans %= Mod;
            }

            if (start > 0)
            {
                ans += Calc(height + 1, start - 1) * fib[start - 1] * fib[W - start - 1];
                ans %= Mod;
            }

            ans += Calc(height + 1, start) * fib[W - start - 1] * fib[start];
            ans %= Mod;
            Memo[height, start] = ans;
            return ans;
        }



        static void Main() => new Program().Solve();
    }


}