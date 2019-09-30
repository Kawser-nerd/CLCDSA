using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using System.IO;

namespace TrieSharding
{
    class Program
    {
        static long FindTrieNodes(List<string> strs)
        {
            long total = 1;

            if (strs.Count == 1)
            {
                return strs[0].Length + 1;
            }
            else if (strs.Count == 0)
            {
                return 0;
            }

            Dictionary<char, List<string>> dict = new Dictionary<char, List<string>>();
            for (int i = 0; i < strs.Count; i++)
            {
                if (strs[i].Length == 0) continue;
                if(dict.ContainsKey(strs[i][0])==false)
                {
                    dict[strs[i][0]] = new List<string>();
                }
                dict[strs[i][0]].Add(strs[i].Substring(1));
            }

            foreach (KeyValuePair<char, List<string>> kv in dict)
            {
                total += FindTrieNodes(kv.Value);
            }

            return total;
        }

        static List<int> ConvertNumToVector(long num, int base_, int numDigits)
        {
            List<int> l = new List<int>();
            for (int i = 0; i < numDigits || (numDigits < 0 && num > 0); i++)
            {
                l.Insert(0, (int)(num % base_));
                num /= base_;
            }

            return l;
        }

        static void Main(string[] args)
        {

            //StreamReader sr = new StreamReader("D:\\a.txt");
            //StreamWriter sw = new StreamWriter("D:\\b.txt");

            StreamReader sr = new StreamReader("D:\\D-small-attempt0.in");
            StreamWriter sw = new StreamWriter("D:\\D-small-attempt0.out");

            //StreamReader sr = new StreamReader("D:\\A-large.in");
            //StreamWriter sw = new StreamWriter("D:\\A-large.out");


            int numTestCases = Convert.ToInt32(sr.ReadLine());

            for (int i = 0; i < numTestCases; i++)
            {

                Console.WriteLine(i);

                string[] str = sr.ReadLine().Split(' ');

                int M = Convert.ToInt32(str[0]);
                int N = Convert.ToInt32(str[1]);

                string[] strs = new string[M];

                for (int j = 0; j < M; j++)
                {
                    strs[j] = sr.ReadLine().Split(' ')[0];
                }

                long max = 1;
                for (int j = 0; j < M; j++) max *= N;

                int[] numNodes = new int[max];
                long maxNumNodes = -1;
                long numMaxNumNodes = 0;

                for (int j = 0; j < max; j++)
                {
                    List<int> div = ConvertNumToVector(j, N, M);

                    List<string>[] servers = new List<string>[N];
                    for (int k = 0; k < N; k++)
                    {
                        servers[k] = new List<string>();
                    }

                    for (int k = 0; k < M; k++)
                    {
                        servers[div[k]].Add(strs[k]);
                    }

                    long totalNodes = 0;

                    bool ok = true;
                    for (int k = 0; k < N; k++)
                    {
                        if (servers[k].Count == 0)
                        {
                            ok = false;
                            break;
                        }
                        servers[k].Sort();
                        totalNodes += FindTrieNodes(servers[k]);

                        
                    }

                    if (ok == false)
                    {
                        continue;
                    }

                    if (totalNodes > maxNumNodes)
                    {
                        maxNumNodes =totalNodes;
                        numMaxNumNodes = 1;
                    }
                    else if (totalNodes == maxNumNodes)
                    {
                        numMaxNumNodes++;
                    }
                }


                sw.Write("Case #{0}: ", i + 1);

                sw.Write(maxNumNodes.ToString() + " " + numMaxNumNodes);

                sw.WriteLine();
            }

            sr.Close();
            sw.Close();
        }
    }
}
