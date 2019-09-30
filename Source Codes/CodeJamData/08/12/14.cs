using System;
using System.Collections.Generic;
using System.Text;

namespace t2
{
    class Program
    {
        static void Main(string[] args)
        {
            int T;
            T = int.Parse(Console.ReadLine());

            //MAX M = 100
            //MAX N = 10;

            int N, M;
            int[] like = new int[200];

            List<int>[] m_x = new List<int>[200];
            List<int>[] m_y = new List<int>[200];
            for (int c = 1; c <= T; c++)
            {
                N = int.Parse(Console.ReadLine());
                M = int.Parse(Console.ReadLine());

                for (int im = 0; im < M; im++)
                {
                    string[] ss = Console.ReadLine().Split(' ');
                    int tm = int.Parse(ss[0]);
                    //make vectors

                    m_x[im] = new List<int>();
                    m_y[im] = new List<int>();
                    for (int i = 0; i < tm; i++)
                    {
                        int X = int.Parse(ss[i * 2 + 1])-1;
                        int Y = int.Parse(ss[i * 2 + 2]);
                        m_x[im].Add(X);
                        m_y[im].Add(Y);
                    }
                }


                int minimum = int.MaxValue;
                int ans_v = 0;
                for (int mask = 0; mask < (1 << N); mask++) // brute force
                {
                    int cnt = 0;
                    for (int j = 0; j < N; j++) if ((mask & (1 << j)) > 0) cnt++;
                    if (cnt >= minimum) continue; // not valid

                    bool flag = true;

                    for (int i = 0; i < M; i++) //check everybody
                    {
                        //int code = mask ^ mask) 
                        bool ok = false;
                        for (int k = 0; k < m_x[i].Count; k++)
                        {
                            int X = m_x[i][k];
                            int Y = m_y[i][k];
                            int code = mask & (1 << X);
                            if (code > 0) code = 1;
                            if (code == Y) { ok = true; break; }
                        }
                        if (!ok) { flag = false; break; }//not valid for one person
                    }

                    if (flag)//all satisfied
                    {
                        minimum = cnt;
                        ans_v = mask;
                    }
                }

                Console.Write("Case #{0}:", c);
                if (minimum == int.MaxValue)
                    Console.WriteLine(" IMPOSSIBLE");
                else
                {
                    for (int j = 0; j < N; j++)
                        if ((ans_v & (1 << j)) > 0)
                            Console.Write(" {0}", 1);
                        else Console.Write(" {0}", 0);
                    Console.WriteLine();

                }
            }
        }
    }
}
