using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.D_Challenge
{
    class ABC_037
    {
        static int[,] mapInfo;
        static long[,] patterns;

        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int[] hw = ReadInts();
            mapInfo = new int[hw[0], hw[1]];
            patterns = new long[hw[0], hw[1]];
            for(int i = 0; i < hw[0]; i++)
            {
                int[] array = ReadInts();
                for(int j = 0; j < hw[1]; j++)
                {
                    mapInfo[i, j] = array[j];
                }
            }

            long res = 0;
            for(int i = 0; i < hw[0]; i++)
            {
                for(int j = 0; j < hw[1]; j++)
                {
                    long cnt= DFS(j,i, 0);
                    res += cnt;
                    //Console.Write(cnt + " ");
                    res %= 1000000000 + 7;
                }
                //Console.WriteLine();
            }

            Console.WriteLine(res);
        }

        static long DFS(int x, int y, int cost)
        {
            if (x < 0 || mapInfo.GetLength(1) <= x
                || y < 0 || mapInfo.GetLength(0) <= y) return 0;
            if (cost >= mapInfo[y, x]) return 0;

            if (patterns[y, x] > 0) return patterns[y, x];

            patterns[y, x] = 1;

            patterns[y, x] += DFS(x + 1, y, mapInfo[y, x]);
            patterns[y, x] += DFS(x, y + 1, mapInfo[y, x]);
            patterns[y, x] += DFS(x - 1, y, mapInfo[y, x]);
            patterns[y, x] += DFS(x, y - 1, mapInfo[y, x]);

            patterns[y, x] %= 1000000000 + 7;
            return patterns[y, x];
        }

        private static string Read() { return Console.ReadLine(); }
        private static int ReadInt() { return int.Parse(Read()); }
        private static long ReadLong() { return long.Parse(Read()); }
        private static double ReadDouble() { return double.Parse(Read()); }
        private static int[] ReadInts() { return Array.ConvertAll(Read().Split(), int.Parse); }
        private static long[] ReadLongs() { return Array.ConvertAll(Read().Split(), long.Parse); }
        private static double[] ReadDoubles() { return Array.ConvertAll(Read().Split(), double.Parse); }
    }
}