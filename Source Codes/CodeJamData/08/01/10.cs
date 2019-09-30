using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace GCodeJam
{
    class Program
    {
        static void Main(string[] args)
        {
            DateTime dt1 = DateTime.Now;

            Program.Call();

            DateTime dt2 = DateTime.Now;
            TimeSpan ts2 = dt2.Subtract(dt1);
            Console.WriteLine("time: {0} ms", ts2.TotalMilliseconds);
        }

        static void Call()
        {
            MyProblem mp = new MyProblem();
            mp.run();
        }
    }

    class MyProblem
    {
        public void run()
        {
            string infile_name = @"F:\!!!20080705\GoogleCodeJam\Program2.0\GCodeJam\1-A-Saving the Universe\A-large.in.txt";

            StreamReader sr = new StreamReader(infile_name);
            string line;
            line = sr.ReadLine();
            int N = Convert.ToInt32(line);
            int[] min_switch = new int[N];

            for (int i = 0; i < N; i++)
            {
                line = sr.ReadLine();
                int S = Convert.ToInt32(line);
                string[] search_engine = new string[S];
                for (int j = 0; j < S; j++)
                {
                    search_engine[j] = sr.ReadLine();
                }
                line = sr.ReadLine();
                int Q = Convert.ToInt32(line);
                string[] query = new string[Q];
                for (int j = 0; j < Q; j++)
                {
                    query[j] = sr.ReadLine();
                }

                int[] i_query = new int[Q];
                for (int j = 0; j < Q; j++)
                {
                    for (int k = 0; k < S; k++)
                    {
                        if (query[j] == search_engine[k])
                        {
                            i_query[j] = k;
                            break;
                        }
                    }
                }

                int[,] dp = new int[Q + 1, S];
                for (int j = 0; j <= Q; j++)
                {
                    if (j == 0)
                    {
                        for (int k = 0; k < S; k++)
                        {
                            dp[j, k] = 0;
                        }
                    }
                    else
                    {
                        for (int k = 0; k < S; k++)
                        {
                            if (k == i_query[j-1])
                            {
                                dp[j, k] = 10000;//impossible case
                            }
                            else
                            {
                                int t = 10000;
                                for (int l = 0; l < S; l++)
                                {
                                    int t1 = 0;
                                    if (l != k)
                                    {
                                        t1 = dp[j - 1, l] + 1;
                                    }
                                    else
                                    {
                                        t1 = dp[j - 1, l];
                                    }
                                    t = t < t1 ? t : t1;
                                }
                                dp[j, k] = t;
                            }
                        }
                    }
                }

                int ttt = 10000;
                for (int j = 0; j < S; j++)
                {
                    ttt = ttt < dp[Q, j] ? ttt : dp[Q, j];
                }
                min_switch[i] = ttt;
            }

            sr.Close();

            /************************************************/



            /************************************************/

            string outfile_name = @"F:\!!!20080705\GoogleCodeJam\Program2.0\GCodeJam\1-A-Saving the Universe\A-large.out.txt";

            StreamWriter sw = new StreamWriter(outfile_name);
            for (int i = 0; i < N; i++)
            {
                sw.WriteLine("Case #{0}: {1}", i + 1, min_switch[i]);
            }
            sw.Flush();
            sw.Close();
        }
    }
}

