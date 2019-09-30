using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Globalization;

namespace Round2ProblemB
{
    class Program
    {
        static int Solve(int R, int C, long[,] PX, long[,] PY, long[,] DD, long[,] RD)
        {
            int max = Math.Min(R, C);
            for (int res = max; res >= 3; --res)
            {
                for (int y = 0; y + res <= R; ++y)
                    for (int x = 0; x + res <= C; ++x )
                    {
                        long D = DD[y + res, x + res] - DD[y, x + res] - DD[y + res, x] + DD[y, x];
                        D -= RD[y + 1, x + 1] + RD[y + res, x + 1] + RD[y + 1, x + res] + RD[y + res, x + res];
                        long SX = PX[y + res, x + res] - PX[y, x + res] - PX[y + res, x] + PX[y, x];
                        SX -= x * RD[y + 1, x + 1] + x * RD[y + res, x + 1] + (x + res - 1) * RD[y + 1, x + res] + (x + res - 1) * RD[y + res, x + res];
                        if (D * (2 * x + res - 1) == 2 * SX)
                        {
                            long SY = PY[y + res, x + res] - PY[y, x + res] - PY[y + res, x] + PY[y, x];
                            SY -= y * RD[y + 1, x + 1] + (y + res - 1) * RD[y + res, x + 1] + y * RD[y + 1, x + res] + (y + res - 1) * RD[y + res, x + res];
                            if (D * (2 * y + res - 1) == 2 * SY)
                                return res;
                        }
                    }
            }
            return -1;
        }
        static void Main(string[] args)
        {
            //const string fileName = "test";
            //const string fileName = "B-small-attempt0";
            const string fileName = "B-large";

            string DataFolder = @"D:\Projects\CSharp\CodeJam2011\Round2ProblemB\Data\";
            StreamReader sr = File.OpenText(DataFolder + fileName + ".in");
            using (StreamWriter sw = File.CreateText(DataFolder + fileName + ".out"))
            {
                int caseCount = int.Parse(sr.ReadLine());
                for (int caseNumber = 1; caseNumber <= caseCount; ++caseNumber)
                {
                    string[] s = sr.ReadLine().Split();
                    int R = int.Parse(s[0]);
                    int C = int.Parse(s[1]);
                    long D = int.Parse(s[2]);
                    long[,] PX = new long[R + 1, C + 1];
                    long[,] PY = new long[R + 1, C + 1];
                    long[,] DD = new long[R + 1, C + 1];
                    long[,] RD = new long[R + 1, C + 1];
                    for (int y = 0; y < R; ++y)
                    {
                        string line = sr.ReadLine();
                        System.Diagnostics.Debug.Assert(line.Length == C);
                        for (int x = 0; x < C; ++x)
                        {
                            long dig = (line[x] - '0') + D;
                            RD[y + 1, x + 1] = dig;
                            DD[y + 1, x + 1] = DD[y + 1, x] + DD[y, x + 1] - DD[y, x] + dig;
                            PX[y + 1, x + 1] = PX[y + 1, x] + PX[y, x + 1] - PX[y, x] + dig * x;
                            PY[y + 1, x + 1] = PY[y + 1, x] + PY[y, x + 1] - PY[y, x] + dig * y;
                        }
                    }
                    int res = Solve(R, C, PX, PY, DD, RD);
                    sw.WriteLine("Case #" + caseNumber.ToString() + ": " + ((res > 0) ? res.ToString(): "IMPOSSIBLE"));
                }
            }
        }
    }
}
