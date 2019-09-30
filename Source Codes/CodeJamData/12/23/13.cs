using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Diagnostics;
using System.IO;

namespace Round1BProblemC
{
    class R1B_ProblemC
    {
        static int GetSumm(int[] S, int mask)
        {
            int res = 0;
            int i = 0;
            while (mask > 0)
            {
                if ((mask & 1) != 0)
                    res += S[i];
                i++;
                mask >>= 1;
            }
            return res;
        }
        
        static string GetSubset(int[] S, int mask)
        {
            string res = "";
            int i = 0;
            while (mask > 0)
            {
                if ((mask & 1) != 0)
                    res += " " + S[i];
                i++;
                mask >>= 1;
            }
            return res.Substring(1);
        }

        static void Main(string[] args)
        {
            //const string fileName = "test";
            const string fileName = "C-small-attempt0";
            //const string fileName = "C-large";

            string DataFolder = @"D:\Projects\CSharp\CodeJam2012\Round1BProblemC\Data\";
            StreamReader sr = File.OpenText(DataFolder + fileName + ".in");
            using (StreamWriter sw = File.CreateText(DataFolder + fileName + ".out"))
            {
                int caseCount = int.Parse(sr.ReadLine());
                for (int caseNumber = 1; caseNumber <= caseCount; ++caseNumber)
                {
                    string[] s = sr.ReadLine().Split();
                    int N = int.Parse(s[0]);
                    Debug.Assert(N + 1 == s.Length);
                    int[] S = new int[N];
                    for (int i = 0; i < N; ++i)
                        S[i] = int.Parse(s[i + 1]);
                    Dictionary<int, int> d = new Dictionary<int,int>(1 << 20);
                    int mask1 = 1;
                    int mask2 = 0;
                    while (mask1 < (1 << 20))
                    {
                        int sum = GetSumm(S, mask1);
                        if (d.TryGetValue(sum, out mask2))
                            break;
                        d.Add(sum, mask1);
                        mask1++;
                    }
                    sw.WriteLine("Case #" + caseNumber.ToString() + ":");
                    if (mask1 < (1 << 20))
                    {
                        sw.WriteLine(GetSubset(S, mask1));
                        sw.WriteLine(GetSubset(S, mask2));
                    }
                    else
                        sw.WriteLine("Impossible");
                }
            }
        }
    }
}
