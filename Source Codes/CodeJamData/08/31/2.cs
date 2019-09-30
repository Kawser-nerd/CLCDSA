using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Diagnostics;

namespace Round1ProblemA
{
    class Program
    {
        static void Main(string[] args)
        {
            //const string fileName = "test";
            //const string fileName = "A-small-attempt0";
            const string fileName = "A-large";
            string DataFolder = @"C:\Projects\CSharp\CodeJam2008\Round1ProblemA\Data\";
            StreamReader sr = File.OpenText(DataFolder + fileName + ".in");
            using (StreamWriter sw = File.CreateText(DataFolder + fileName + ".out"))
            {
                int caseCount = int.Parse(sr.ReadLine());
                for (int caseNumber = 1; caseNumber <= caseCount; ++caseNumber)
                {
                    //int turnaround = int.Parse(sr.ReadLine());
                    string[] s = sr.ReadLine().Split(' ');
                    int P = int.Parse(s[0]);
                    int K = int.Parse(s[1]);
                    int L = int.Parse(s[2]);
                    int[] fr = new int[L];
                    s = sr.ReadLine().Split(' ');
                    for (int i = 0; i < L; ++i)
                        fr[i] = int.Parse(s[i]);
                    
                    Array.Sort(fr);
                    int k = 0;
                    while (k < fr.Length && fr[k] == 0) ++k;
                    int letInMes = fr.Length - k;
                    Debug.Assert(letInMes <= K * P);

                    long res = 0;

                    for (int i = fr.Length - 1; i >= k; --i)
                    {
                        long presCount = 1 + ((fr.Length - 1 - i) / K);
                        res += (long)fr[i] * presCount;
                    }

                    sw.WriteLine("Case #" + caseNumber.ToString() + ": " + res);
                }
            }
        }
    }
}
