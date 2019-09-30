using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace Round2ProblemC
{
    class Program
    {
        static void Main(string[] args)
        {
            //const string fileName = "test";
            const string fileName = "C-small-attempt0";
            //const string fileName = "C-large";

            string DataFolder = @"C:\Projects\CSharp\CodeJam2010\Round2ProblemC\Data\";
            StreamReader sr = File.OpenText(DataFolder + fileName + ".in");
            using (StreamWriter sw = File.CreateText(DataFolder + fileName + ".out"))
            {
                int caseCount = int.Parse(sr.ReadLine());

                for (int caseNumber = 1; caseNumber <= caseCount; ++caseNumber)
                {
                    int R = int.Parse(sr.ReadLine());
                    int minX = 100;
                    int minY = 100;
                    int maxX = 0;
                    int maxY = 0;
                    bool[,] p = new bool[101, 101];
                    int total = 0;
                    for (int i = 0; i < R; ++i)
                    {
                        string[] s = sr.ReadLine().Split();
                        int x1 = int.Parse(s[0]);
                        int y1 = int.Parse(s[1]);
                        int x2 = int.Parse(s[2]);
                        int y2 = int.Parse(s[3]);
                        maxX = Math.Max(maxX, x2);
                        maxY = Math.Max(maxY, y2);
                        minX = Math.Min(minX, x1);
                        minY = Math.Min(minY, y1);
                        for (int y = y1; y <= y2; ++y)
                            for (int x = x1; x <= x2; ++x)
                                if (!p[y, x])
                                {
                                    total++;
                                    p[y, x] = true;
                                }
                    }

                    int time = 0;
                    while (total > 0)
                    {
                        time++;
                        total = 0;
                        for (int y = maxY; y >= minY; --y)
                            for (int x = maxX; x >= minX; --x)
                                if (p[y, x])
                                {
                                    if (!p[y - 1, x] && !p[y, x - 1])
                                        p[y, x] = false;
                                    else
                                        total++;
                                }
                                else
                                {
                                    if (p[y - 1, x] && p[y, x - 1])
                                    {
                                        p[y, x] = true;
                                        total++;
                                    }
                                }
                    }

                    sw.WriteLine("Case #" + caseNumber.ToString() + ": " + time.ToString());
                }
            }
        }
    }
}
