using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Problem4
{
    class Program
    {
        public static bool Solve(int x, int r, int c)
        {
            int w = Math.Min(r, c);
            int h = Math.Max(r, c);

            if (w * h % x != 0)
                return false;



            if (x == 1)
                return true;
            else if (x == 2)
                return true;
            else if (x == 3)
            {
                if (w == 1)
                    return false;
                return true;
            }
            else if (x == 4 )
            {
                if (w <= 2)
                    return false;
                return true;        
            }

            return true;
        }


        static void Main(string[] args)
        {
            string inputFile = @"c:\codejam\D-small-attempt0.in";
            string outputFile = @"c:\codejam\D-small-attempt0.out";

            using (StreamReader sr = new StreamReader(inputFile))
            {
                using (StreamWriter sw = new StreamWriter(outputFile))
                {
                    int T = int.Parse(sr.ReadLine());
                    for (int i1 = 1; i1<=T; ++i1)
                    {
                        string[] line = sr.ReadLine().Split(' ');
                        int x = int.Parse(line[0]);
                        int r = int.Parse(line[1]);
                        int c = int.Parse(line[2]);

                        if (Solve(x, r, c))
                            sw.WriteLine("Case #{0}: GABRIEL", i1);
                        else
                            sw.WriteLine("Case #{0}: RICHARD", i1);

                    }

                }
            }
        }
    }
}
