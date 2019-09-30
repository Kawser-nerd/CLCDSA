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


        static long Count(long x, long[] m)
        {
            long sum = 0;
            for (int i = 0; i<m.Length; ++i)
            {
                sum += (x/m[i])+1;
            }
            return sum;

        }

        static void Main(string[] args)
        {
            string inputFile = @"e:\codejam\2015round1a\B-large.in";
            string outputFile = @"E:\codejam\2015round1a\B-large.out";

            using (StreamReader sr = new StreamReader(inputFile))
            {
                using (StreamWriter sw = new StreamWriter(outputFile))
                {
                    int T = int.Parse(sr.ReadLine());
                    for (int i1 = 1; i1 <= T; ++i1)
                    {
                        var temp1 = sr.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
                        long b = temp1[0];
                        long n = temp1[1];

                        long[] m = sr.ReadLine().Split(' ').Select(x => long.Parse(x)).ToArray();


                        long low = 0, high = n*m.Max();

                        while (low < high)
                        {
                            long mid = (low + high) / 2;
                            long count = Count(mid, m);
                            if (count >= n)
                            {
                                high = mid;
                            }
                            else
                            {
                                low = mid + 1;
                            }
                        };
                        
                        long count2 = Count(low, m);
                        long last = Count(low-1,m);
                        Console.WriteLine("{0} {1} {2} {3}", count2, last, n, low);

                        List<int> d = new List<int>();
                        for (int i = 0; i < m.Length; ++i)
                            if (low % m[i] == 0)
                            {
                                d.Add(i+1);
                            }
                        
                        d.Reverse();

                        int ans = d[(int)(count2 - n)];
                   
                        sw.WriteLine("Case #{0}: {1}", i1, ans);
                    }

                }
            }
        }
    }
}
