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
        public static string Reverse(string s)
        {
            char[] charArray = s.ToCharArray();
            Array.Reverse(charArray);
            return new string(charArray);
        }

        static void Main(string[] args)
        {
            var root = @"D:\gcj\p1\";

            long[] l = new long[16];
            l[1] = 9;

            for (long i = 2; i < 16; ++i)
            {
                long half = (i) / 2;
                long steps = 1;

                long exp = 1;
                for(int j = 0; j < half; ++j)
                {
                    exp *= 10;
                }

                steps += (exp - 1) * 2;

                if ((i + 1) / 2 != half)
                {
                    long bHalf = (i + 1) / 2;
                    exp = 1;
                    for (int j = 0; j < bHalf; ++j)
                    {
                        exp *= 10;
                    }
                    steps += (exp * 9) / 10;
                }

                l[i] = steps;

                Console.WriteLine("For {0} steps are {1}", i, l[i]);
            }

            string[] input = System.IO.File.ReadAllLines(root + "small.txt");
            StreamWriter output = new StreamWriter(root + "out.txt");
            long[] data = input.SelectMany(x => x.Split(' ').Select(y => long.Parse(y))).ToArray();
            IEnumerator<long> scanner = data.AsEnumerable<long>().GetEnumerator();
            scanner.MoveNext();
            long numCases = scanner.Current;
            for(long nc = 0; nc < numCases; ++nc)
            {
                scanner.MoveNext();
                long n = (long)scanner.Current;

                int numDig = n.ToString().Length;


                long res = 1;

                if (numDig == 1)
                {
                    res += n - 1;
                }
                else
                {
                    for (int i = 1; i <= numDig - 1; ++i)
                    {
                        res += l[i];
                    }

                    long half = (numDig + 1) / 2;
                    long sHalf = (numDig)/2;

                    string substr = n.ToString().Substring(0, (int)sHalf);
                    string rev = Reverse(substr);
                    bool trivial = true;
                    for (int i = 0; i < substr.Length; ++i)
                    {
                        if (i == 0 && substr[i] != '1')
                        {
                            trivial = false;
                        }
                        else if (i != 0 && substr[i] != '0')
                        {
                            trivial = false;
                        }
                    }


                    if (!trivial && long.Parse(n.ToString().Substring((int)half)) == 0)
                    {
                        n--;
                        substr = n.ToString().Substring(0, (int)sHalf);
                        rev = Reverse(substr);
                        res += 1;
                        trivial = true;
                        for (int i = 0; i < substr.Length; ++i)
                        {
                            if (i == 0 && substr[i] != '1')
                            {
                                trivial = false;
                            }
                            else if (i != 0 && substr[i] != '0')
                            {
                                trivial = false;
                            }
                        }
                    }


                    if (!trivial)
                    {
                        res += long.Parse(rev);
                    }

                    if (half != sHalf)
                    {

                        string s = "";
                        s += n.ToString()[(int)sHalf];
                        for(int i = 0; i < (int) sHalf; ++i)
                        {
                            s += "0";
                        }
                        res += long.Parse(s);
                    }


                    substr = n.ToString().Substring((int)half);
                    res += long.Parse(substr);

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
