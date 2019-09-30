using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ_2015_Round1C
{
    public class B
    {
        private void Run()
        {
            int T = int.Parse(Console.ReadLine().Trim());
            for (int testcase = 1; testcase <= T; ++testcase)
            {
                var input = Console.ReadLine().Trim().Split();
                var K = Console.ReadLine().Trim();
                var L = Console.ReadLine().Trim();
                int S = int.Parse(input[2]);

                double max = 0;
                double total = 0;
                double count = 0;

                var l = new char[S];
                Action<int> dfs = null;
                dfs = (index) =>
                    {
                        if (index == S)
                        {
                            int temp = 0;
                            for (int i = 0; i < S - L.Length + 1; i++)
                            {
                                if (l.Skip(i).Take(L.Length).SequenceEqual(L)) { temp += 1; }
                            }
                            if (max < temp) { max = temp; }
                            total += 1;
                            count += temp;
                            return;
                        }
                        foreach (char c in K)
                        {
                            l[index] = c;
                            dfs(index + 1);
                        }
                    };
                dfs(0);

                Console.Write("Case #{0}: ", testcase);
                Console.WriteLine("{0:F9}", max - (count / total));
            }
        }

        private static void Main()
        {
            var old = Console.Out;
            using (var writer = new System.IO.StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false })
            {
                Console.SetOut(writer);
                new B().Run();
                Console.Out.Flush();
                Console.SetOut(old);
            }
        }
    }
}
