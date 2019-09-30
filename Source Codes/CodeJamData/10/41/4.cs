using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace Round2ProblemA
{
    class Program
    {
        static bool IsDiamond(char[,] dm, int K, int N)
        {
            for (int x0 = 0; x0 <= N - K; ++x0)
                for (int y0 = 0; y0 <= N - K; ++y0)
                {
                    bool bDiamond = true;
                    for (int x = 0; x < K && bDiamond; ++x)
                        for (int y = 0; y < K; ++y)
                        {
                            int hy = x0 + x;
                            int hx = y0 + y;
                            if (y0 <= hy && hy < y0 + K && x0 <= hx && hx < x0 + K && dm[y, x] != dm[hy - y0, hx - x0])
                            {
                                bDiamond = false;
                                break;
                            }
                            hy = N - 1 - (x0 + x);
                            hx = N - 1 - (y0 + y);
                            if (y0 <= hy && hy < y0 + K && x0 <= hx && hx < x0 + K && dm[y, x] != dm[hy - y0, hx - x0])
                            {
                                bDiamond = false;
                                break;
                            }
                        }
                    if (bDiamond)
                        return true;
                }
            return false;
        }

        static void Main(string[] args)
        {
            //const string fileName = "test";
            //const string fileName = "A-small-attempt0";
            const string fileName = "A-large";

            string DataFolder = @"C:\Projects\CSharp\CodeJam2010\Round2ProblemA\Data\";
            StreamReader sr = File.OpenText(DataFolder + fileName + ".in");
            using (StreamWriter sw = File.CreateText(DataFolder + fileName + ".out"))
            {
                int caseCount = int.Parse(sr.ReadLine());

                for (int caseNumber = 1; caseNumber <= caseCount; ++caseNumber)
                {
                    int K = int.Parse(sr.ReadLine());
                    char[,] dm = new char[K, K];
                    for (int i = 0; i < K; ++i)
                    {
                        string s = sr.ReadLine();
                        int p = 0;
                        for (int j = 0; j < s.Length; ++j)
                            if (s[j] != ' ')
                            {
                                dm[i - p, p] = s[j];
                                p++;
                            }
                    }
                    for (int i = 1; i < K; ++i)
                    {
                        string s = sr.ReadLine();
                        int p = i;
                        for (int j = 0; j < s.Length; ++j)
                            if (s[j] != ' ')
                            {
                                dm[K - 1 + i - p, p] = s[j];
                                p++;
                            }
                    }

                    int N = K;
                    while (!IsDiamond(dm, K, N)) ++N;
                    int res = N * N - K * K;

                    sw.WriteLine("Case #" + caseNumber.ToString() + ": " + res.ToString());
                }
            }
        }
    }
}
