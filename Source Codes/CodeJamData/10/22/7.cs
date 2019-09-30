using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading;

namespace Picking_Up_Chicks
{
    class Program
    {
        static void Main(string[] args)
        {
            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
            var reader = new StreamReader("b.txt");
            var writer = new StreamWriter("b_out.txt");

            var C = long.Parse(reader.ReadLine());
            for (long test = 1; test <= C; ++test)
            {
                var input = reader.ReadLine().Split(' ');
                long N = long.Parse(input[0]);
                long K = long.Parse(input[1]);
                long B = long.Parse(input[2]);
                long T = long.Parse(input[3]);

                input = reader.ReadLine().Split(' ');
                var X = new long[N];
                for (int i = 0; i < N; ++i)
                    X[i] = long.Parse(input[i]);

                input = reader.ReadLine().Split(' ');
                var V = new long[N];
                for (int i = 0; i < N; ++i)
                    V[i] = long.Parse(input[i]);

                long result = 0;

                long last = N - 1;
                while (last >=0)
                {
                    if (B - X[last] <= T * V[last]) --last;
                    else break;
                }

                K -= N - 1 - last;

                long cur = last;
                while (K>0 && cur>=0 && last>=0)
                {
                    while (cur>=0)
                    {
                        if (B - X[cur] <= T * V[cur]) break;
                        else --cur;
                    }
                    if (cur < 0) break;
                    result += last - cur;
                    --last;
                    --cur;
                    --K;
                }

                if (K > 0) writer.WriteLine("Case #{0}: {1}", test, "IMPOSSIBLE");
                else writer.WriteLine("Case #{0}: {1}", test, result);

            }

            reader.Close();
            writer.Close();
        }
    }
}
