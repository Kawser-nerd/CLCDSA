using System;
using System.Collections;
using System.IO;
public class GG
{
    static long[,] CM;
    public void processing()
    {
        StreamReader SR;
        StreamWriter SW;
        SR = File.OpenText("A.in");
        SW = File.CreateText("C.out");
     //   string S;
        int NN = int.Parse(SR.ReadLine());

        for (int cc = 1; cc <= NN; cc++)
        {
            string[] par = SR.ReadLine().Split();
            int C = int.Parse(par[0]);
            int N = int.Parse(par[1]);
            if(N>=C)
            {
                 SW.WriteLine("Case #" + cc + ": 1.0");
                Console.WriteLine("Case #" + cc + ": 1.0");
            }
            else{

                double[] steps = new double[C + 1];
                steps[N] = 1.0;
                double[,] jumpChance = new double[C + 1, C + 1] ;
                double[] forwardChance = new double[C+1];
                double[] reachChance = new double[C + 1];
                reachChance[N] = 1.0;
                for(int i=N;i<C;i++)
                    for (int j = i + 1; j <= C; j++)
                    {
                        int diff = j - i;
                        if (diff <= N)
                        {
                            jumpChance[i, j] = (double)CM[C - i, diff] * CM[i, N - diff] / (double)CM[C, N];
                            forwardChance[i] += jumpChance[i, j];
                        }
                    }
                for (int i = N + 1; i <= C; i++)
                {
                    for (int j = 0; j < i; j++)
                    {
                        if (reachChance[j] > 0.0  && jumpChance[j,i]>0.0)
                        {
                            reachChance[i] += reachChance[j] * jumpChance[j, i] / forwardChance[j];
                        }

                    }
                }
                for (int i = N + 1; i <= C; i++)
                {
                    for (int j = 0; j < i; j++)
                    {
                        if (reachChance[j] > 0.0 && jumpChance[j, i] > 0.0)
                        {
                            double fromChance = reachChance[j] * (jumpChance[j, i] / forwardChance[j])/reachChance[i];
                            //steps[i] += fromChance * (steps[j] + 1.0 / jumpChance[j, i]);
                            steps[i] += fromChance * (steps[j] + 1.0 / (forwardChance[j]));
                        }
                    }
                }



                SW.WriteLine("Case #" + cc + ": "+steps[C]);
                Console.WriteLine("Case #" + cc + ": "+steps[C]);
            }
        }
        SR.Close();
        SW.Close();
    }
    public static void Main()
    {
        CM = new long[41,41];
        for(int i=0;i<=40;i++)
            for (int j = 0; j <= i; j++)
            {
                if (i == j)
                    CM[i, j] = 1;
                else if (j == 0)
                    CM[i, j] = 1;
                else
                {
                    CM[i, j] = CM[i - 1, j] + CM[i - 1, j - 1];
                }
            }
      //  Console.WriteLine(CM[4, 2]);
        GG g = new GG();
        g.processing();
    }
}