using System;
using System.IO;

namespace CodeJam2017
{
    public class QR_A
    {
        public static void Solve(TextReader input, TextWriter output)
        {
            int t = Convert.ToInt32(input.ReadLine());

            for (int z = 1; z <= t; z++)
            {
                string[] data = input.ReadLine().Split(' ');
                string s = data[0];
                int k = Int32.Parse(data[1]);
                bool[] x = new bool[s.Length];

                for (int i = 0; i < s.Length; i++)
                    x[i] = s[i] == '+';

                int r = 0;

                for (int i = 0; i <= s.Length - k; i++)
                {
                    if (!x[i])
                    {
                        for (int j = i; j < i + k; j++)
                            x[j] = !x[j];

                        r++;
                    }
                }

                for (int i = s.Length - k + 1; i < s.Length; i++)
                    if (!x[i]) r = -1;

                output.WriteLine("Case #{0}: {1}", z, (r >= 0) ? r.ToString() : "IMPOSSIBLE");
            }
        }
    }
}
