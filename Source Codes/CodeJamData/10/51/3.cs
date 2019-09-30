using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace Round3ProblemA
{
    class Program
    {
        static int[] prm = new int[10000];
        static int prmCnt = 0;
        static void IniPrimtes()
        { 
            prm[0] = 2;
            prm[1] = 3;
            prmCnt = 2;
            for (int i = 5; i < 10000; i += 2 )
            {
                bool bPrime = true;
                for (int j = 1; prm[j] * prm[j] <= i && j < prmCnt; ++j)
                    if (i % prm[j] == 0)
                    {
                        bPrime = false;
                        break;
                    }
                if (bPrime)
                    prm[prmCnt++] = i;
            }
        }

        static string solve(int K, int D, int[] ss)
        {
            if (K == 1)
                return "I don't know.";
            int maxP = 1;
            for (int i = 0; i < D; ++i)
                maxP *= 10;
            int maxS = ss[0];
            for (int i = 1; i < K; ++i)
                maxS = Math.Max(maxS, ss[i]);

            int nextS = -1;
            long[] sa = new long[K];
            for (int a = 0; a < maxP; ++a)
            {
                for (int i = 0; i < K; ++i)
                    sa[i] = ss[i] * (long)a;
                for (int i = 0; i < prmCnt && prm[i] <= maxP; ++i)
                {
                    int p = prm[i];
                    if (p <= maxS)
                        continue;
                    int B = (ss[1] + p - (int)( sa[0] % p)) %p;
                    bool bCan = true;
                    for (int j = 1; j < K; ++j)
                        if ((p + ss[j] - (int)(sa[j - 1] % p)) %p != B)
                        {
                            bCan = false;
                            break;
                        }
                    if (bCan)
                    {
                        int next = ((int)(sa[K - 1] % p) + B) % p;
                        if (nextS == -1)
                            nextS = next;
                        else if (nextS != next)
                            return "I don't know.";
                    }
                }
            }
            return nextS.ToString();
           
        }
        static void Main(string[] args)
        {
            //const string fileName = "test";
            const string fileName = "A-small-attempt0";
            //const string fileName = "A-large";

            string DataFolder = @"C:\Projects\CSharp\CodeJam2010\Round3ProblemA\Data\";
            StreamReader sr = File.OpenText(DataFolder + fileName + ".in");
            using (StreamWriter sw = File.CreateText(DataFolder + fileName + ".out"))
            {
                IniPrimtes();
                int caseCount = int.Parse(sr.ReadLine());

                for (int caseNumber = 1; caseNumber <= caseCount; ++caseNumber)
                {
                    string[] s = sr.ReadLine().Split();
                    int D = int.Parse(s[0]);
                    int K = int.Parse(s[1]);
                    s = sr.ReadLine().Split();
                    int[] ss = new int[K];
                    for (int i = 0; i < K; ++i)
                        ss[i] = int.Parse(s[i]);
                    string res = solve(K, D, ss);

                    sw.WriteLine("Case #" + caseNumber.ToString() + ": " + res);
                }
            }

        }
    }
}
