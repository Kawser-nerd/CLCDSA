using System;
using System.Collections.Generic;
using System.Linq;

namespace test
{
    class Program
    {
        static void Main(string[] args)
        {
            var input = ReadArrayInt();
            var N = input[0];
            var M = input[1];
            var R = input[2];
            var r = ReadArrayInt();
            var roads = new long[N + 1, N + 1];
            for (int i = 0; i < N + 1; i++) for (int j = 0; j < N + 1; j++) if (!(i == j)) roads[i, j] = int.MaxValue;
            for (int i = 0; i < M; i++)
            {
                input = ReadArrayInt();
                roads[input[0], input[1]] = input[2];
                roads[input[1], input[0]] = input[2];
            }
            for (int i = 1; i < N + 1; i++)
            {
                for (int j = 1; j < N + 1; j++)
                {
                    for (int k = 1; k < N + 1; k++)
                    {
                        roads[j, k] = Math.Min(roads[j, k], roads[j, i] + roads[i, k]);
                    }
                }
            }

            var pl = new PermList(R);
            var list = pl.List();
            var ans = long.MaxValue;

            for (int i = 0; i < pl.Idx(); i++)
            {
                var tmp = 0L;
                for (int j = 0; j < R - 1; j++)
                {
                    tmp += roads[r[list[i, j]], r[list[i, j + 1]]];
                }
                if (tmp < ans) ans = tmp;
            }

            Console.WriteLine(ans);
            Console.ReadLine();
        }

        static string Read() { return Console.ReadLine(); }
        static int ReadInt() { return int.Parse(Read()); }
        static long ReadLong() { return long.Parse(Read()); }
        static int[] ReadArrayInt() { return Read().Split(' ').Select(s => int.Parse(s)).ToArray(); }
        static long[] ReadArrayLong() { return Read().Split(' ').Select(s => long.Parse(s)).ToArray(); }
    }

    class PermList
    {
        int[,] list;
        int num;
        int idx = 0;

        public PermList(int num)
        {
            list = new int[Factorial(num), num];
            this.num = num;
            for (int i = 0; i < num; i++)
            {
                int[] pat = new int[num];
                pat[0] = i;
                bool[] used = new bool[num];
                used[i] = true;
                int cnt = 1;
                Perm(pat, used, cnt);
            }
        }

        void Perm(int[] pat, bool[] used, int cnt)
        {
            for (int i = 0; i < num; i++)
            {
                if (used[i]) continue;
                pat[cnt] = i;
                used[i] = true;
                cnt++;                
                if (cnt == num) {
                    for (int j = 0; j < num; j++) list[idx, j] = pat[j];
                    idx++;
                }
                else Perm(pat, used, cnt);
                used[i] = false;
                cnt--;
            }
        }

        public int[,] List() { return list; }
        public int Idx() { return idx; }

        int Factorial(int num) { if (num == 0) return 1; return num * Factorial(num - 1); }
    }
}