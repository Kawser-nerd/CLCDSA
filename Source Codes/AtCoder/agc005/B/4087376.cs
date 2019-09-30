using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.AGC_Challenge
{
    class _005_B
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int n = ReadInt();
            int[] array = ReadInts();
            var indexes = new int[n];
            var tree = new int[n];
            var size = new int[n];
            for (int i = 0; i < n; i++)
            {
                indexes[array[i] - 1] = i;
                tree[i] = -1;
                size[i] = 1;
            }

            long res = 0;
            for(long i = n - 1; i >= 0; i--)
            {
                int index = indexes[i];
                tree[index] = index;
                if (index < n - 1 && tree[index + 1] >= 0)
                    Unite(ref tree, ref size, index, index + 1);
                long r = size[index];
                if (index > 0 && tree[index - 1] >= 0)
                    Unite(ref tree, ref size, index, index - 1);
                long l = size[Root(ref tree, index)] - r + 1;
                //Console.WriteLine(l + " " + r);
                res += (i + 1) * l * r;
            }
            Console.WriteLine(res);
        }

        static int Root(ref int[] tree, int x)
        {
            int rx = x;
            while (tree[rx] != rx)
            {
                rx = tree[rx];
            }
            tree[x] = rx;
            return rx;
        }

        static bool IsSame(ref int[] tree, int x, int y)
        {
            return Root(ref tree, x)
                == Root(ref tree, y);
        }

        static void Unite(ref int[] tree,ref int[] size,
            int x, int y)
        {
            int rx = Root(ref tree, x);
            int ry = Root(ref tree, y);
            if (rx == ry) return;
            if (rx> ry)
            {
                int temp = rx;
                rx = ry;
                ry = temp;
            }
            tree[ry] = rx;
            size[rx] += size[ry];
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