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
        static bool[,] grid = new bool[16,16];
        static long R = 0;
        static long C = 0;
        static long N = 0;


        static long recurse(long r, long c, long n, long u)
        {
            if (c >= C)
            {
                c = 0;
                r++;
            }
            if (n == N)
            {
                return u;
            }
            if (r >= R)
            {
                return long.MaxValue;
            }

            grid[r, c] = true;
            int nu = 0;
            if (r > 0 && grid[r - 1, c])
            {
                nu++;
            }
            if (c > 0 && grid[r, c- 1])
            {
                nu++;
            }

            long res1 = recurse(r, c + 1, n + 1, u + nu);

            grid[r, c] = false;

            long res2 = recurse(r, c + 1, n, u);

            return Math.Min(res1, res2);


        }


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
                R = scanner.Current;
                scanner.MoveNext();
                C = scanner.Current;
                scanner.MoveNext();
                N = scanner.Current;

                var res = recurse(0, 0, 0, 0);

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
