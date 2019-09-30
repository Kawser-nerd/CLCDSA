using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.D_Challenge
{
    class ABC_089
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int[] hwd = ReadInts();
            var grid = new int[hwd[0]][];
            var posList = new List<int[]>();
            for(int i = 0; i < hwd[0]; i++)
            {
                grid[i] = ReadInts();
                for (int j = 0; j < hwd[1]; j++)
                {
                    posList.Add(new int[3] { grid[i][j], i, j });
                }
            }
            posList.Sort((a, b) => a[0] - b[0]);
            var costGrid = new int[hwd[0], hwd[1]];
            for(int i=0;i<posList.Count;i++)
            {
                int prevIndex = i - hwd[2];
                if (prevIndex < 0)
                {
                    costGrid[posList[i][1], posList[i][2]] = 0;
                }
                else
                {
                    int[] pos = posList[i];
                    int[] prevPos = posList[prevIndex];
                    costGrid[pos[1], pos[2]]
                        = costGrid[prevPos[1], prevPos[2]];
                    costGrid[pos[1], pos[2]]
                        += Math.Abs(pos[1] - prevPos[1])
                        + Math.Abs(pos[2] - prevPos[2]);
                }
            }

            int q = ReadInt();
            var lrs = new int[q][];
            for(int i = 0; i < q; i++)
            {
                lrs[i] = ReadInts();
            }
            for(int i = 0; i < q; i++)
            {
                int l = lrs[i][0];
                int r = lrs[i][1];
                int cost
                    = costGrid[posList[r - 1][1], posList[r - 1][2]]
                    - costGrid[posList[l - 1][1], posList[l - 1][2]];
                Console.WriteLine(cost);
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