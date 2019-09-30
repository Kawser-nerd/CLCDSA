using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using KEY = System.Tuple<int, int>;

namespace GCJ
{
    class Program
    {
        class Node
        {
            public int id;
            public List<int> cn = new List<int>();

            public override bool Equals(object obj)
            {
                return id == ((Node)obj).id;
            }
        }


        static int Recurse(int r, int p, List<List<int>> nds, Dictionary<Tuple<int,int>,int> cache)
        {
            var k = new KEY(r, p);
            if (cache.ContainsKey(k))
            {
                return cache[k];
            }

            int ch1 = 0;
            int ch2 = 0;

            foreach (var c in nds[r])
            {
                if (c == p)
                {
                    continue;
                }
                int val = Recurse(c, r, nds, cache);
                if (val > ch1)
                {
                    ch2 = ch1;
                    ch1 = val;
                }
                else if (val > ch2)
                {
                    ch2 = val;
                }
            }

            if ((ch1 == 0 && ch2 == 0)
                || (ch1 > 0 && ch2 > 0))
            {
                cache.Add(k, 1 + ch1 + ch2);
                return 1 + ch1 + ch2;
            }
            else
            {
                cache.Add(k, 1);
                return 1;
            }

            

            
        }

        static void Main(string[] args)
        {

            var root = @"D:\gcj\p2\";

            string[] input = System.IO.File.ReadAllLines(root + "small.txt");
            StreamWriter output = new StreamWriter(root + "out.txt");
            
            int[] data = input.SelectMany(x => x.Split(' ').Select(y => Int32.Parse(y))).ToArray();
            IEnumerator<int> scanner = data.AsEnumerable<int>().GetEnumerator();
            scanner.MoveNext();
            int numCases = scanner.Current;
            for (int nc = 0; nc < numCases; ++nc)
            {
                scanner.MoveNext();
                int N = scanner.Current;


                List<List<int>> nds = new List<List<int>>();
                for (int i = 0; i < N; ++i)
                {
                    nds.Add(new List<int>());
                }

                for (int i = 0; i < N - 1; ++i)
                {
                    scanner.MoveNext();
                    int x = scanner.Current - 1;
                    scanner.MoveNext();
                    int y = scanner.Current - 1;

                    nds[x].Add(y);
                    nds[y].Add(x);
                }


                Dictionary<KEY, int> cache = new Dictionary<KEY,int>();
                for(int r = 0; r < N; ++r)
                {
                    int val = Recurse(r, -1, nds, cache);
                }


                output.WriteLine("Case #{0}: {1}", nc + 1, N - cache.Values.Max());
                Console.WriteLine("Case #{0}: {1}", nc + 1, N - cache.Values.Max());
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
