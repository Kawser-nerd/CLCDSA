using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Numerics;

namespace _1bb
{
    class Program
    {
        static void Main(string[] args)
        {
            string file = "B-large";
            string inputFile = file + ".in";
            string outputFile = file + ".out";

            using (StreamWriter writer = new StreamWriter(outputFile))
            {


                using (StreamReader reader = new StreamReader(inputFile))
                {
                    int t = int.Parse(reader.ReadLine());
                    for (int i = 0; i < t; i++)
                    {
                        var r = ReadLine(reader.ReadLine());
                        BigInteger a = Math.Max(r[0], r[1]);
                        BigInteger b = Math.Min(r[0], r[1]);
                        BigInteger k = r[2];
                        BigInteger res = 0;
                        if (k > b)
                        {
                            res = a * b;
                        }
                        else
                        {
                            res = a * k;
                            for (BigInteger m = k; m < b; m++)
                            {
                                res += k;
                                for (BigInteger n = k; n < a; n++)
                                {
                                    if ((m & n) < k)
                                    {
                                        res++;
                                    }
                                }
                            }
                        }



                        writer.WriteLine("Case #{0}: {1}", i + 1, res);
                    }
                }
            }
        }

        static int[] ReadLine(string line)
        {
            int[] res = line.Split(' ').Select(o => int.Parse(o)).ToArray();
            return res;
        }


    }
}
