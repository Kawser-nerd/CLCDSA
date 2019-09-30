/* Codejam 2010
 * Jack Hou
 * jack.m.hou@gmail.com
 * 
 * To run, simply call Go(args)
 */

using System;
using System.Collections.Generic;
using System.Text;
using System.Text.RegularExpressions;
using System.IO;

namespace Codejam2010Round1C
{
    class Rope
    {
        public static void Go(string[] args)
        {
            MatchCollection mc;
            string line = Console.ReadLine();
            int T = int.Parse(line);
            for (int t = 0; t < T; t++)
            {
                line = Console.ReadLine();
                mc = Regex.Matches(line, @"\d+");
                int N = int.Parse(mc[0].ToString());

                int[] left = new int[N];
                int[] right = new int[N];
                for (int n = 0; n < N; n++)
                {
                    line = Console.ReadLine();
                    mc = Regex.Matches(line, @"\d+");
                    left[n] = int.Parse(mc[0].ToString());
                    right[n] = int.Parse(mc[1].ToString());
                }

                int total = 0;
                for (int n = 0; n < N; n++)
                {
                    int a = left[n];
                    int b = right[n];
                    for (int i = 0; i < N; i++)
                    {
                        if (left[i] > a && right[i] < b)
                            total++;
                        if (left[i] < a && right[i] > b)
                            total++;
                    }
                }
                total /= 2;

                Console.WriteLine("Case #" + (t + 1) + ": " + total);
            }
        }
    }
}
