using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace gcj15r2
{
    class Program
    {
        static void Main(string[] args)
        {
            {
                string root = @"C:\GCJ\";
                string problem = "B";
                string ptype = "small-attempt0";
                //string ptype = "Large";

                string[] lines = System.IO.File.ReadAllLines(string.Format("{0}{1}-{2}.in", root, problem, ptype));
                TextWriter tw = new StreamWriter(string.Format("{0}{1}-{2}.out", root, problem, ptype));

                int idx = 0;
                int t = int.Parse(lines[idx++]);
                for (int a = 0; a < t; a++)
                {
                    string[] line = lines[idx++].Split(' ');
                    int N = int.Parse(line[0]);
                    double V = double.Parse(line[1]);
                    double X = double.Parse(line[2]);
                    double[] rates = new double[N];
                    double[] temps = new double[N];
                    bool poss = true;
                    double ans = 0;
                    for (int b = 0; b < N; b++)
                    {
                       string[] curline = lines[idx++].Split(' ');
                       rates[b] = double.Parse(curline[0]);
                       temps[b] = double.Parse(curline[1]);
                    }
                    if (N == 1)
                    {
                        if (temps[0] == X)
                        {
                            ans = V / rates[0];
                        }
                        else
                        {
                            poss = false;
                        }
                    }
                    else if (temps[0] < X && temps[1] < X)
                    {
                        poss = false;
                    }
                    else if (temps[0] > X && temps[1] > X)
                    {
                        poss = false;
                    }
                    else if (temps[0] == X || temps[1] == X)
                    {
                        double rate = 0;
                        if (temps[0] == X)
                        {
                            rate += rates[0];
                        }
                        if (temps[1] == X)
                        {
                            rate += rates[1];
                        }
                        ans = V / rate;
                    }
                    else
                    {
                        double vol1 = V * (temps[0] - X) / (temps[0] - temps[1]);
                        double vol0 = V - vol1;
                        double time1 = vol1 / rates[1];
                        double time2 = vol0 / rates[0];
                        ans = Math.Max(time1, time2);
                    }

                    tw.WriteLine("Case #{0}: {1}", a + 1, (poss ? ans.ToString() : "IMPOSSIBLE"));
                }

                tw.Close();
            }
        }
    }
}
