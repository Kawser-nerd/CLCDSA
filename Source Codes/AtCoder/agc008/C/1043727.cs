using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace AGC008
{
    public class C
    {
        private void Run()
        {
            checked
            {
                var A = Console.ReadLine().Trim().Split().Select(long.Parse).ToArray();
                var I = A[0];
                var O = A[1];
                //var T = A[2];
                var J = A[3];
                var L = A[4];
                //var S = A[5];
                //var Z = A[6];

                long t1 = O;
                t1 += I / 2 * 2;
                t1 += J / 2 * 2;
                t1 += L / 2 * 2;
                if (I % 2 == 1 && J % 2 == 1 && L % 2 == 1) { t1 += 3; }

                long t2 = O;
                if (I > 0 && J > 0 && L > 0)
                {
                    t2 += 3;
                    I--;
                    J--;
                    L--;
                }
                t2 += I / 2 * 2;
                t2 += J / 2 * 2;
                t2 += L / 2 * 2;

                Console.WriteLine(Math.Max(t1, t2));
            }
        }

        public static void Main()
        {
            var old = Console.Out;
            using (var writer = new System.IO.StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false })
            {
                Console.SetOut(writer);
                new C().Run();
                Console.Out.Flush();
                Console.SetOut(old);
            }
        }
    }
}