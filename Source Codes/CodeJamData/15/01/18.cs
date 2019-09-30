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
            string inputFile = @"e:\codejam\A-large.in";
            string outputFile = @"e:\codejam\A-large.out";

            using (StreamReader sr = new StreamReader(inputFile))
            {
                using (StreamWriter sw = new StreamWriter(outputFile))
                {
                    int T = int.Parse(sr.ReadLine());
                    for (int i1 = 1; i1<=T; ++i1)
                    {
                        string line = sr.ReadLine();
                        string count = line.Split(' ')[1];


                        int total = 0;
                        int add = 0;

                        for (int i = 0; i < count.Length; ++i)
                        {
                           int val = int.Parse(count[i].ToString());
                           if (total < i && val > 0) 
                           {
                               add += i-total;
                               total = i;
                           };
                           total += val;
                        };

                        sw.WriteLine("Case #{0}: {1}", i1, add);
                    }
                }
            }
        }
    }
}
