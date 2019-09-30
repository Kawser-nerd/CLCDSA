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
                    string[] input = sr.ReadLine().Split(' ');
                    long L = long.Parse(input[0]);
                    long t = long.Parse(input[1]);
                    long N = long.Parse(input[2]);
                    int C = int.Parse(input[3]);

                    long[] c = new long[C];
                    for (int i = 0; i < C; i++)
                    {
                        c[i] = long.Parse(input[i + 4]);
                    }

                    LinkedList<long> distances = new LinkedList<long>();
                    int index = 0;
                    long totalTime = 0;
                    for (int i = 0; i < N; i++)
                    {
                        distances.AddLast(c[index]);
                        totalTime += (c[index] * 2);
                        index++;
                        index %= C;
                    }


                    if (L != 0)
                    {
                        while (t > 0 && distances.Count > 0)
                        {
                            if (distances.First.Value * 2 < t)
                            {
                                t -= (distances.First.Value * 2);
                                distances.RemoveFirst();
                            }
                            else
                            {
                                distances.First.Value -= (long)(t / 2);
                                t = 0;
                            }
                        }

                        List<long> remainingDistances = distances.ToList();
                        remainingDistances.Sort();
                        remainingDistances.Reverse();
                        for (int i = 0; i < L && i < remainingDistances.Count; i++)
                        {
                            totalTime -= remainingDistances[i];
                        }
                    }

                    Console.WriteLine("Case #{0}: {1}", testNumber, totalTime);
                    sw.WriteLine("Case #{0}: {1}", testNumber, totalTime);
                }
            }
        }
    }
}
