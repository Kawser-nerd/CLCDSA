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
    class Load
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
                double L = double.Parse(mc[0].ToString());
                double P = double.Parse(mc[1].ToString());
                double C = double.Parse(mc[2].ToString());

                int total = 0;
                double a = P;
                while (true)
                {
                    if (a / L <= C) break;
                    
                    a = Math.Sqrt(L*a);
                    total++;
                }

                Console.WriteLine("Case #" + (t + 1) + ": " + total);
            }
        }
    }
}
