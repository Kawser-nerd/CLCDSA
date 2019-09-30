using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace CodeJamB
{
    class HotDog
    {
        static void Main(string[] args)
        {
            var file = File.OpenText(args[0]);

            using (var outFile = new StreamWriter(File.Open("output.txt", FileMode.Create)))
            {
                Int64 T = Int64.Parse(file.ReadLine());
                for (Int64 i = 0; i < T; i++)
                {
                    var line = file.ReadLine();
                    string[] puzzle = line.Split(' ');
                    Int64 C = Int64.Parse(puzzle[0]);
                    Int64 D = Int64.Parse(puzzle[1]);

                    Int64 minP = 0;
                    Int64 currPt = 0;
                    Int64 maxTravel = 0;
                    for (Int64 j = 0; j < C; j++)
                    {
                        string[] pt = file.ReadLine().Split(' ');
                        Int64 P = Int64.Parse(pt[0]);
                        Int64 V = Int64.Parse(pt[1]);

                        if (j == 0)
                        {
                            minP = P;
                            currPt = P;
                        }

                        for (Int64 k = 0; k < V; k++)
                        {
                            Int64 travel = currPt - P;
                            if (travel < 0)
                            {
                                travel = 0;
                                currPt = P + D;
                            }
                            else
                                currPt += D;

                            maxTravel = Math.Max(maxTravel, travel);
                        }
                    }

                    string answer = string.Format("Case #{0}: {1}", (i + 1), (double)((double)maxTravel / (double)2));
                    outFile.WriteLine(answer);
                }
            }
        }
    }
}
