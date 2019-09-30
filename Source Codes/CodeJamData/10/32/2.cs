using System;
using System.IO;
using System.Collections.Generic;
using System.Text;

namespace GCJ2010
{
    class Round1B
    {
        public void SloveFile(string inputfile)
        {
            using (StreamReader reader = new StreamReader(inputfile))
            using (StreamWriter writer = new StreamWriter(inputfile + ".out"))
            {
                int n = int.Parse(reader.ReadLine());
                for (int i = 1; i <= n; i++)
                {
                    var ss = reader.ReadLine().Split();

                    long L = long.Parse(ss[0]);
                    long P = long.Parse(ss[1]);
                    int C = int.Parse(ss[2]);

                    int r = SloveCase(L, P, C);

                    writer.WriteLine("Case #{0}: {1}", i, r);
                    Console.WriteLine("Case #{0}: {1}", i, r);
                }
            }
        }

        int SloveCase(long L, long P, int C)
        {
            double d = Math.Log((double)P / L, (double)C);
            int x = N(d);

            Console.WriteLine("d={0}, x={1}", d, x);

            return N(Math.Log((double)x, 2.0f));
        }

        int N(double d)
        {
            if (d - Math.Round(d) > 0.0f)
                return (int)Math.Round(d) + 1;
            else
                return (int)Math.Round(d);
        }
    }
}
