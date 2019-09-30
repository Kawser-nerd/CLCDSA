using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using System.IO;

namespace CodeJam2012
{
    class Problem1
    {
        private const string INPUT = "A-small-attempt0 (1).in";
        private const string OUTPUT = "A-small-attempt0 (1).out";

        static void Main(string[] args)
        {
            string[] input = File.ReadAllLines("d:/code/codejam_dotnet/data/" + INPUT);
            var output = new List<string>();
            int counter = 0;
            int i = 1;
            while(i < input.Length)
            {
                int numberVines = Convert.ToInt32(input[i]);
                var testCase = new List<string>();
                for (int j = 0; j < numberVines; j++)
                {
                    testCase.Add(input[i + j + 1]);
                }
                testCase.Add(input[i + numberVines + 1]);//distance from love
                output.Add("Case #" + ++counter + ": " + GetResult(testCase));
                Console.WriteLine(i + " of " + input.Length);
                i += numberVines + 2;
            }
            File.WriteAllLines("d:/code/codejam_dotnet/data/" + OUTPUT, output);
        }

        private static string GetResult(List<string> input)
        {
            long distanceLove = Convert.ToInt64(input.Last());
            var vines = new List<Vine>();
            for (int i = 0; i < input.Count - 1; i++)
            {
                string[] xs = input[i].Split();
                vines.Add(new Vine(Convert.ToInt64(xs[0]), Convert.ToInt64(xs[1])));
            }

            return IsPossibleFromVine(vines[0], 0, vines[0].Distance, distanceLove, vines) ? "YES" : "NO";
        }

        private static bool IsPossibleFromVine(Vine currentVine, long curDistance, long curLength, long distanceLove, List<Vine> vines)
        {
            if (curDistance + 2 * curLength >= distanceLove) return true;

            foreach (var vine in vines.Where(n => n.Distance > currentVine.Distance && n.Distance <= curDistance + 2 * curLength))
            {
                if (IsPossibleFromVine(vine, currentVine.Distance + Math.Max((vine.Distance - currentVine.Distance - vine.Length), 0), Math.Min(vine.Length, vine.Distance - currentVine.Distance), distanceLove, vines)) return true;
            }

            return false;
        }

        private class Vine
        {
            public Vine(long d, long l)
            {
                Distance = d;
                Length = l;
            }
            public long Distance { get; set; }
            public long Length { get; set; }
        }
    }
}
