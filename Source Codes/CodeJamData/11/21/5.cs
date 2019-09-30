using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Globalization;

namespace Round1BProblemA
{
    class Program
    {
        static void Main(string[] args)
        {
            //const string fileName = "test";
            //const string fileName = "A-small-attempt0";
            const string fileName = "A-large";

            string DataFolder = @"D:\Projects\CSharp\CodeJam2011\Round1BProblemA\Data\";
            StreamReader sr = File.OpenText(DataFolder + fileName + ".in");
            using (StreamWriter sw = File.CreateText(DataFolder + fileName + ".out"))
            {
                int caseCount = int.Parse(sr.ReadLine());
                for (int caseNumber = 1; caseNumber <= caseCount; ++caseNumber)
                {
                    int N = int.Parse(sr.ReadLine());
                    string[] s = new string[N];
                    for (int i = 0; i < N; ++i)
                    {
                        s[i] = sr.ReadLine();
                        System.Diagnostics.Debug.Assert(s[i].Length == N);
                    }
                    int[] Games = new int[N];
                    int[] Wins = new int[N];
                    for (int i = 0; i < N; ++i)
                    {
                        for (int j = 0; j < N; ++j)
                            if (s[i][j] != '.')
                            {
                                Games[i]++;
                                if (s[i][j] == '1')
                                    Wins[i]++;
                            }
                    }
                    double[] OWP = new double[N];
                    for (int i = 0; i < N; ++i)
                    {
                        for (int j = 0; j < N; ++j)
                            if (s[i][j] != '.')
                            {
                                int opWinds = Wins[j];
                                if (s[i][j] == '0')
                                    opWinds--;

                                OWP[i] += (((double)opWinds) / (Games[j] - 1));
                            }
                        OWP[i] /= Games[i];
                    }
                    double[] OOWP = new double[N];
                    for (int i = 0; i < N; ++i)
                    {
                        for (int j = 0; j < N; ++j)
                            if (s[i][j] != '.')
                                OOWP[i] += OWP[j];
                        OOWP[i] /= Games[i];
                    }
                    sw.WriteLine("Case #" + caseNumber.ToString() + ":");
                    for (int i = 0; i < N; ++i)
                    {
                        double res = (((double)Wins[i]) / Games[i]) * 0.25 + 0.5 * OWP[i] + 0.25 * OOWP[i];
                        sw.WriteLine(res.ToString("F8", CultureInfo.InvariantCulture));
                    }
                }
            }
        }
    }
}
