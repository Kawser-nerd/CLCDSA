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
            string infile_name = @"F:\!!!20080705\GoogleCodeJam\Program2.0\GCodeJam\2A-B-Milkshakes\B-small-attempt0.in.txt";

            string outfile_name = @"F:\!!!20080705\GoogleCodeJam\Program2.0\GCodeJam\2A-B-Milkshakes\B-small-attempt0.out.txt";

            StreamWriter sw = new StreamWriter(outfile_name);

            StreamReader sr = new StreamReader(infile_name);
            string line;
            line = sr.ReadLine();
            int C = Convert.ToInt32(line.Trim());

            for (int i = 0; i < C; i++)
            {
                line = sr.ReadLine();
                int N = Convert.ToInt32(line.Trim());
                line = sr.ReadLine();
                int M = Convert.ToInt32(line.Trim());

                int[][,] customer = new int[M][,];
                int[] cust_T = new int[M];
                for (int j = 0; j < M; j++)
                {
                    customer[j] = new int[N, 2];
                    for (int k = 0; k < N; k++)
                    {
                        customer[j][k, 0] = 0;
                        customer[j][k, 1] = 0;
                    }
                    line = sr.ReadLine().Trim();
                    string[] ss = line.Split(' ');
                    cust_T[j] = Convert.ToInt32(ss[0]);
                    for (int k = 0; k < cust_T[j]; k++)
                    {
                        int x = Convert.ToInt32(ss[1 + k * 2]);
                        int y = Convert.ToInt32(ss[2 + k * 2]);
                        customer[j][x - 1, y] = 1;
                    }
                }

                int min_j = 0;
                int min_value = 10000;
                int[] fl = new int[N];
                for (int j = 0; j < (1 << N); j++)
                {
                    int my_value = 0;
                    for (int k = 0; k < N; k++)
                    {
                        if ((j & (1 << k)) != 0)
                        {
                            fl[k] = 1;
                            my_value++;
                        }
                        else
                        {
                            fl[k] = 0;
                        }
                    }
                    if (my_value >= min_value) continue;

                    for (int k = 0; k < M; k++)
                    {
                        bool flag = false;
                        for (int k1 = 0; k1 < N; k1++)
                        {
                            if ((customer[k][k1, 0] == 1 && fl[k1] == 0) ||
                                (customer[k][k1, 1] == 1 && fl[k1] == 1))
                            {
                                flag = true;
                                break;
                            }
                        }
                        if (flag == false)
                        {
                            my_value = 10000;
                            break;
                        }
                    }

                    if (my_value < min_value)
                    {
                        min_value = my_value;
                        min_j = j;
                    }
                }

                sw.Write("Case #{0}: ", i + 1);
                if (min_value == 10000)
                {
                    sw.WriteLine("IMPOSSIBLE");
                }
                else
                {
                    string s = "";
                    for (int k = 0; k < N; k++)
                    {
                        if ((min_j & (1 << k)) != 0)
                        {
                            s += "1 ";
                        }
                        else
                        {
                            s += "0 ";
                        }
                    }
                    sw.WriteLine(s.Substring(0, s.Length - 1));
                }
            }
            /************************************************/



            /************************************************/

            sw.Flush();
            sw.Close();
        }

        
    }
}

