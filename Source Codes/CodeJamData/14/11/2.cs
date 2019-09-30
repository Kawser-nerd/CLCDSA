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
            long numCases = Int32.Parse(input[0]);
            int ln = 1;
            for(long nc = 0; nc < numCases; ++nc)
            {
                int[] data = input[ln].Split(' ').Select(y => int.Parse(y)).ToArray();
                ln++;
                int N = data[0];
                int L = data[1];


                string[] flows = input[ln].Split(' ').ToArray();
                ln++;
                string[] outlets = input[ln].Split(' ').ToArray();
                ln++;

                bool[,] f = new bool[N,L];

                ulong[] fs = new ulong[N];
                bool[,] o = new bool[N, L];

                for (int i = 0; i < N; ++i)
                {
                    for (int j = 0; j < L; ++j)
                    {
                        f[i, j] = flows[i][j] == '1';
                        o[i, j] = outlets[i][j] == '1';
                        if(flows[i][j] == '1')
                        {
                            fs[i] = fs[i] | (ulong)(1 << j);
                        }
                    }
                }

                HashSet<ulong> vals = new HashSet<ulong>(fs.AsEnumerable());
                HashSet<ulong> vals2 = new HashSet<ulong>();

                int minSeen = 600000;

                bool[] flips = new bool[L];

                for (int i = 0; i < N; ++i)
                {
                    for (int j = 0; j < N; ++j)
                    {
                        int curFlip = 0;
                        for (int k = 0; k < L; ++k)
                        {
                            if (f[i, k] != o[j, k])
                            {
                                flips[k] = true;
                                curFlip++;
                            }
                            else
                            {
                                flips[k] = false;
                            }
                        }
                        ulong[] os = new ulong[N];

                        for (int k = 0; k < N; ++k)
                        {
                            for (int z = 0; z < L; ++z)
                            {
                                if (flips[z] != o[k, z])
                                {
                                    os[k] = os[k] | (ulong)(1 << z);
                                }
                            }
                        }

                        vals2.Clear();
                        foreach (var v in os)
                        {

                            vals2.Add(v);
                        }

                        bool good = true;
                        foreach (var v in vals)
                        {
                            if (!vals2.Contains(v))
                            {
                                good = false;
                                break;
                            }
                        }

                        if (good && curFlip < minSeen)
                        {
                            minSeen = curFlip;
                        }


                    }
                }





                output.WriteLine("Case #{0}: {1}", nc + 1, minSeen == 600000 ? "NOT POSSIBLE" : minSeen.ToString());
                Console.WriteLine("Case #{0}: {1}", nc + 1, minSeen == 600000 ? "NOT POSSIBLE" : minSeen.ToString());
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
