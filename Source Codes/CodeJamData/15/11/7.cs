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
        static void Solve()
        {
            
        }


        static void Main(string[] args)
        {
            string inputFile = @"e:\codejam\2015round1a\A-large.in";
            string outputFile = @"E:\codejam\2015round1a\A-large.out";

            using (StreamReader sr = new StreamReader(inputFile))
            {
                using (StreamWriter sw = new StreamWriter(outputFile))
                {
                    int T = int.Parse(sr.ReadLine());
                    for (int i1 = 1; i1<=T;++i1)
                    {
                        int n = int.Parse(sr.ReadLine());
                        int[] m = sr.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();

                        long ans1 = 0;
                        for (int i = 1; i<n; ++i)
                            if (m[i] < m[i-1])
                                ans1 +=  m[i-1]-m[i];


                        long ans2 = long.MaxValue;
                        for (int k=0;k<=200000;++k)
                        {
                           bool valid = true;
                           long sum = 0;
                           for (int i = 1; i < n; ++i)
                           {
                               long after = Math.Max(m[i-1]-k, 0);

                               if (m[i] < after)
                               {
                                   valid = false;
                                  break;
                               }
                               else {
                                   sum += m[i-1]-after;
                               }
                           }
                            if (valid && sum < ans2)
                                ans2 = sum;                           
                        }

                        sw.WriteLine("Case #{0}: {1} {2}", i1, ans1, ans2);
                    }

                }
            }
        }
    }
}
