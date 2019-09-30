/* To compile in MS Visual C# Express:
 * - create a new console program project
 * - import this file
 * - call Go()
 * 
 * Code Jam 2009
 * Author: Jack Hou (jack.m.hou@gmail.com)
 */

using System;
using System.Collections.Generic;
using System.Text;
using System.Text.RegularExpressions;
using System.IO;

namespace CodeJam
{
    class BribeThePrisoners
    {
        static public void Go()
        {
            string line = Console.ReadLine();
            int T = int.Parse(line);

            for (int t = 0; t < T; t++)
            {
                line = Console.ReadLine();
                MatchCollection PQ = Regex.Matches(line, @"\d+");
                int P = int.Parse(PQ[0].ToString()) + 1;
                int Q = int.Parse(PQ[1].ToString());

                line = Console.ReadLine();
                PQ = Regex.Matches(line, @"\d+");
                int[] cuts = new int[Q + 2];
                for (int q = 0; q < Q; q++)
                {
                    cuts[q + 1] = int.Parse(PQ[q].ToString());
                }
                cuts[0] = 0;
                cuts[Q + 1] = P;

                //foreach (int i in cuts)
                  //  Console.WriteLine(""+i);

                int[,] dp = new int[Q + 2, Q + 2];
                Q++;
                for (int d = 2; d <= Q; d++)
                {
                    for (int i = 0, j = d; j <= Q; i++, j++)
                    {
                        int min_value = int.MaxValue;

                        for (int k = i + 1; k < j; k++)
                        {
                            int s = dp[i,k] + dp[k,j] + cuts[j] - cuts[i] - 2;
                            //Console.WriteLine("" + cuts[j] + " " + cuts[i]);
                            if (s < min_value) min_value = s;
                        }

                        dp[i,j] = min_value;
                    }
                }

                Console.WriteLine("Case #" + (t+1) + ": " + (dp[0,Q]));



            }
        }
    }
}
