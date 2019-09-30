using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.D_Challenge
{
    class ABC_033
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            long n = ReadInt();
            var xy = new int[n][];
            for(int i = 0; i < n; i++)
            {
                xy[i] = ReadInts();
            }

            long rightCnt = 0;
            long obtuseCnt = 0;
            double eps = 0.000000001;
            for (int i = 0; i < n; i++)
            {
                var angles = new List<double>();
                for (int j = 0; j < n; j++)
                {
                    if (j == i) continue;
                    double angle = Math.Atan2(
                        xy[j][1] - xy[i][1], xy[j][0] - xy[i][0]);
                    angles.Add(angle);
                }
                angles.Sort();
                for(int j = 0; j < n - 1; j++)
                {
                    angles.Add(angles[j] + 2 * Math.PI);
                    //Console.WriteLine(angles[j] + " ");
                }
                //Console.WriteLine();
                int rightIndex = 0;//???90????????????
                int obtuseIndex = 0;//???180????????????
                for(int j = 0; j < n - 1; j++)
                {
                    while (rightIndex < angles.Count
                        && angles[rightIndex] - angles[j]
                            < Math.PI * 0.5 - eps) rightIndex++;
                    while (obtuseIndex < angles.Count
                        && angles[obtuseIndex] - angles[j]
                                < Math.PI + eps) obtuseIndex++;
                    if (Math.Abs(angles[rightIndex] - angles[j]-Math.PI*0.5)
                            <eps*2)
                    {
                        rightCnt++;
                        rightIndex++;
                    }
                    obtuseCnt += obtuseIndex - rightIndex;
                    //Console.WriteLine(sharp + " " + right + " " + obtuse);
                }
            }
            long sharpCnt = n * (n -1) * (n - 2) / 6 - rightCnt - obtuseCnt;
            Console.WriteLine(sharpCnt + " " + rightCnt + " " + obtuseCnt);
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