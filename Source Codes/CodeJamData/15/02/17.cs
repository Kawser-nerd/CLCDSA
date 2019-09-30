using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace ProblemA
{
    class Program
    {
        static void Main(string[] args)
        {
            string inputFile = @"e:\codejam\B-large.in";
            string outputFile = @"e:\codejam\B-large.out";

            using (StreamReader sr = new StreamReader(inputFile))
            {
                using (StreamWriter sw = new StreamWriter(outputFile))
                {
                    int T = int.Parse(sr.ReadLine());
                    for (int i1 = 1; i1 <= T; ++i1)
                    {
                        string line = sr.ReadLine();
                        line = sr.ReadLine();

                        List<int> d = line.Split(' ').Select(x => int.Parse(x)).ToList();

                        int maxD = d.Max();
                        int min = int.MaxValue;
                        for (int target = 1; target <= maxD; ++target)
                        {
                            int extra = 0;
                            for (int i = 0; i < d.Count; ++i)
                                if (d[i] > target)
                                {
                                    extra += (int)(d[i] / target)-1;
                                    if ((d[i] % target) != 0)
                                        extra += 1;
                                }
                            if (extra + target < min)
                                min = extra + target;
                        }

                        sw.WriteLine("Case #{0}: {1}", i1, min);
                    }
                }
            }
        }
    }
}
