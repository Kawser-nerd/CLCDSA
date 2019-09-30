using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Threading.Tasks;

namespace CodeJam2017
{
 
    class Pony
    {
        static void Main(string[] args)
        {
            string[] lines = File.ReadAllLines("input.txt");
            StringWriter output = new StringWriter();

            int n = int.Parse(lines[0]);
            int at = 1;
            for(int i=0;i<n;i++)
            {
                string[] line = lines[at++].Split();
                int N = int.Parse(line[0]);
                int Q = int.Parse(line[1]);
                List<int> horseSpeeds = new List<int>();
                List<int> horseDists = new List<int>();
                long[,] D = new long[N, N];
                for (int j = 0; j < N; j++)
                {
                    string[] line2 = lines[at++].Split();
                    horseDists.Add(int.Parse(line2[0]));
                    horseSpeeds.Add(int.Parse(line2[1]));
                }
                for (int j = 0; j < N; j++)
                {
                    string[] line2 = lines[at++].Split();
                    for (int k = 0; k < N; k++)
                    {
                        D[j, k] = int.Parse(line2[k]);
                    }
                }
                APSP(N, D);
                StringBuilder res = new StringBuilder();
                for (int j = 0; j < Q; j++)
                {
                    string[] line2 = lines[at++].Split();
                    int U = int.Parse(line2[0]) - 1;
                    int V = int.Parse(line2[1]) - 1;
                    double time = (solve(N, horseSpeeds, horseDists, D, U, V));
                    res.Append(time.ToString());
                    if (j < Q - 1) res.Append(" ");
                }


                output.WriteLine("Case #" + (i + 1) + ": " + res);
            }
            File.WriteAllText("output.txt", output.ToString());
            Console.WriteLine(output.ToString());
        }
        static void APSP(int N, long[,] D)
        {
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    for (int k = 0; k < N; k++)
                    {
                        if (D[j, i] != -1 && D[i, k] != -1)
                        {
                            if (D[j, k] == -1 || D[j, i] + D[i, k] < D[j, k])
                            {
                                D[j, k] = D[j, i] + D[i, k];
                            }
                        }
                    }
                }
            }
        }

        static double solve(int N, List<int> speeds, List<int> dists, long[,] D, int u, int v)
        {
            double[] best = new double[N];
            for (int i = 0; i < N; i++) best[i] = -1;
            Queue<int> cities = new Queue<int>();
            Queue<double> ts = new Queue<double>();
            ts.Enqueue(0);
            cities.Enqueue(u);
            while(cities.Count > 0)
            {
                int city = cities.Dequeue();
                double tt = ts.Dequeue();
                if (best[city] != -1 && tt > best[city]) continue;
                if (city == v) continue;
                for (int i = 0; i < N; i++)
                {
                    if (D[city, i] != -1 && dists[city] >= D[city, i] && city != i)
                    {
                        double d = D[city, i];
                        double s = speeds[city];
                        double t = d / s;

                        if (best[i] == -1 || t + tt < best[i])
                        {
                            cities.Enqueue(i);
                            ts.Enqueue(t + tt);
                            best[i] = t + tt;
                        }
                    }
                }
            }
            return best[v];
        }
    }
}
