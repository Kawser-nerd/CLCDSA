using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using KEY = System.Tuple<int, int>;

// The solution might use the C5 C# library, available at http://www.itu.dk/research/c5/

namespace GCJ
{
    class Program
    {
      


        static void Main(string[] args)
        {

            var root = @"C:\projects\comp\gcj\p2\";

            string[] input = System.IO.File.ReadAllLines(root + "small.txt");
            StreamWriter output = new StreamWriter(root + "out.txt");
            long[] data = input.SelectMany(x => x.Split(' ').Select(y => Int64.Parse(y))).ToArray();
            IEnumerator<long> scanner = data.AsEnumerable<long>().GetEnumerator();
            scanner.MoveNext();
            long numCases = scanner.Current;

            for (long nc = 0; nc < numCases; ++nc)
            {
                scanner.MoveNext();
                int N = (int)scanner.Current;

                Dictionary<int, int> counts = new Dictionary<int, int>();
                for (int i = 0; i < 2 * N - 1; ++i)
                {
                    for (int j = 0; j < N; ++j)
                    {
                        scanner.MoveNext();
                        if (!counts.ContainsKey((int)scanner.Current))
                        {
                            counts.Add((int)scanner.Current, 0);
                        }
                        counts[(int)scanner.Current]++;
                    }
                }



                var final = counts.Where(x => x.Value % 2 == 1);

                if(final.Count() != N)
                {
                    throw new Exception("Failure " + N + " " + final.Count());
                }

                var sorted = final.Select(x => x.Key).OrderBy(x => x).Select(x => x.ToString());


                


                output.WriteLine("Case #{0}: {1}", nc + 1, String.Join(" ", sorted));
                Console.WriteLine("Case #{0}: {1}", nc + 1, String.Join(" ", sorted));
            }

            output.Close();

            string readOut = File.ReadAllText(root + "out.txt");
            string pOut = File.ReadAllText(root + "outP.txt");

            if (readOut.Equals(pOut))
            {
                Console.WriteLine("Match found");
            }
            else
            {
                Console.WriteLine("Match not found");
                Console.WriteLine("v1 is: {0}\nv2 is: {1}", readOut, pOut);
            }
        }
    }
}
