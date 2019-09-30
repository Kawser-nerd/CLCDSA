using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Globalization;

namespace Round2ProblemC
{
    class Program
    {
        static int[] div;
        static void Init()
        {
            div = new int[1000010];
            div[1] = 1;
            for (int i = 2; i < div.Length; ++i)
            {
                if (div[i] == 0)
                {
                    for (int j = i; j < div.Length; j += i)
                        div[j] = i;
                }
            }
        }

        static Dictionary<int, int> getMult(int N)
        {
            Dictionary<int, int> res = new Dictionary<int, int>();
            while (N > 1)
            {
                int p = div[N];
                if (!res.ContainsKey(p))
                    res.Add(p, 1);
                else
                    res[p]++;
                N /= p;
            }
            return res;
        }

        static long Solve(long N)
        {
            if (N == 1)
                return 0;
            long Sq = (long)(Math.Sqrt(N) + 1);
            long delta = 1;
            for (long i = 2; i <= Sq; ++i)
            {
                if (div[i] == i)
                {
                    long d = i * i;
                    while (d <= N)
                    {
                        delta++;
                        d *= i;
                    }
                }
            }
            return delta;
        }
        static void Main(string[] args)
        {
            //const string fileName = "test";
            //const string fileName = "C-small-attempt0";
            const string fileName = "C-large";

            Init();
            string DataFolder = @"D:\Projects\CSharp\CodeJam2011\Round2ProblemC\Data\";
            StreamReader sr = File.OpenText(DataFolder + fileName + ".in");
            using (StreamWriter sw = File.CreateText(DataFolder + fileName + ".out"))
            {
                int caseCount = int.Parse(sr.ReadLine());
                for (int caseNumber = 1; caseNumber <= caseCount; ++caseNumber)
                {
                    long N = long.Parse(sr.ReadLine());
                    long res = Solve(N);
                    sw.WriteLine("Case #" + caseNumber.ToString() + ": " + res.ToString());
                }
            }
        }
    }
}
