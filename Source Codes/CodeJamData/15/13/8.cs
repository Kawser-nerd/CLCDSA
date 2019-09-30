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

        static long CrossProduct(long[] o, long[] a, long[] b)
        {
            return (a[0] - o[0]) * (b[1] - o[1]) - (a[1] - o[1]) * (b[0] - o[0]);
        }

        static long Count(long x, long[] m)
        {
            long sum = 0;
            for (int i = 0; i < m.Length; ++i)
            {
                sum += (x / m[i]) + 1;
            }
            return sum;

        }

        static void Main(string[] args)
        {
            string inputFile = @"e:\codejam\2015round1a\C-small-attempt1.in";
            string outputFile = @"E:\codejam\2015round1a\C-small-attempt1.out";

            using (StreamReader sr = new StreamReader(inputFile))
            {
                using (StreamWriter sw = new StreamWriter(outputFile))
                {
                    int T = int.Parse(sr.ReadLine());
                    for (int i1 = 1; i1 <= T; ++i1)
                    {
                        int n = int.Parse(sr.ReadLine());

                        List<long[]> points = new List<long[]>();
                        for (int i = 0; i < n; ++i)
                        {
                            string line = sr.ReadLine();
                            long[] point = line.Split(' ').Select(x => long.Parse(x)).ToArray();
                            points.Add(point);
                        };

                        if (n == 1)
                        {
                            sw.WriteLine("Case #{0}:", i1);
                            sw.WriteLine("0");
                            continue;
                        }
                        int[] results = new int[n];
                        
                        for (int i=0; i< n; ++i)                        
                        {
                            int min = int.MaxValue;
                            for (int j = 0; j < n; ++j )
                            {
                                int ans = 0;
                                if (j == i) continue;
                                for (int k = 0; k < n; ++k)
                                {
                                    if (k == i || k == j) continue;
                                    if (CrossProduct(points[j], points[i], points[k]) > 0)
                                    {
                                        ans++;
                                    }
                                }
                                ans = Math.Min(n - 2 - ans, ans);
                                if (ans < min)
                                    min = ans;
                            }
                            results[i] = min;
                        };

                        sw.WriteLine("Case #{0}:", i1);
                        for (int i = 0; i < n; ++i)
                            sw.WriteLine("{0}", results[i]);                            
                    }

                }
            }
        }
    }
}
 