using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJam.CodeJam_2010
{
    class PickUpChicks
    {
        int solve(int[] pos, int[] speed, int K, int B, int T)
        {
            for (int i = 0; i < pos.Length; i++)
            {
                pos[i] = B - 1 - pos[i];
            }

            Array.Reverse(pos);
            Array.Reverse(speed);

            int swaps = 0;

            for (int i = 0; i < pos.Length; i++)
            {
                if (K == 0) break;

                int newpos = pos[i] - T * speed[i];
                if (newpos < 0)
                {
                    K--;
                    for (int j = i - 1; j >= 0; j--)
                    {
                        if (pos[j] < 0) continue;
                        swaps++;
                    }
                    pos[i] = -1;
                    continue;
                }
                pos[i] = newpos;
            }

            if (K == 0) return swaps;
            return -1;
        }

        public static void Main(string[] args)
        {
            StreamReader sr = new StreamReader(args[0]);
            StreamWriter sw = new StreamWriter("CodeJam.out");

            var obj = new PickUpChicks();

            int T = int.Parse(sr.ReadLine());
            for (int i = 1; i <= T; i++)
            {
                var t = sr.ReadLine().Split(' ').Select(s => int.Parse(s)).ToList();
                var pos = sr.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
                var speed = sr.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
                int res = obj.solve(pos, speed, t[1], t[2], t[3]);
                sw.WriteLine("Case #{0}: {1}", i, res == -1 ? "IMPOSSIBLE" : res.ToString());
                Console.WriteLine("Case #{0}: {1}", i, res == -1 ? "IMPOSSIBLE" : res.ToString());
            }

            sr.Close();
            sw.Close();
        }
    }
}
