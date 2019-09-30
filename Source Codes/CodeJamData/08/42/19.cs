using System;
using System.Collections.Generic;
using System.IO;

namespace GCJ
{
    class Program
    {
        static void Main(string[] args)
        {
            new Program().Run();
        }

        void Run()
        {
            StreamReader sr = File.OpenText(@"d:\b-small-attempt0.in");
            int T = int.Parse(sr.ReadLine());
            
            for (int t = 0; t < T; t++)
            {
                string[] ss = sr.ReadLine().Split();
                long N = long.Parse(ss[0]), M = long.Parse(ss[1]), A = long.Parse(ss[2]);
                bool done = false;
                for (int x1 = 0; !done && x1 <= N; x1++)
                    for (int y1 = 0; !done && y1 <= M; y1++)
                        for (int x2 = 0; !done && x2 <= N; x2++)
                            for (int y2 = 0; !done && y2 <=M; y2++)
                                if (Math.Abs(x1 * y2 - x2 * y1) == A)
                                {
                                    Console.WriteLine("Case #" + (t + 1) + ": 0 0 " + x1 + " " + y1 + " " + x2 + " " + y2);
                                    done = true;
                                }
                if (!done) Console.WriteLine("Case #" + (t + 1) + ": IMPOSSIBLE");
            }
            sr.Close();
        }
   }
}