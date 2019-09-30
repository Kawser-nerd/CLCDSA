using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Diagnostics;

namespace Round1ProblemB
{
    class Program
    {
        static long[,,] cnt;
        static long eval(string s, int[] op)
        {
            long res = 0;
            bool bAdd = true;
            long d = (int)(s[0] - '0');
            for (int i = 0; i < op.Length; ++i)
            {
                if (op[i] == 0)
                    d = d * 10 + (int)(s[i + 1] - '0');
                else
                {
                    res += (bAdd) ? d : -d;
                    d = (int)(s[i + 1] - '0');
                    bAdd = op[i] == 1;
                }
            }
            res += (bAdd) ? d : -d;
            return res;
        }
        static bool IsUgly(long n)
        {
            return (n %2 ==0) ||(n %3 ==0) || (n %5 ==0) ||(n %7 ==0); 
        }
        static void Main(string[] args)
        {
            //const string fileName = "test";
            //const string fileName = "B-small";
//            const string fileName = "B-small-attempt0";
            const string fileName = "B-large";
            string DataFolder = @"C:\Projects\CSharp\CodeJam2008\Round1ProblemB\Data\";
            StreamReader sr = File.OpenText(DataFolder + fileName + ".in");
            using (StreamWriter sw = File.CreateText(DataFolder + fileName + ".out"))
            {
                int caseCount = int.Parse(sr.ReadLine());
                for (int caseNumber = 1; caseNumber <= caseCount; ++caseNumber)
                {
                    string s = sr.ReadLine().Trim();
                    cnt = new long[210, 2, 210];
                    cnt[0, 0, s[0] - '0'] = 1;
                    for (int i = 1; i < s.Length; ++i)
                    {
                        int ch = s[i] - '0';
                        long[, ,] cnt2 = new long[210, 2, 210];//(long[,,])cnt.Clone();
                        for (int r = 0; r < 210; ++r)
                            for (int d = 0; d < 210; ++d)
                            { 
                                int nd = (d * 10 + ch) % 210;
                                cnt2[r, 0, nd] += cnt[r, 0, d];
                                cnt2[r, 1, nd] += cnt[r, 1, d];

                                cnt2[(r + d) % 210, 0, ch] += cnt[r, 0, d];
                                cnt2[(r + 210 - d) % 210, 0, ch] += cnt[r, 1, d];


                                cnt2[(r + d) % 210, 1, ch] += cnt[r, 0, d];
                                cnt2[(r + 210 - d) % 210, 1, ch] += cnt[r, 1, d];
                            }
                        cnt = cnt2;
                    }
                    long res = 0;
                    for (int r = 0; r < 210; ++r)
                        for (int d = 0; d < 210; ++d)
                        {
                            if (IsUgly(r + d))
                                res += cnt[r, 0, d];
                            if (IsUgly(r + 210 - d))
                                res += cnt[r, 1, d];
                        }
/*                    int[] op = new int[s.Length - 1];

                    int res = 0;
                    if (IsUgly(eval(s, op)))
                        res++;
                    int i = op.Length - 1;
                    while (i >= 0)
                    {
                        op[i] += 1;
                        if (IsUgly(eval(s, op)))
                            res++;
                        i = op.Length - 1;
                        while (i >= 0 && op[i] == 2)
                        {
                            op[i] = 0;
                            --i;
                        };
                    }
  */                 
                    sw.WriteLine("Case #" + caseNumber.ToString() + ": " + res);
                }
            }
        }
    }
}
