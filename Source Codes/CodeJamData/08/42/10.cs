using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Diagnostics;

namespace CodeJamSharp
{

    class Program
    {
        static void Main(string[] args)
        {
            using (StreamReader sr = File.OpenText(@"C:\Google\B.in"))
            using (StreamWriter sout = File.CreateText(@"C:\Google\B.out"))
            {
                string line = sr.ReadLine();
                int cases = int.Parse(line);
                for (int cas = 1; cas <= cases; cas++)
                {
                    line = sr.ReadLine();
                    string[] items = line.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                    int N = int.Parse(items[0]);
                    int M = int.Parse(items[1]);
                    int A = int.Parse(items[2]);
                    // Area =  1/2 *  (x2-x1) * (y3-y1) - (x3-x1) * (y2-y1)
                    // A = (x2-x1) * (y3-y1) - (x3-x1) * (y2-y1)                    
                    bool found = false;
                    for(int x1=0;x1<=N && !found;x1++)
                        for (int x2 = 0; x2 <= N && !found; x2++)
                            for (int y1 = 0; y1 <= M && !found; y1++)
                                for (int y2 = 0; y2 <= M && !found; y2++)
                                {
                                    if (A == Math.Abs(x1 * y2 - x2 * y1))
                                    {
                                        sout.WriteLine("Case #{0}: 0 0 {1} {2} {3} {4}", cas, x1,y1,x2,y2);
                                        found = true;
                                    }
                                }

                    if (!found)
                    {
                        sout.WriteLine("Case #{0}: IMPOSSIBLE", cas);
                    }
                }
            }
        }
    }
}
