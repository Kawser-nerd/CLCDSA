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
    class CenterOfMass
    {
        static public void Go()
        {
            string line = Console.ReadLine();
            int T = int.Parse(line);

            for (int t = 0; t < T; t++)
            {
                line = Console.ReadLine();
                int N = int.Parse(line);

                long x0 = 0, y0 = 0, z0 = 0, vx0 = 0, vy0 = 0, vz0 = 0;

                for (int n = 0; n < N; n++)
                {
                    line = Console.ReadLine();
                    MatchCollection m = Regex.Matches(line, @"-?\d+");
                    x0 += long.Parse((m[0]).ToString());
                    y0 += long.Parse((m[1]).ToString());
                    z0 += long.Parse((m[2]).ToString());
                    vx0 += long.Parse((m[3]).ToString());
                    vy0 += long.Parse((m[4]).ToString());
                    vz0 += long.Parse((m[5]).ToString());
                }

                double Nd = N;
                double x = x0 / Nd;
                double y = y0 / Nd;
                double z = z0 / Nd;
                double vx = vx0 / Nd;
                double vy = vy0 / Nd;
                double vz = vz0 / Nd;

                //Console.WriteLine(x + " " + y + " " + z + " " + vx + " " + vy + " " + vz);
                //Console.ReadLine();

                double divisor = (vx * vx + vy * vy + vz * vz);
                double time = -1;
                if (divisor != 0)
                {
                    time = (-1) * (x * vx + y * vy + z * vz) / divisor;
                }

                if (time > 0)
                {
                    double px = x + time * vx;
                    double py = y + time * vy;
                    double pz = z + time * vz;

                    double distance = Math.Sqrt(px * px + py * py + pz * pz);

                    Console.WriteLine("Case #" + (t + 1) + ": " + distance.ToString("0.00000000") + " " + time.ToString("0.00000000"));
                }
                else
                {
                    double distance = Math.Sqrt(x * x + y * y + z * z);

                    Console.WriteLine("Case #" + (t + 1) + ": " + distance.ToString("0.00000000") + " 0.00000000");
                }
            }
        }
    }
}
