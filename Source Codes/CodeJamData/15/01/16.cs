using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GoogleCodeJam
{
    class A
    {
        static void Main(string[] args)
        {
            var input = @"C:\Users\kaspir\Downloads\A-large.in";

            File.WriteAllLines(Path.ChangeExtension(input, "out"), Solver.Solve(File.ReadAllLines(input)));

            Console.WriteLine("Press ENTER to finish");
            Console.ReadLine();
        }

        public class Solver
        {
            public static IEnumerable<string> Solve(IEnumerable<string> input)
            {
                var reader = new Reader(input);
                reader.Next(); // Test Count

                for (var i = 0; ; i++)
                {
                    var line = reader.NextOrNull();

                    if (line == null)
                        break;

                    var parts = line.Split(' ');
                    var sMax = int.Parse(parts[0]);
                    var shyness = parts[1].Select(c => c - '0').ToList();
                    yield return string.Format("Case #{0}: {1}", i + 1, SolveCase(sMax, shyness));
                }
            }

            public static int SolveCase(int sMax, IList<int> shyness)
            {
                var standingCount = 0;
                var friendCount = 0;

                for (var i = 0; i <= sMax; i++)
                {
                    if (standingCount < i)
                    {
                        friendCount += (i - standingCount);
                        standingCount = i;
                    }
                    standingCount += shyness.ElementAtOrDefault(i);
                }

                return friendCount;
            }
        }

        class Reader
        {
            readonly IEnumerator<string> _enumerator;

            public Reader(IEnumerable<string> lines)
            {
                _enumerator = lines.GetEnumerator();
            }

            public string NextOrNull()
            {
                if (!_enumerator.MoveNext())
                    return null;

                return _enumerator.Current;
            }

            public string Next()
            {
                if (!_enumerator.MoveNext())
                    throw new ApplicationException("End of input");

                return _enumerator.Current;
            }
        }
    }
}
