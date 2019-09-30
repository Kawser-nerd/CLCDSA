using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            using (var reader = new StreamReader("C:/CodeJam/1a/Problem2/B-large (1).in"))
            {
                using (var writer = new StreamWriter("C:/CodeJam/1a/Problem2/output.txt"))
                {
                    var numTC = int.Parse(reader.ReadLine());
                    for (var tc = 1; tc <= numTC; tc++)
                    {
                        Console.Write("Case #{0}: ", tc);
                        writer.Write("Case #{0}: ", tc);
                        Solve(reader, writer);
                    }
                }
            }
            Console.ReadKey();

        }

        static void Solve(StreamReader reader, StreamWriter writer)
        {
            var N = int.Parse(reader.ReadLine());
            var lines = new List<int[]>();
            for (int i = 0; i < 2 * N - 1; i++)
            {
                lines.Add(reader.ReadLine().Split(' ').Select(int.Parse).ToArray());
            }
            var linesBack = lines.ToArray();
            var lowestArr = new int[N];
            var missing = -1;
            int[] missingArr = null;
            for (int i = 0; i < N; i++)
            {
                var lowest = int.MaxValue;
                var lowestCount = 0;
                List<int[]> lowestL = new List<int[]>();
                foreach (var s in lines)
                {
                    if (s[i] < lowest)
                    {
                        lowest = s[i];
                        lowestL.Clear();
                        lowestL.Add(s);
                        lowestCount = 1;
                    }
                    else if (s[i] == lowest)
                    {
                        lowestL.Add(s);
                        lowestCount++;
                    }
                }
                foreach(var a in lowestL)
                {
                    lines.Remove(a);
                }
                lowestArr[i] = lowest;
                if (lowestCount != 2)
                {
                    missing = i;
                    missingArr = lowestL[0];
                }
            }

            lines = linesBack.ToList();

            int[] ret = new int[N];
            for (int j = 0; j < N; j++)
            {
                var vals = new List<int>();
                foreach (var s in lines)
                {
                    if (s[j] == lowestArr[j])
                    {
                        vals.Add(s[missing]);
                    }
                }
                if (vals.Count == 1)
                {
                    ret[j] = vals[0];
                }
                else
                {
                    if(vals[0] == missingArr[j])
                    {
                        ret[j] = vals[1];
                    }
                    else
                    {
                        ret[j] = vals[0];
                    }
                }
            }
            Console.WriteLine(string.Join(" ", ret));
            writer.WriteLine(string.Join(" ", ret));
        }
    }
}
