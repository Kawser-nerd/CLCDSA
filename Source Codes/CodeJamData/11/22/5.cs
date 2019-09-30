using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Globalization;

namespace Round1BProblemB
{
    class Program
    {
        static int C;
        static int D;
        static long[] P;
        static long[] V;
        static bool Can(long time)
        {
            long pos = long.MinValue;
            for (int i = 0; i < C; ++i)
            {
                if (pos > P[i] + time)
                    return false;
                long leftP = Math.Max(pos, P[i] - time);
                pos = leftP + V[i] * D;
                if (pos - D > P[i] + time)
                    return false;
            }
            return true;
        }
        static void Main(string[] args)
        {
            //const string fileName = "test";
            //const string fileName = "B-small-attempt0";
            const string fileName = "B-large";

            string DataFolder = @"D:\Projects\CSharp\CodeJam2011\Round1BProblemB\Data\";
            StreamReader sr = File.OpenText(DataFolder + fileName + ".in");
            using (StreamWriter sw = File.CreateText(DataFolder + fileName + ".out"))
            {
                int caseCount = int.Parse(sr.ReadLine());
                for (int caseNumber = 1; caseNumber <= caseCount; ++caseNumber)
                {
                    string[] s = sr.ReadLine().Split();
                    C = int.Parse(s[0]);
                    D = 2 * int.Parse(s[1]);
                    P = new long[C];
                    V = new long[C];
                    for (int i = 0; i < C; ++i)
                    {
                        s = sr.ReadLine().Split();
                        P[i] = 2 * int.Parse(s[0]);
                        V[i] = int.Parse(s[1]);
                    }
                    long minT = 0;
                    long maxT = 1000000L * 1000000 * 2;
                    while (minT < maxT)
                    {
                        long T = (minT + maxT) / 2;
                        if (Can(T))
                            maxT = T;
                        else
                            minT = T + 1;
                    }
                    sw.WriteLine("Case #" + caseNumber.ToString() + ": " + ((double)minT / 2).ToString("F1", CultureInfo.InvariantCulture));
                }
            }
        }
    }
}
