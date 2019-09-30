using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace Marius.CodeJam
{
    public static class Program
    {
        public static void Main(string[] args)
        {
            using (var reader = new StreamReader(@"..\..\input.txt"))
            using (var writer = new StreamWriter(@"..\..\output.txt"))
            {
                var caseCount = int.Parse(reader.ReadLine());

                for (int currentCase = 0; currentCase < caseCount; currentCase++)
                {
                    writer.Write("Case #" + (currentCase + 1) + ": ");
                    Solve(reader, writer);
                }
            }
        }

        private static void Solve(StreamReader reader, StreamWriter writer)
        {
            var N = int.Parse(reader.ReadLine().Trim());
            var p = reader.ReadLine().Split().Select(s => int.Parse(s)).ToArray();

            var lets = Enumerable.Range('A', 'Z').Select(s => (char)s).ToArray();

            var sum = p.Sum();
            while (true)
            {
                var max = p.Max();
                if (max == 0)
                    break;

                var indexes = IndexesOf(p, max).ToArray();
                var count = indexes.Length;

                if (count == 2 || count > 3)
                {
                    for (var i = 0; i < 2; i++)
                    {
                        var index = indexes[i];
                        p[index]--;
                        writer.Write(lets[index]);
                    }
                }
                else
                {
                    var index = indexes[0];
                    p[index]--;
                    writer.Write(lets[index]);
                }

                writer.Write(' ');
            }

            writer.WriteLine();
        }

        private static IEnumerable<int> IndexesOf(int[] p, int max)
        {
            for (var i = 0; i < p.Length; i++)
                if (p[i] == max)
                    yield return i;
        }

        private static void Repeat(int count, Action<int> action)
        {
            for (int i = 0; i < count; i++)
            {
                action(i);
            }
        }
    }
}
