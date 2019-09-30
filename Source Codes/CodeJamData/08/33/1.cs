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
            const string fileName = "C-small-attempt0";
            //const string fileName = "C-large";
            string DataFolder = @"C:\Projects\CSharp\CodeJam2008\Round1ProblemC\Data\";
            StreamReader sr = File.OpenText(DataFolder + fileName + ".in");
            using (StreamWriter sw = File.CreateText(DataFolder + fileName + ".out"))
            {
                int caseCount = int.Parse(sr.ReadLine());
                for (int caseNumber = 1; caseNumber <= caseCount; ++caseNumber)
                {
                    string[] s = sr.ReadLine().Split(' ');
                    int n = int.Parse(s[0]);
                    int m = int.Parse(s[1]);
                    long X = int.Parse(s[2]);
                    long Y = int.Parse(s[3]);
                    long Z = int.Parse(s[4]);
                    long[] A = new long[m];
                    for (int i = 0; i < m; ++i)
                        A[i] = int.Parse(sr.ReadLine());
                    int[] sg = new int[n];
                    for (int i = 0; i < n; ++i)
                    {
                        sg[i] = (int)A[i % m];
                        A[i % m] = (X * A[i % m] + Y * (i + 1)) % Z;
                    }
                    long[] dp = new long[n];
                    long res = 0;
                    for (int i = n - 1; i >= 0; --i)
                    {
                        dp[i] = 1;
                        int sgi = sg[i];
                        for (int j = i + 1; j < n; ++j)
                            if (sgi < sg[j])
                                dp[i] = (dp[i] + dp[j]) % 1000000007;
                        res = (res + dp[i]) % 1000000007;
                    }

                    sw.WriteLine("Case #" + caseNumber.ToString() + ": " + res);
                }
            }
        }
    }
}
