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
            var root = @"C:\projects\comp\gcj\p1\";


            string[] input = System.IO.File.ReadAllLines(root + "small.txt");
            StreamWriter output = new StreamWriter(root + "out.txt");
            IEnumerator<string> scanner = input.AsEnumerable<string>().GetEnumerator();
            scanner.MoveNext();
            long numCases = long.Parse(scanner.Current);

            
            for (long nc = 0; nc < numCases; ++nc)
            {
                scanner.MoveNext();
                string w = scanner.Current;

                char[] vals = new char[10000];
                int index = 5000;
                int bIndex = 5000;

                vals[index] = w[0];

                for(int i = 1; i < w.Length; ++i)
                {
                    if(w[i] > vals[index])
                    {
                        index--;
                        vals[index] = w[i];
                    }
                    else if(w[i] < vals[index])
                    {
                        bIndex++;
                        vals[bIndex] = w[i];
                    }
                    else
                    {
                        int ti = index + 1;
                        while(true)
                        {
                            if(vals[ti] == vals[index])
                            {
                                ti++;
                                continue;
                            }
                            else if(vals[ti] == 0 || w[i] > vals[ti])
                            {
                                index--;
                                vals[index] = w[i];
                                break;
                            }
                            else
                            {
                                bIndex++;
                                vals[bIndex] = w[i];
                                break;
                            }
                        }
                    }

                }

                StringBuilder s = new StringBuilder();

                for(int i = index; i <= bIndex; ++i)
                {
                    s.Append(vals[i]);
                }


                output.WriteLine("Case #{0}: {1}", nc + 1, s);
                Console.WriteLine("Case #{0}: {1}", nc + 1, s);
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
