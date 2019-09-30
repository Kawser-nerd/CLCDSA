using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace AtTest.ARC_B
{
    class _027
    {
        static void Main(string[] args)
        {
            Method(args);
            ReadLine();
        }

        static void Method(string[] args)
        {
            int n = ReadInt();
            string s1 = Read();
            string s2 = Read();
            UnionFind unionFind = new UnionFind(26);
            for (int i = 0; i < n; i++)
            {
                int a = s1[i] - 'A';
                int b = s2[i] - 'A';
                if (0 <= a && a < 26 && (b < 0 || b >= 26))
                {
                    unionFind.mode[unionFind.Root(a)] = 3;
                }
                if (0 <= b && b < 26 && (a < 0 || a >= 26))
                {
                    unionFind.mode[unionFind.Root(b)] = 3;
                }
                if (0 <= a && a < 26 && 0 <= b && b < 26)
                {
                    unionFind.Unite(a, b);
                    int root = unionFind.Root(a);
                    if (i == 0)
                    {
                        unionFind.mode[root] = Max(unionFind.mode[root], 2);
                    }
                    unionFind.mode[root] = Max(unionFind.mode[root], 1);
                }
            }
            long res = 1;
            for(int i = 0; i < 26; i++)
            {
                //Write(unionFind.mode[i]);
                if (unionFind.Root(i) != i || unionFind.mode[i] == 0) continue;

                if (unionFind.mode[i] == 1) res *= 10;
                if (unionFind.mode[i] == 2) res *= 9;
            }
            //WriteLine();
            WriteLine(res);
        }

        class UnionFind
        {
            int[] tree;
            public int[] mode;

            public UnionFind(int length)
            {
                tree = new int[length];
                mode = new int[length];
                for (int i = 0; i < length; i++)
                {
                    tree[i] = i;
                    mode[i] = 0;
                }
            }            

            public int Root(int x)
            {
                int rx = x;
                while (tree[rx] != rx)
                {
                    rx = tree[rx];
                }
                tree[x] = rx;
                return rx;
            }

            public bool IsSame(int x, int y)
            {
                return Root(x) == Root(y);
            }

            public void Unite(int x, int y)
            {
                int rx = Root(x);
                int ry = Root(y);
                if (rx == ry) return;

                if (rx > ry)
                {
                    int temp = rx;
                    rx = ry;
                    ry = temp;
                }
                tree[ry] = rx;
                mode[rx] = Max(mode[rx], mode[ry]);//0: unused,any,natural,fix
            }
        }

        private static string Read() { return ReadLine(); }
        private static int ReadInt() { return int.Parse(Read()); }
        private static long ReadLong() { return long.Parse(Read()); }
        private static double ReadDouble() { return double.Parse(Read()); }
        private static int[] ReadInts() { return Array.ConvertAll(Read().Split(), int.Parse); }
        private static long[] ReadLongs() { return Array.ConvertAll(Read().Split(), long.Parse); }
        private static double[] ReadDoubles() { return Array.ConvertAll(Read().Split(), double.Parse); }
    }
}