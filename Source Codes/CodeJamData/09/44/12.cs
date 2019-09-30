using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Globalization;

namespace Round2ProblemD
{
    class Program
    {
        static int N;
        static int[] X;
        static int[] Y;
        static int[] R;

        static double getR2(int i1, int i2)
        {
            return (Math.Sqrt((X[i1] - X[i2]) * (X[i1] - X[i2]) + (Y[i1] - Y[i2]) * (Y[i1] - Y[i2])) + R[i1] + R[i2]) / 2.0;
        }

        static void Main(string[] args)
        {
            //const string fileName = "test";
            const string fileName = "D-small-attempt0";
            //const string fileName = "D-large";

            string DataFolder = @"C:\Projects\CSharp\CodeJam2009\Round2ProblemD\Data\";
            StreamReader sr = File.OpenText(DataFolder + fileName + ".in");
            using (StreamWriter sw = File.CreateText(DataFolder + fileName + ".out"))
            {
                int caseCount = int.Parse(sr.ReadLine());
                for (int caseNumber = 1; caseNumber <= caseCount; ++caseNumber)
                {
                    N = int.Parse(sr.ReadLine());
                    X = new int[N];
                    Y = new int[N];
                    R = new int[N];
                    for (int i = 0; i < N; ++i)
                    {
                        string[] s = sr.ReadLine().Split(' ');
                        X[i] = int.Parse(s[0]);
                        Y[i] = int.Parse(s[1]);
                        R[i] = int.Parse(s[2]);
                    }
                    double res = 0;
                    switch (N) 
                    {
                        case 1:
                            res = R[0];
                            break;
                        case 2:
                            res = Math.Max(R[0], R[1]);
                            break;
                        case 3:
                            res = Math.Max(getR2(0, 1), R[2]);
                            res = Math.Min(res, Math.Max(getR2(0, 2), R[1]));
                            res = Math.Min(res, Math.Max(getR2(1, 2), R[0]));
                            break;
                    }
                    sw.WriteLine("Case #" + caseNumber.ToString() + ": " + res.ToString("F8", CultureInfo.InvariantCulture));
                }
            }
        }
    }
}
