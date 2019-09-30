using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Round1_ProblemC
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
                    int P = int.Parse(splits[0]);
                    int K = int.Parse(splits[1]);
                    int L = int.Parse(splits[2]);
                    splits = sr.ReadLine().Split(' ');
                    List<int> list = new List<int>();
                    foreach (string s in splits)
                        list.Add(int.Parse(s));
                    list.Sort();
                    list.Reverse();

                    List<List<int>> ans = new List<List<int>> ();
                    for (int j = 0; j < K; j++)
                    {
                        ans.Add(new List<int>());
                    }

                    foreach (int j in list)
                    {
                        int minPos = 0;
                        for(int l = 1; l < ans.Count; l++)
                        {
                            List<int> sub = ans[l];
                            if (sub.Count > P)
                                continue;

                            if (ans[minPos].Count > sub.Count)
                                minPos = l;
                        }

                        ans[minPos].Add(j);
                    }
                    
                    long ansCount = 0;
                    foreach (List<int> sub in ans)
                    {
                        for(int w = 1; w <= sub.Count; w++)
                            ansCount += (long)w * sub[w-1];
                    }

                    sw.WriteLine("Case #{0}: {1}", i, ansCount.ToString());
                }
            }
        }
    }
}
