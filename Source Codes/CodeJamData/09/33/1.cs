using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace Round1ProblemC
{
    class Program
    {
        static void Main(string[] args)
        {
            //const string fileName = "test";
            //const string fileName = "C-small-attempt0";
            const string fileName = "C-large";

            string DataFolder = @"C:\Projects\CSharp\CodeJam2009\Round1ProblemC\Data\";
            StreamReader sr = File.OpenText(DataFolder + fileName + ".in");
            using (StreamWriter sw = File.CreateText(DataFolder + fileName + ".out"))
            {
                int caseCount = int.Parse(sr.ReadLine());
                for (int caseNumber = 1; caseNumber <= caseCount; ++caseNumber)
                {
                    string[] s = sr.ReadLine().Split(' ');
                    int P = int.Parse(s[0]);
                    int Q = int.Parse(s[1]);
                    int[] qp = new int[Q + 2];
                    s = sr.ReadLine().Split(' ');
                    for (int i = 0; i < Q; ++i)
                        qp[i + 1] = int.Parse(s[i]);
                    qp[Q + 1] = P + 1;
                    int[,] dp = new int[Q + 2, Q + 2];
                    for (int len = 2; len <= Q + 1; ++len)
                        for (int A = 0; A + len < Q + 2; ++A)
                        {
                            int B = A + len;
                            int min = int.MaxValue; 
                            for (int i = 1; i < len; ++i)
                                min = Math.Min(min, dp[A, A + i] + dp[A + i, B]);
                            dp[A, B] = min + qp[B] - qp[A] - 2;
                        }
                    sw.WriteLine("Case #" + caseNumber.ToString() + ": " + dp[0, Q + 1].ToString());
                }
            }
        }
    }
}
