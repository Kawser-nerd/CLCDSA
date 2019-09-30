using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.AGC_029
{
    class B
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            var tt = new int[30] {2, 4, 8, 16, 32, 64, 128, 256, 512,
1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288,
1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912,
1073741824};
            int n = ReadInt();
            int[] array = ReadInts();
            Array.Sort(array);
            var dict = new Dictionary<int, int>();
            for(int i =0; i < n; i++)
            {
                if (!dict.ContainsKey(array[i])) dict.Add(array[i], 0);
                dict[array[i]]++;
            }
            int res = 0;
            for (int j = tt.Length - 1; j >= 0; j--)
            {
                for (int i = 0; i < n; i++)
                {
                    if (!dict.ContainsKey(array[i])) continue;

                    int v = tt[j] - array[i];
                    if (v == 0) continue;

                    if (array[i] == v)
                    {
                        if (dict[v] >= 2)
                        {
                            res++;
                            if (dict[v] == 2) dict.Remove(v);
                            else dict[v] -= 2;
                        }
                    }
                    else if (dict.ContainsKey(v))
                    {
                        res++;
                        if (dict[v] == 1) dict.Remove(v);
                        else dict[v]--;
                        if (dict[array[i]] == 1) dict.Remove(array[i]);
                        else dict[array[i]]--;
                    }
                }
            }
            Console.WriteLine(res);
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