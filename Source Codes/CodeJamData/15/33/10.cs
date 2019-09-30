using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ_2015_Round1C
{
    public class C
    {
        private void Run()
        {
            int T = int.Parse(Console.ReadLine().Trim());
            for (int testcase = 1; testcase <= T; ++testcase)
            {
                var input = Console.ReadLine().Trim().Split();
                var C = int.Parse(input[0]);
                var D = new SortedSet<int>(Console.ReadLine().Split().Select(int.Parse));
                var V = int.Parse(input[2]);

                int res = 0;
                while (true)
                {
                    var can = new bool[V + 1];
                    can[0] = true;
                    foreach (var d in D)
                    {
                        for (int j = V - d; j >= 0; j--)
                        {
                            if (can[j]) { can[j + d] = true; }
                        }
                    }
                    int notIndex = Array.FindIndex(can, b => !b);
                    if (notIndex < 0) { break; }
                    D.Add(notIndex);
                    res += 1;
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
                new C().Run();
                Console.Out.Flush();
                Console.SetOut(old);
            }
        }
    }
}
