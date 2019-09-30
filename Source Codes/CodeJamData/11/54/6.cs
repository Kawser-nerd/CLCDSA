using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Globalization;

namespace Round3ProblemD
{
    class Program
    {
        static bool IsSquare(long v)
        {
            long d = (long)(Math.Sqrt(v) + 0.4);
            return d * d == v;
        }
        
        static long solveEasy(long sq, long mask)
        {
            long v = 0;
            if (IsSquare(sq))
                return sq;
            while (v != mask)
            {
                v = ((v | (~mask)) + 1) & mask;
                if (IsSquare(sq | v))
                    return sq | v;
            }
            System.Diagnostics.Debug.Assert(false, "no solution");
            return sq;
        }

        static void Main(string[] args)
        {
            //const string fileName = "test";
            const string fileName = "D-small-attempt0";
            //const string fileName = "D-large";

            string DataFolder = @"D:\Projects\CSharp\CodeJam2011\Round3ProblemD\Data\";
            StreamReader sr = File.OpenText(DataFolder + fileName + ".in");
            using (StreamWriter sw = File.CreateText(DataFolder + fileName + ".out"))
            {
                int caseCount = int.Parse(sr.ReadLine());
                for (int caseNumber = 1; caseNumber <= caseCount; ++caseNumber)
                {
                    string s = sr.ReadLine();
                    long sq = 0;
                    long mask = 0;
                    for (int i = 0; i < s.Length; ++i)
                    {
                        mask <<= 1;
                        sq <<= 1;
                        if (s[i] == '?')
                            mask++;
                        else if (s[i] == '1')
                            sq++;
                    }
                    long res = solveEasy(sq, mask);
                    s = "";
                    while (res > 0)
                    {
                        if ((res & 1) != 0)
                            s = "1" + s;
                        else
                            s = "0" + s;
                        res >>= 1;
                    }
                    sw.WriteLine("Case #" + caseNumber.ToString() + ": " + s);
                }
            }
        }
    }
}
