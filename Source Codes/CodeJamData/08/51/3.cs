using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Diagnostics;

namespace Round3ProblemA
{
    class Program
    {
        static int[] dx = { 0, 1, 0, -1 };
        static int[] dy = { 1, 0, -1, 0 };

        static void Main(string[] args)
        {
            //const string fileName = "test";
            //const string fileName = "A-small-attempt0";
            const string fileName = "A-large";
            string DataFolder = @"C:\Projects\CSharp\CodeJam2008\Round3ProblemA\Data\";
            StreamReader sr = File.OpenText(DataFolder + fileName + ".in");
            using (StreamWriter sw = File.CreateText(DataFolder + fileName + ".out"))
            {
                int caseCount = int.Parse(sr.ReadLine());
                for (int caseNumber = 1; caseNumber <= caseCount; ++caseNumber)
                {
                    int L = int.Parse(sr.ReadLine());
                    int MAX_VAL = 4000;
                    int[,] mX = new int[6500, 2];
                    int[,] mY = new int[6500, 2];
                    for (int i = 0; i < 6500; ++i)
                    {
                        mX[i, 0] = MAX_VAL;
                        mX[i, 1] = -MAX_VAL;
                        mY[i, 0] = MAX_VAL;
                        mY[i, 1] = -MAX_VAL;
                    }
                    int c = 0;
                    int x0 = 0;
                    int y0 = 0;
                    int minX = 0;
                    int minY = 0;
                    int maxX = 0;
                    int maxY = 0;
                    int dir = 0;
                    int S = 0;
                    while (c < L)
                    {
                        string[] s = sr.ReadLine().Split(' ');
                        for (int k = 0; k < s.Length; k += 2)
                        {
                            string st = s[k];
                            int rep = int.Parse(s[k + 1]);
                            for (int m = 0; m < rep; ++m)
                            {
                                for (int j = 0; j < st.Length; ++j)
                                {
                                    switch (st[j])
                                    {
                                        case 'L': dir = (dir + 3) % 4;
                                            break;
                                        case 'R': dir = (dir + 1) % 4;
                                            break;
                                        case 'F':
                                            {
                                                if (dir == 0 || dir == 2)
                                                {
                                                    int line = ((dir == 0) ? y0 : y0 - 1) + 3020;
                                                    mX[line, 0] = Math.Min(mX[line, 0], x0);
                                                    mX[line, 1] = Math.Max(mX[line, 1], x0);
                                                }
                                                else if (dir == 1 || dir == 3)
                                                {
                                                    int line = ((dir == 1) ? x0 : x0 - 1) + 3020;
                                                    mY[line, 0] = Math.Min(mY[line, 0], y0);
                                                    mY[line, 1] = Math.Max(mY[line, 1], y0);
                                                }
                                                S += x0 * (y0 + dy[dir]) - y0 * (x0 + dx[dir]);
                                                x0 += dx[dir];
                                                y0 += dy[dir];
                                                
                                                minX = Math.Min(minX, x0);
                                                minY = Math.Min(minY, y0);
                                                maxX = Math.Max(maxX, x0);
                                                maxY = Math.Max(maxY, y0);
                                                break;
                                            }
                                    }
                                }
                            }
                            c++;
                        }
                    }
                    Debug.Assert(x0 == 0 && y0 == 0);
                    int S1 = 0;
                    for (int x = minX; x <= maxX; ++x)
                        for (int y = minY; y <= maxY; ++y)
                            if ((mY[x + 3020, 0] <= y && y < mY[x + 3020, 1]) || (mX[y + 3020, 0] <= x && x < mX[y + 3020, 1]))
                                S1++;


                    int res = S1 -(Math.Abs(S) / 2);
                    Debug.Assert(res >= 0);

                    sw.WriteLine("Case #" + caseNumber.ToString() + ": " + res);
                }
            }
        }
    }
}
