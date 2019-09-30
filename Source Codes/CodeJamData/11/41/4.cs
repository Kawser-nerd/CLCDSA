using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Globalization;

namespace Round2ProblemA
{
    class Program
    {
        static void Main(string[] args)
        {
           //const string fileName = "test";
            //const string fileName = "A-small-attempt0";
            const string fileName = "A-large";

            string DataFolder = @"D:\Projects\CSharp\CodeJam2011\Round2ProblemA\Data\";
            StreamReader sr = File.OpenText(DataFolder + fileName + ".in");
            using (StreamWriter sw = File.CreateText(DataFolder + fileName + ".out"))
            {
                int caseCount = int.Parse(sr.ReadLine());
                for (int caseNumber = 1; caseNumber <= caseCount; ++caseNumber)
                {
                    string[] s = sr.ReadLine().Split();
                    int X = int.Parse(s[0]);
                    int S = int.Parse(s[1]);
                    int R = int.Parse(s[2]);
                    int t = int.Parse(s[3]);
                    int N = int.Parse(s[4]);
                    int[] w = new int[N + 1];
                    int[] L = new int[N + 1];
                    int TotalL = 0;
                    for (int i = 0; i < N; ++i)
                    {
                        s = sr.ReadLine().Split();
                        w[i] = int.Parse(s[2]);
                        L[i] = int.Parse(s[1]) - int.Parse(s[0]);
                        TotalL += L[i];
                    }
                    w[N] = 0;
                    L[N] = X - TotalL;
                    System.Diagnostics.Debug.Assert(L[N] >= 0);
                    Array.Sort(w, L);
                    double res = 0;
                    for (int i = 0; i <= N; ++i)
                    {
                        double rt = t - res;
                        if (rt > 0)
                        {
                            double t1 = (((double)L[i]) / (w[i] + R));
                            if (t1 < rt)
                                res += t1;
                            else
                                res += rt + ((L[i] - (w[i] + R) * rt) / (w[i] + S));
                        }
                        else
                            res += ((double)L[i]) / (w[i] + S);

                    }
                    sw.WriteLine("Case #" + caseNumber.ToString() + ": " + res.ToString("F8", CultureInfo.InvariantCulture));
                }
            }
        }
    }
}
