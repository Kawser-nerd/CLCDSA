using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace quest2
{
    class Program
    {
        static System.IO.StreamReader reader;
        static System.IO.StreamWriter writer;

        static void Main(string[] args)
        {
            reader = new System.IO.StreamReader("input.txt");
            writer = new System.IO.StreamWriter("output.txt");


            long T = long.Parse(reader.ReadLine());

            for (long i = 0; i < T; i++)
            {
                string[] tok = reader.ReadLine().Split();
                long N = long.Parse(tok[0]);
                long K = long.Parse(tok[1]);
                double U = double.Parse(reader.ReadLine());
                List<double> list = new List<double>();
                tok = reader.ReadLine().Split();
                for (long j = 0; j < N; j++)
                {
                    list.Add(double.Parse(tok[j]));
                }
                list.Sort();// from small to big
                list.Add(1.0);
                for (int n = 0; n < (list.Count() - 1) && U > 0; n++)
                {
                    if (list[n] < list[n + 1])
                    {
                        double demand = (list[n + 1] - list[n]) * (n + 1);
                        if (U > demand)
                        {
                            U -= demand;
                            for (int m = 0; m <= n; m++)
                            {
                                list[m] = list[n + 1];
                            }
                        }
                        else
                        {
                            for (int m = 0; m <= n; m++)
                            {
                                list[m] += U/(double)(n+1);
                            }
                            U = 0;
                        }
                    }
                }
                double score = 1.0;
                foreach (double d in list)
                {
                    score *= d;
                }

                writer.WriteLine("Case #" + (i + 1) + ": " + score);

            }
            reader.Close();
            writer.Close();
        }
    }
}