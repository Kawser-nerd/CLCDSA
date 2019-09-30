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

            var root = @"D:\gcj\p2\";

            string[] input = System.IO.File.ReadAllLines(root + "small.txt");
            StreamWriter output = new StreamWriter(root + "out.txt");
            
            long[] data = input.SelectMany(x => x.Split(' ').Select(y => long.Parse(y))).ToArray();
            IEnumerator<long> scanner = data.AsEnumerable<long>().GetEnumerator();
            scanner.MoveNext();
            long numCases = scanner.Current;
            for (int nc = 0; nc < numCases; ++nc)
            {
                scanner.MoveNext();
                long b = scanner.Current;
                scanner.MoveNext();
                long n = scanner.Current;

                List<long> barbs = new List<long>();
                for (int i = 0; i < b; ++i)
                {
                    scanner.MoveNext();
                    barbs.Add(scanner.Current);
                }

                long maxBarb = barbs.Max();
                long maxTime = maxBarb * n + 1;


                long minTime = 0;

                while (true)
                {
                    long midTime = (maxTime - minTime) / 2 + minTime;
                    

                    long cB = 0;
                    long cA = 0;
                    foreach (var i in barbs)
                    {
                        cB += (midTime - 1) / i;
                        cA += (midTime) / i;
                    }
                    cA += barbs.Count;
                    cB += barbs.Count;


                    if (cA < n)
                    {
                        minTime = midTime + 1;
                    }
                    else if (cB >= n)
                    {
                        maxTime = midTime - 1;
                    }
                    else
                    {
                        minTime = midTime;
                        maxTime = midTime;
                        break;
                    }
                }


                long cust = 0;
                foreach (var i in barbs)
                {
                    cust += (minTime - 1) / i;
                }
                cust += barbs.Count;

                int res = -1;
                for (int i = 0; i < barbs.Count; ++i)
                {
                    if (minTime % barbs[i] == 0)
                    {
                        cust++;
                        if (cust == n)
                        {
                            res = i + 1;
                            break;
                        }
                    }
                }
                if (res == -1)
                {
                    throw new Exception("Bug");
                }


               

                output.WriteLine("Case #{0}: {1}", nc + 1, res);
                Console.WriteLine("Case #{0}: {1}", nc + 1, res);
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
