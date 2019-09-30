using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace Round3ProblemC
{
    class Program
    {
        static int N;
        static int M;

        static bool[] busy;
        static int[] brk;
//        static int[] res;

        static int res;


        static bool isOK(int n)
        { 
            for (int i = 0; i < N; ++i)
                if ((n & (1 << i)) != 0)
                {
                    if ((n & (1 << (i + 1))) != 0)
                        return false;
                }
            return true;
        }
        
        static int bitCount(int n)
        {
            int res = 0;
            while (n > 0)
            {
                if (n % 2 != 0)
                    res++;
                n = (n >> 1);
            }
            return res;
        }

        static int upMask(int n)
        {
            int res = 0;
            for (int i = 0; i < N; ++i)
                if ((n & (1 << i)) != 0)
                {
                    if (i > 0)
                        res |= (1 << (i - 1));
                    if (i + 1< N)
                        res |= (1 << (i + 1));
                }
            return res;
        }

        static void Main(string[] args)
        {
            //const string fileName = "test";
            const string fileName = "C-small-attempt0";
            //const string fileName = "C-large";
            string DataFolder = @"C:\Projects\CSharp\CodeJam2008\Round3ProblemC\Data\";
            StreamReader sr = File.OpenText(DataFolder + fileName + ".in");
            using (StreamWriter sw = File.CreateText(DataFolder + fileName + ".out"))
            {
                int caseCount = int.Parse(sr.ReadLine());
                for (int caseNumber = 1; caseNumber <= caseCount; ++caseNumber)
                {
                    //int turnaround = int.Parse(sr.ReadLine());
                    string[] s = sr.ReadLine().Split(' ');
                    M = int.Parse(s[0]);
                    N = int.Parse(s[1]);
                    string[] map = new string[M];
                    int mx = (1 << N);
                    int[,] dp = new int[M, mx];

                    brk = new int[M];
                    for (int i = 0; i < M; ++i)
                    {
                        map[i] = sr.ReadLine();
                        int br = 0;
                        for (int j = 0; j < N; ++j)
                            if (map[i][j] == 'x')
                                br |=  (1 << j);
                        brk[i] = br;
                    }
                    for (int i = 0; i < mx; ++i)
                    {
                        if (isOK(i) && ((i & brk[0]) == 0))
                            dp[0, i] = bitCount(i);
                    }
                    for (int j = 1; j < M; ++j)
                    {
                        for (int i = 0; i < mx; ++i)
                        {
                            if (isOK(i) && ((i & brk[j]) == 0))
                            {
                                int um = upMask(i);
                                int dc = bitCount(i);
                                int prev = 0;
                                for (int k = 0; k < mx; ++k)
                                {
                                    if ((um & k ) == 0)
                                        prev = Math.Max(prev, dp[j - 1, k]);
                                }
                                dp[j, i] = dc + prev;
                            }
                        }
                    }
                    int res = 0;

                    for (int i = 0; i < mx; ++i)
                    {
                        res = Math.Max(res, dp[M - 1, i]);
                    }

                    sw.WriteLine("Case #" + caseNumber.ToString() + ": " + res);
                }
            }
        }
    }
}
