using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Globalization;

namespace Round1ProblemB
{
    class Program
    {
        static void Main(string[] args)
        {
            //const string fileName = "test";
            //const string fileName = "B-small-attempt0";
            const string fileName = "B-large";

            string DataFolder = @"C:\Projects\CSharp\CodeJam2009\Round1ProblemB\Data\";
            StreamReader sr = File.OpenText(DataFolder + fileName + ".in");
            using (StreamWriter sw = File.CreateText(DataFolder + fileName + ".out"))
            {
                int caseCount = int.Parse(sr.ReadLine());
                for (int caseNumber = 1; caseNumber <= caseCount; ++caseNumber)
                {
                    long x0 = 0;
                    long y0 = 0;
                    long z0 = 0;
                    long vx = 0;
                    long vy = 0;
                    long vz = 0;
                    int N = int.Parse(sr.ReadLine());
                    for (int i = 0; i < N; ++i)
                    {
                        string[] s = sr.ReadLine().Split(' ');
                        x0 += int.Parse(s[0]);
                        y0 += int.Parse(s[1]);
                        z0 += int.Parse(s[2]);
                        vx += int.Parse(s[3]);
                        vy += int.Parse(s[4]);
                        vz += int.Parse(s[5]);
                    }
                    long v2 = vx * vx + vy * vy  + vz * vz;
                    double resT = (v2 > 0)? -((double)x0 * vx + y0 * vy + z0 * vz)/(double)v2: 0;
                    if (resT < 0)
                        resT = 0;
                    double fx = x0 + vx * resT;
                    double fy = y0 + vy * resT;
                    double fz = z0 + vz * resT;
                    double resD = Math.Sqrt(fx * fx + fy * fy + fz * fz) / (double)N;
                    sw.WriteLine("Case #" + caseNumber.ToString() + ": " + resD.ToString("F8", CultureInfo.InvariantCulture) + " " + resT.ToString("F8", CultureInfo.InvariantCulture));
                }
            }
        }
    }
}
