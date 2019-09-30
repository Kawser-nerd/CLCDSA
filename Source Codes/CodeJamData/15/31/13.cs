using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ_2015_Round1C
{
    public class A
    {
        private void Run()
        {
            int T = int.Parse(Console.ReadLine().Trim());
            for (int testcase = 1; testcase <= T; ++testcase)
            {
                var input = Console.ReadLine().Trim().Split();
                int height = int.Parse(input[0]);
                int width = int.Parse(input[1]);
                int W = int.Parse(input[2]);

                int res = height * (width / W);
                int remainWidth = W + (width % W);
                if (remainWidth == W)
                {
                    res += (W - 1);
                }
                else
                {
                    res += W;
                }

                Console.Write("Case #{0}: ", testcase);
                Console.WriteLine(res);
            }
        }

        private static void Main()
        {
            var old = Console.Out;
            using (var writer = new System.IO.StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false })
            {
                Console.SetOut(writer);
                new A().Run();
                Console.Out.Flush();
                Console.SetOut(old);
            }
        }
    }
}
