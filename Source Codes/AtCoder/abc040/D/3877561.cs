using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.D_Challenge
{
    class ABC_040
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int[] nm = ReadInts();
            var abys = new int[nm[1]][];
            for(int i = 0; i < nm[1]; i++)
            {
                abys[i] = ReadInts();
            }
            int q = ReadInt();
            var vws = new int[q][];
            for(int i = 0; i < q; i++)
            {
                int[] vw = ReadInts();
                vws[i] = new int[3] { vw[0], vw[1], i };
            }
            var tree = new int[nm[0]][];
            var rank = new int[nm[0]];
            for(int i = 0; i < nm[0]; i++)
            {
                tree[i] = new int[2] { i, 1 };
            }
            Array.Sort(abys, (a, b) => b[2] - a[2]);
            Array.Sort(vws, (a, b) => b[1] - a[1]);
            int rI = 0;
            var res = new int[q];
            for(int i = 0; i < q; i++)
            {
                for(;rI<nm[1]&& abys[rI][2] > vws[i][1]; rI++)
                {
                    Unite(ref tree, ref rank,
                        abys[rI][0] - 1, abys[rI][1] - 1);
                }
                //Console.WriteLine(rI);
                res[vws[i][2]] = tree[Root(ref tree, vws[i][0] - 1)][1];
            }

            for(int i =0; i < q; i++)
            {
                Console.WriteLine(res[i]);
            }
        }

        static int Root(ref int[][] tree, int x)
        {
            int rx = x;
            while (tree[rx][0] != rx)
            {
                rx = tree[rx][0];
            }
            tree[x][0] = rx;
            return rx;
        }

        static bool IsSame(ref int[][] tree, int x, int y)
        {
            return Root(ref tree, x)
                == Root(ref tree, y);
        }

        static void Unite(ref int[][] tree, ref int[] rank,
            int x, int y)
        {
            int rx = Root(ref tree, x);
            int ry = Root(ref tree, y);
            if (rx == ry) return;
            if (rank[rx] < rank[ry])
            {
                int temp = rx;
                rx = ry;
                ry = temp;
            }
            if (rank[rx] == rank[ry])
            {
                rank[rx]++;
            }
            tree[ry][0] = rx;
            tree[rx][1] += tree[ry][1];
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