using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.C_Challenge
{
    class ABC_064
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
            var levelWall = new int[8]
                { 400, 800, 1200, 1600, 2000, 2400, 2800, 3200 };
            var levelCnt = new int[9];
            for (int i = 0; i < n; i++)
            {
                for(int j = 0; j <= levelWall.Length; j++)
                {
                    if (j == levelWall.Length)
                    {
                        levelCnt[levelWall.Length]++;
                    }
                    else if (array[i] < levelWall[j])
                    {
                        levelCnt[j]++;
                        break;
                    }
                }
            }

            int colorCnt = 0;
            for (int i = 0; i < levelWall.Length; i++)
            {
                if (levelCnt[i] > 0)
                {
                    colorCnt++;
                }
            }
            int min = colorCnt > 0 ? colorCnt : 1;
            int max = colorCnt + levelCnt[levelWall.Length];

            Console.WriteLine(min + " " + max);
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