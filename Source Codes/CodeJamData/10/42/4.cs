using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace Round2ProblemB
{
    class Program
    {
        //static solve()

        static void Main(string[] args)
        {
            //const string fileName = "test";
            //const string fileName = "B-small-attempt0";
            const string fileName = "B-large";

            string DataFolder = @"C:\Projects\CSharp\CodeJam2010\Round2ProblemB\Data\";
            StreamReader sr = File.OpenText(DataFolder + fileName + ".in");
            using (StreamWriter sw = File.CreateText(DataFolder + fileName + ".out"))
            {
                int caseCount = int.Parse(sr.ReadLine());

                for (int caseNumber = 1; caseNumber <= caseCount; ++caseNumber)
                {
                    int P = int.Parse(sr.ReadLine());
                    string[] s = sr.ReadLine().Split();
                    int N = 1 << P; 
                    int[] K = new int[N];
                    for (int i = 0; i < N; ++i)
                        K[i] = P - int.Parse(s[i]);
                    int[] cost = new int[N];
                    int pos = N;
                    for (int i = 0; i < P; ++i)
                    {
                        s = sr.ReadLine().Split();
                        for (int j = s.Length - 1; j >= 0; --j)
                        {
                            cost[--pos] = int.Parse(s[j]);
                        }
                    }

                    int lev = P - 1;
                    int[,] dp = new int[N, P];
                    for (int i = N - 1; i > 0; --i)
                    {
                        for (int k = 0; k <= lev; ++k)
                        {
                            if (lev == P - 1)
                            {
                                int c1 = (i - (1 << lev)) * 2;
                                if (K[c1] - k > 1 || K[c1 + 1] - k > 1)
                                    dp[i, k] = int.MaxValue / 4;
                                else if (K[c1] - k <= 0 && K[c1 + 1] - k <= 0)
                                    dp[i, k] = 0;
                                else 
                                    dp[i, k] = cost[i];
                            }
                            else
                            {
                                int c1 = i * 2;
                                dp[i, k] = Math.Min(cost[i] + dp[c1, k + 1] + dp[c1 + 1, k + 1], dp[c1, k] + dp[c1 + 1, k]);
                                if (dp[i, k] > int.MaxValue / 4)
                                    dp[i, k] = int.MaxValue / 4;
                            }
                        }
                        if (i == (1 << lev))
                            lev--;
                    }

                    int res = dp[1, 0];
                    sw.WriteLine("Case #" + caseNumber.ToString() + ": " + res.ToString());
                }
            }

        }
    }
}
