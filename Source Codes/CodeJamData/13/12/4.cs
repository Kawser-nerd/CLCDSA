using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJam2013_0
{
    class GCJ2013_1AB
    {
        const string fileName = "B-large";
        const string inputFile = fileName + ".in";
        const string outputFile = fileName + ".out";
        StreamReader reader = new StreamReader(inputFile);
        StreamWriter writer = new StreamWriter(outputFile);

        long Solve(List<long> V, long E, long R)
        {
            long result = 0;
            long remaining = E;
            long spendable;
            
            for (int i = 0; i < V.Count; i++)
            {
                if (i == V.Count - 1)
                {
                    result += (V[i] * remaining);
                    break;
                }
                else
                {
                    for (int j = i + 1; j < V.Count; j++)
                    {
                        if (R * (j - i) >= E)
                        {
                            result += (V[i] * remaining);
                            remaining = 0;
                            break;
                        }
                        else if (V[j] > V[i])
                        {
                            spendable = remaining - (E - (R * (j - i)));
                            if (spendable > 0)
                            {
                                result += (V[i] * spendable);
                                remaining -= spendable;
                            }
                            break;
                        }
                        else if (j == V.Count - 1)
                        {
                            result += (V[i] * remaining);
                            remaining = 0;
                            break;
                        }
                    }
                }
                remaining += R;
            }

            return result;
        }

        public GCJ2013_1AB()
        {
            char[] sep = { ' ' };
            int T = Int32.Parse(reader.ReadLine());
            long E, R;
            int N;
            List<long> V = new List<long>();
            for (int i = 0; i < T; i++)
            {
                string[] s = reader.ReadLine().Split(sep);
                E = Int64.Parse(s[0]);
                R = Int64.Parse(s[1]);
                if (R > E) R = E;
                N = Int32.Parse(s[2]);
                s = reader.ReadLine().Split(sep);
                V.Clear();
                for (int j = 0; j < N; j++)
                    V.Add(Int64.Parse(s[j]));

                writer.WriteLine(String.Format("Case #{0}: {1}", (i + 1), Solve(V, E, R)));
            }

            reader.Close();
            writer.Close();
        }

        static void Main(string[] args)
        {
            new GCJ2013_1AB();
        }
    }
}
