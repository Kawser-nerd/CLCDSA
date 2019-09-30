using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Diagnostics;
using System.IO;
using System.Globalization;

namespace Round1CProblemB
{
    class R1C_ProblemB
    {
        static double D;
        static int N;
        static double[] t;
        static double[] x;
        
        static double Solve(double A)
        {
            double fastest = Math.Sqrt(2 * D / A);
            double res = fastest;
            int pos = 0;
            while (x[pos] < D) pos++;
            if (pos > 0)
            {
                double tcar = t[pos - 1] + ((D - x[pos - 1]) * (t[pos] - t[pos - 1]) / (x[pos] - x[pos - 1]));
                res = Math.Max(res, tcar);

                for (int i = 0; i < pos; ++i)
                {
                    double dt = t[i] - Math.Sqrt(2 * x[i] / A);
                    if (dt > 0)
                        res = Math.Max(res, dt + fastest);
                }
            }
            return res;
        }

        static void Main(string[] args)
        {
            //const string fileName = "test";
            //const string fileName = "B-small-attempt0";
            const string fileName = "B-large";

            string DataFolder = @"D:\Projects\CSharp\CodeJam2012\Round1CProblemB\Data\";
            StreamReader sr = File.OpenText(DataFolder + fileName + ".in");
            using (StreamWriter sw = File.CreateText(DataFolder + fileName + ".out"))
            {
                int caseCount = int.Parse(sr.ReadLine());
                for (int caseNumber = 1; caseNumber <= caseCount; ++caseNumber)
                {
                    string[] s = sr.ReadLine().Split();
                    D = double.Parse(s[0], CultureInfo.InvariantCulture);
                    N = int.Parse(s[1]);
                    int ACount = int.Parse(s[2]);
                    t = new double[N];
                    x = new double[N];
                    for (int i = 0; i < N; ++i)
                    {
                        s = sr.ReadLine().Split();
                        t[i] = double.Parse(s[0], CultureInfo.InvariantCulture);
                        x[i] = double.Parse(s[1], CultureInfo.InvariantCulture);
                    }
                    s = sr.ReadLine().Split();
                    Debug.Assert(ACount == s.Length);

                    sw.WriteLine("Case #" + caseNumber.ToString() + ":");
                    for (int i = 0; i < ACount; ++i)
                    {
                        double res = Solve(double.Parse(s[i], CultureInfo.InvariantCulture));
                        sw.WriteLine(res.ToString("F8", CultureInfo.InvariantCulture));
                    }
                }
            }
        }
    }
}
