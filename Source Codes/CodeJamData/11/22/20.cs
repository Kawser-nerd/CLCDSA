using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Template
{
    public class Program
    {
        private const string InputFileName = @"C:\disk\input.in";
        private const string OutputFileName = @"C:\disk\output.out";

        public static void Main()
        {
            using (StreamReader sr = new StreamReader(InputFileName))
            using (StreamWriter sw = new StreamWriter(OutputFileName))
            {
                long numberOfTests = long.Parse(sr.ReadLine());
                for (long testNumber = 1; testNumber <= numberOfTests; testNumber++)
                {
                    string[] line = sr.ReadLine().Split(' ');
                    long pointsWithVendors = long.Parse(line[0]);
                    long minimumDistance = long.Parse(line[1]);
                    List<decimal> vendors = new List<decimal>();
                    for (long i = 0; i < pointsWithVendors; i++)
                    {
                        line = sr.ReadLine().Split(' ');
                        long p = long.Parse(line[0]);
                        long v = long.Parse(line[1]);
                        for (long j = 0; j < v; j++)
                        {
                            vendors.Add(p);
                        }
                    }
                    vendors.Sort();
                    decimal time = 0;
                    bool done = CheckIfDone(vendors, minimumDistance);
                    while (!done)
                    {
                        vendors[0] -= 0.5m;
                        for (int i = 1; i < vendors.Count - 1; i++)
                        {
                            decimal leftDistance = vendors[i] - vendors[i - 1];
                            decimal rightDistance = vendors[i + 1] - vendors[i];
                            if (leftDistance > minimumDistance)
                            {
                                vendors[i] -= 0.5m;
                            }
                            else if (rightDistance > minimumDistance + 0.5m)
                            {
                                vendors[i] += 0.5m;
                            }
                            else if (leftDistance > rightDistance)
                            {
                                vendors[i] -= 0.5m;
                            }
                            else if (leftDistance < rightDistance)
                            {
                                vendors[i] += 0.5m;
                            }
                        }
                        vendors[vendors.Count - 1] += 0.5m;
                        time += 0.5m;
                        done = CheckIfDone(vendors, minimumDistance);
                    }
                    Console.WriteLine("Case #{0}: {1}", testNumber, time);
                    sw.WriteLine("Case #{0}: {1}", testNumber, time);
                }
            }
        }

        private static bool CheckIfDone(List<decimal> vendors, long distance)
        {
            bool done = true;
            for (int i = 1; i < vendors.Count - 1; i++)
            {
                if (vendors[i] - vendors[i - 1] < distance ||
                    vendors[i + 1] - vendors[i] < distance)
                {
                    done = false;
                    break;
                }
            }
            return done;
        }
    }
}
