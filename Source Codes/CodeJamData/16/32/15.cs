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
            var data = reader.ReadLine().Split().Select(s => long.Parse(s)).ToArray();

            var B = data[0];
            var M = data[1];

            var max = (1L << (int)(B - 2));
            if (max < M)
            {
                writer.WriteLine("IMPOSSIBLE");
                return;
            }

            writer.WriteLine("POSSIBLE");

            M = (M << 1) - 1;
            var f = new StringBuilder();
            for (var i = 0; i < B; i++)
            {
                if ((M & 1) == 1)
                    f.Insert(0, '1');
                else
                    f.Insert(0, '0');
                M = M >> 1;
            }

            writer.WriteLine(f);

            for (var i = 1; i < B; i++)
            {
                Repeat(i + 1, s => writer.Write('0'));
                Repeat((int)B - (i + 1), s => writer.Write('1'));
                writer.WriteLine();
            }

            //var bits = new int[64];
            //var mb = 0;
            //for (var i = 0; i < bits.Length; i++)
            //{
            //    bits[i] = (int)(M & 1);
            //    M = (M >> 1);
            //    if (M == 0)
            //    {
            //        mb = i;
            //        break;
            //    }
            //}
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
