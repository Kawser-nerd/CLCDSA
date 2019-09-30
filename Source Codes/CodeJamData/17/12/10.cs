using System;
using System.IO;
using System.Linq;

namespace B
{
    class Program
    {
        static void Main(string[] args)
        {
            using (StreamReader sr = new StreamReader(@"..\..\b.in"))
            using (StreamWriter sw = new StreamWriter(@"..\..\b.out"))
            {
                int testcount = int.Parse(sr.ReadLine());

                for (int t = 1; t <= testcount; t++)
                {
                    string[] input = sr.ReadLine().Split(' ');
                    int N = int.Parse(input[0]);
                    int P = int.Parse(input[1]);
                    int[] Weights = Array.ConvertAll(sr.ReadLine().Split(' '), int.Parse);
                    double[][] Counts = Enumerable.Range(0, N).Select(i => Array.ConvertAll(sr.ReadLine().Split(' '), s => double.Parse(s) / Weights[i])).ToArray();
                    for (int i = 0; i < N; i++) Array.Sort(Counts[i]);

                    int res = 0;
                    int maxptr = 0;
                    int[] ptrs = new int[N];

                    Func<bool> satisfy = () =>
                    {
                        double lower = double.MinValue;
                        double upper = double.MaxValue;
                        for (int i = 0; i < N; i++)
                        {
                            double l = Counts[i][ptrs[i]] / 1.1;
                            double u = Counts[i][ptrs[i]] / 0.9;

                            lower = Math.Max(lower, l);
                            upper = Math.Min(upper, u);
                        }

                        return Math.Ceiling(lower) <= Math.Floor(upper);
                    };

                    while (maxptr < P)
                    {
                        if (satisfy())
                        {
                            res++;
                            for (int i = 0; i < N; i++) ptrs[i]++;
                            maxptr++;
                        }
                        else
                        {
                            double minvalue = Enumerable.Range(0, N).Min(i => Counts[i][ptrs[i]]);
                            int minindex = Enumerable.Range(0, N).First(i => Counts[i][ptrs[i]] == minvalue);

                            maxptr = Math.Max(maxptr, ptrs[minindex] = ptrs[minindex] + 1);

                            //if (maxptr >= P) break;
                        }
                    }

                    sw.WriteLine($"Case #{t}: {res}");
                }
            }
        }
    }
}