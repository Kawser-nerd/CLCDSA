using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.D_Challenge
{
    class ABC_013
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int[] nmd = ReadInts();
            int n = nmd[0];
            int m = nmd[1];
            int d = nmd[2];
            if (m == 0)
            {
                for(int i = 0; i < n; i++)
                {
                    Console.WriteLine(i + 1);
                }
                return;
            }

            int[] array = ReadInts();

            var poses = new int[n];
            for(int i = 0; i < n; i++)
            {
                poses[i] = i;
            }
            for(int i = 0; i < m; i++)
            {
                int index = array[i] - 1;
                int temp = poses[index];
                poses[index] = poses[index + 1];
                poses[index + 1] = temp;
            }

            var setDict = new Dictionary<int, int>();
            for(int i = 0; i < n; i++)
            {
                setDict.Add(poses[i], i);
            }

            var dict = new Dictionary<int, int[]>();
            var list = new List<List<int>>();
            for(int i = 0; i < n; i++)
            {
                if (dict.ContainsKey(i)) continue;

                list.Add(new List<int>());
                list[list.Count - 1].Add(i);
                dict.Add(i, new int[2] { list.Count - 1, 0 });

                int now = setDict[i];
                while (now != i)
                {
                    list[list.Count - 1].Add(now);
                    dict.Add(now, new int[2]
                    { list.Count - 1, list[list.Count - 1].Count - 1 });
                    now = setDict[now];
                }
            }

            for(int i = 0; i < n; i++)
            {
                List<int> nowList = list[dict[i][0]];
                int len = d % nowList.Count;
                Console.WriteLine(
                    nowList[(dict[i][1] + len) % nowList.Count] + 1);
            }

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