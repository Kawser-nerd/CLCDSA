using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.D_Challenge
{
    class ABC_076
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int n = ReadInt();
            var tList = new List<int>();
            tList.AddRange(ReadInts());
            tList.Add(1);
            int[] ts = tList.ToArray();

            var vList = new List<int>();
            vList.AddRange(ReadInts());
            vList.Add(0);
            int[] vs = vList.ToArray();
            int totalTime = 0;
            for (int i = 0; i <= n; i++)
            {
                totalTime += tList[i];
            }
            totalTime++;
            var goVals = new double[totalTime];
            var endVals = new double[totalTime];
            int time = 0;
            for (int i = 0; i < n; i++)
            {
                for (int j = 1; j <= ts[i]; j++)
                {
                    goVals[time + j]
                        = Math.Min(goVals[time + j - 1] + 1, vs[i]);
                }
                time += ts[i];
            }
            time = totalTime - 1;
            for (int i = n; i >= 0; i--)
            {
                time -= ts[i];
                for (int j = ts[i] - 1; j >= 0; j--)
                {
                    endVals[time + j]
                        = Math.Min(endVals[time + j + 1] + 1, vs[i]);
                }
            }
            for (int i = 0; i < totalTime; i++)
            {
                //Console.WriteLine(goVals[i]+" "+endVals[i]);
            }
            var vals = new double[totalTime];
            for(int i = 0; i < totalTime; i++)
            {
                vals[i] = Math.Min(goVals[i], endVals[i]);
                //Console.WriteLine(vals[i]);
            }
            double area = 0;
            time = 0;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < ts[i]; j++)
                {
                    area += (vals[time+j] + vals[time+j + 1]) * 0.5;
                    if (vals[time+j] == vals[time+j + 1]
                        && vals[time+j] < vs[i])
                    {
                        area += 0.25;
                    }
                }
                time += ts[i];
            }
            Console.WriteLine(area);
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