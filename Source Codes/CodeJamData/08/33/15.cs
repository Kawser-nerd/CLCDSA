using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Round1_ProblemA
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length != 2)
            {
                return;
            }

            using (StreamReader sr = new StreamReader(args[0]))
            using (StreamWriter sw = new StreamWriter(args[1]))
            {
                int caseCount = int.Parse(sr.ReadLine());
                for (int i = 1; i <= caseCount; i++)
                {
                    string line = sr.ReadLine();
                    string[] splits = line.Split(' ');
                    long n = long.Parse(splits[0]);
                    long m = long.Parse(splits[1]);
                    long X = long.Parse(splits[2]);
                    long Y = long.Parse(splits[3]);
                    long Z = long.Parse(splits[4]);
                    List<long> A = new List<long>();
                    for (long j = 0; j < m; j++)
                    {
                        A.Add(long.Parse(sr.ReadLine()));
                    }
                    List<long> list = new List<long>();
                    for (long j = 0; j < n; j++)
                    {
                        list.Add(A[(int)(j % m)]);
                        A[(int)(j % m)] = (X * A[(int)(j % m)] + Y * (j + 1)) % Z;
                    }

                    List<long> q = new List<long>();
                    for (long j = 0; j < list.Count; j++)
                    {
                        q.Add(1);
                    }

                    for (int j = list.Count - 1; j >= 0; j--)
                    {
                        for (int p = list.Count - 1; p > j; p--)
                        {
                            if (list[j] < list[p])
                            {
                                q[j] += q[p];
                                if (q[j] >= 1000000007)
                                {
                                    q[j] = q[j] % 1000000007;
                                }
                            }
                        }
                    }

                    long ans = 0;
                    for(int j = 0; j < q.Count; j++)
                    {
                        ans += q[j];

                        if (ans >= 1000000007)
                            ans = ans % 1000000007;
                    }

                    string result = ans.ToString();
                    sw.WriteLine("Case #{0}: {1}", i, result);
                }
            }
        }
    }
}
