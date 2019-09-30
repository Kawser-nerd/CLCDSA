using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace Round1ProblemA
{
    class Program
    {
        static long solve(string s)
        {
            int[] value = new int[128];
            for (int i = 0; i < value.Length; ++i)
                value[i] = -1;
            
            int curval = 1;
            value[s[0]] = 1;
            for (int i = 1; i < s.Length; ++i)
            {
                if (value[s[i]] < 0)
                {
                    value[s[i]] = (curval == 1) ? 0 : curval;
                    ++curval;
                }
            }            
            if (curval < 2)
                curval = 2;

            long res = 0;
            for (int i = 0; i < s.Length; ++i)
                res = res * (long)curval + (long)value[s[i]];
            return res;
        }

        static void Main(string[] args)
        {
            //const string fileName = "test";
            //            const string fileName = "A-small-attempt0";
            const string fileName = "A-large";

            string DataFolder = @"C:\Projects\CSharp\CodeJam2009\Round1ProblemA\Data\";
            StreamReader sr = File.OpenText(DataFolder + fileName + ".in");
            using (StreamWriter sw = File.CreateText(DataFolder + fileName + ".out"))
            {
                int caseCount = int.Parse(sr.ReadLine());
                for (int caseNumber = 1; caseNumber <= caseCount; ++caseNumber)
                {
                    string s = sr.ReadLine();
                    long res = solve(s);
                    sw.WriteLine("Case #" + caseNumber.ToString() + ": " + res.ToString());
                }
            }
        }
    }
}
