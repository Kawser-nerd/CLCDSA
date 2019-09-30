using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ10_R1C_01_01
{
    class Program
    {
        static void Main(string[] args)
        {
            string dir = @"C:\Projects\GCJ10\R1C\01\";

            using(StreamReader sr = new StreamReader(dir + "input.in"))
            {
                string readstr;
                readstr = sr.ReadLine();

                int TestCases = int.Parse(readstr);

                using (StreamWriter sw = new StreamWriter(dir + "output.out"))
                {
                    for (int testCnt = 0; testCnt < TestCases; testCnt++)
                    {
                        int intersect = 0;

                        readstr = sr.ReadLine();
                        int NumWires = int.Parse(readstr);
                        string[] strCoords;
                        List<int> aCoords = new List<int>();
                        List<int> bCoords = new List<int>();

                        for (int wireCnt = 0; wireCnt < NumWires; wireCnt++)
                        {
                            readstr = sr.ReadLine();
                            strCoords = readstr.Split(' ');
                            int newA = int.Parse(strCoords[0]);
                            int newB = int.Parse(strCoords[1]);

                            for (int checkCnt = 0; checkCnt < wireCnt; checkCnt++)
                            {
                                if ((aCoords[checkCnt] - newA) * (bCoords[checkCnt] - newB) < 0)
                                    intersect++;
                            }

                            aCoords.Add(newA);
                            bCoords.Add(newB);
                        }

                        sw.WriteLine("Case #{0}: {1}", testCnt + 1, intersect);
                    }
                }
            }
        }
    }
}
