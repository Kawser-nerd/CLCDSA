using System;
using System.Collections.Generic;
using System.Text;
using System.Collections;
using System.IO;

/* Yoel Grodentzik
 * thed0okie
 * C#
 * Safety in Numbers (A)
 */

namespace goroGCjam
{
    class GCJ2012R1SATa
    {
        static void Main(string[] args)
        {

            StreamReader sr = new StreamReader(@"C:\A-large (1).in");
            StreamWriter sw = new StreamWriter(@"C:\A-large (1).out");

            int numCases = 0;
            numCases = Convert.ToInt32(sr.ReadLine());

            for (int i = 0; i < numCases; i++)
            {
                int N = 0;
                
                string theLine = sr.ReadLine();
                N = Convert.ToInt32((theLine.Split(' '))[0]);
                int[] J = new int[N];
                string[] tmp = new string[N + 1];
                tmp = theLine.Split(' ');
                for (int j = 0; j < N; j++)
                    J[j] = Convert.ToInt32(tmp[1 + j]);

                double[] p = new double[N];
                double[] A = new double[N];

                int JSum = 0;
                for (int j = 0; j < N; j++)
                {
                    JSum += J[j];
                    p[j] = J[j];
                    A[j] = 0;
                }

                
                
                for (int j = 0; j < N; j++)
                {
                    A[j] = bisect(J, JSum, j);
                }

                sw.Write("Case #" + (i + 1) + ": ");
                for (int j = 0; j < N; j++)
                {
                    double ans = A[j] * 100;
                    if (ans < 0.0000001)
                        ans = 0;
                    sw.Write(ans);
                    if (j < N - 1)
                        sw.Write(" ");
                }
                sw.WriteLine();
            }



        
            sr.Close();
            sw.Close();
        }

        static double bisect(int[] J, int jSum, int idx)
        {
            double LB = 0;
            double UB = 1;


            for(int i = 0; i < 50; i++)
            {
                double g = (UB + LB)/2.0;
                bool res = F(J, jSum, idx, g);
                if (res)
                    UB = g;
                else
                    LB = g;
            }
            return (UB + LB) / 2.0;
        }

        static bool F(int[] J, int jSum, int idx, double guess)
        {
            double score = ((double)J[idx]) + guess * ((double)jSum);
            double PROB = 1 - guess;
            for (int t = 0; t < J.Length; t++)
            {
                if (t != idx)
                {
                    if (J[t] < score)
                    {
                        double diff = (score - ((double)J[t])) / ((double)jSum);
                        if (diff > PROB)
                            return true;
                        else
                            PROB -= diff;
                    }
                }
            }
            return false;
        }
    }


}
