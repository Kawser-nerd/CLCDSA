using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace Round2ProblemA
{
    class Program
    {
        static void Main(string[] args)
        {
            //const string fileName = "test";
            //const string fileName = "A-small-attempt0";
            const string fileName = "A-large";

            string DataFolder = @"C:\Projects\CSharp\CodeJam2009\Round2ProblemA\Data\";
            StreamReader sr = File.OpenText(DataFolder + fileName + ".in");
            using (StreamWriter sw = File.CreateText(DataFolder + fileName + ".out"))
            {
                int caseCount = int.Parse(sr.ReadLine());
                for (int caseNumber = 1; caseNumber <= caseCount; ++caseNumber)
                {
                    int N = int.Parse(sr.ReadLine());
                    int[] a = new int[N];
                    for (int i = 0; i < N; ++i)
                    {
                        string s = sr.ReadLine();
                        int k = s.Length - 1;
                        while (k >= 0 && s[k] == '0')  --k;
                        a[i]= k;
                    }
                    int res = 0;
                    for (int i = 0; i < N; ++i)
                    {
                        if (a[i] > i)
                        {
                            int k = i + 1;
                            while (a[k] > i) ++k;
                            int ak = a[k];
                            for (int j = k - 1; j >= i; --j)
                                a[j + 1] = a[j];
                            a[i] = ak;
                            res += k - i;
                        }
                    }
                    sw.WriteLine("Case #" + caseNumber.ToString() + ": " + res.ToString());
                }
            }
        }
    }
}
