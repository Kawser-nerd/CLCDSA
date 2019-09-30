using System;
using System.IO;
using System.Linq;

namespace Google.CodeJam
{
    internal class Solver
    {
        private static int Solve(int n, int m, int k)
        {
            if (k <= 4 || n < 3 || m < 3)
                return k;

            if ((n * m) - k <= 4)
                return n + n + m - 2 + m - 2 - ((n * m) - k);

            int w = n - 2;
            int h = m - 2;

            while (2 * w + 2 * h + w * h > k)
            {
                if (w > h)
                    w--;
                else
                    h--;
            }

            if (2 * w + 2 * h + w * h == k)
                return 2 * w + 2 * h;

            if (w > h)
                h++;
            else
                w++;

            int encl = 2 * w + 2 * h + w * h;
            int stones = 2 * w + 2 * h;
            int diff = encl - k;

            if (diff == 1)
                return stones;

            if (diff == 2 || diff == 3)
                return stones - 1;

            return stones - 2;
        }

        private static void Solve(int id, TextReader reader, TextWriter writer)
        {
            var line = reader.ReadLine().Split(' ').Select(int.Parse).ToArray();
            int n = line[0], m = line[1], k = line[2];
            writer.WriteLine("Case #{0}: {1}", id, Solve(n, m, k));
        }

        private static void Main(string[] args)
        {
            try
            {
                var inputPath = args[0];
                var outputPath = args[1];

                using (var reader = new StreamReader(inputPath))
                using (var writer = new StreamWriter(outputPath))
                {
                    int count = int.Parse(reader.ReadLine());
                    for (int i = 0; i < count; i++)
                        Solve(i + 1, reader, writer);
                }
            }
            catch (Exception e)
            {
                Console.WriteLine(e);
            }
        }
    }
}
