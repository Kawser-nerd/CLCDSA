using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace AtTest.AGC_031
{
    class C
    {
        static void Main(string[] args)
        {
            Method(args);
            ReadLine();
        }

        static void Method(string[] args)
        {
            int[] nab = ReadInts();
            int n = nab[0];
            int a = nab[1];
            int b = nab[2];
            int delta = 0;
            int div = 1;
            for(int i = 0; i < n; i++)
            {
                if ((a & div) != (b & div)) delta++;
                div *= 2;
            }
            if (delta % 2 ==0)
            {
                WriteLine("NO");
                return;
            }
            WriteLine("YES");

            int all = 1 << n;
            int[][] array = new int[all][];
            for(int i = 0; i < all; i++)
            {
                array[i] = new int[n];
                for (int j = 0; j < n; j++) array[i][j] = -1;
            }
            for(int i = 0; i < n; i++)
            {
                array[0][i] = (a & (1 << i)) > 0 ? 1 : 0;
                array[all-1][i] = (b & (1 << i)) > 0 ? 1 : 0;
            }
            DFS(ref array, 0, all - 1);
            for(int i = 0; i < all; i++)
            {
                int val = 0;
                for(int j = 0; j < n; j++)
                {
                    if (array[i][j] == 1) val += 1 << j;
                }
                Write(val);
                if (i + 1 < all) Write(" ");
            }
            WriteLine();
        }

        static void DFS(ref int[][] array,int l,int r)
        {
            if (l + 1 == r) return;

            int digit = array[l].Length;
            int mid = (l + r) / 2;
            int difI = -1;
            for(int i = 0; i < digit; i++)
            {
                if (difI == -1 && array[l][i] != array[r][i])
                {
                    difI = i;
                }
            }
            for(int i = l; i < r; i++)
            {
                if (i <= mid) array[i][difI] = array[l][difI];
                else array[i][difI] = array[r][difI];
            }
            bool changed = false;
            for (int i = 0; i < digit; i++)
            {
                if (array[mid][i] >= 0) continue;

                if (changed)
                {
                    array[mid][i] = array[l][i];
                    array[mid + 1][i] = array[l][i];
                }
                else
                {
                    array[mid][i] = array[l][i] == 0 ? 1 : 0;
                    array[mid + 1][i] = array[mid][i];
                    changed = true;
                }
            }
            DFS(ref array, l, mid);
            DFS(ref array, mid + 1, r);
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