using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace GCJ.P1
{
    class Program
    {


        static void Main(string[] args)
        {
            var root = @"D:\gcj\p1\";

            string[] input = System.IO.File.ReadAllLines(root + "small.txt");
            StreamWriter output = new StreamWriter(root + "out.txt");
            int[] data = input.SelectMany(x => x.Split(' ').Select(y => Int32.Parse(y))).ToArray();
            IEnumerator<int> scanner = data.AsEnumerable<int>().GetEnumerator();
            scanner.MoveNext();
            int numCases = scanner.Current;
            for(long nc = 0; nc < numCases; ++nc)
            {
                scanner.MoveNext();
                int intervals = scanner.Current;
                List<int> iv = new List<int>();
                for(int i = 0; i < intervals; ++i)
                {
                    scanner.MoveNext();
                    iv.Add(scanner.Current);
                }

                int m1 = 0;
                for(int i = 1; i < intervals; ++i)
                {
                    if(iv[i] < iv[i-1])
                    {
                        m1+= iv[i-1] - iv[i];
                    }
                }

                int max = 0;
                for(int i = 1; i < intervals; ++i)
                {
                    int diff = iv[i-1] - iv[i];

                    if (diff > max)
                    {
                        max = diff;
                    }
                }


                int m2 = 0;
                for(int i = 0; i < intervals - 1; ++i)
                {
                    if (iv[i] >= max)
                    {
                        m2 += max;
                    }
                    else
                    {
                        m2 += iv[i];
                    }
                }


                output.WriteLine("Case #{0}: {1} {2}", nc + 1, m1, m2);
                Console.WriteLine("Case #{0}: {1} {2}", nc + 1, m1, m2);
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
