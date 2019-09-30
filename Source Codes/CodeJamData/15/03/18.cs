using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace ProblemC
{
    class Program
    {
        const int num = 128;

        static void Main(string[] args)
        {
            string inputFile = @"e:\codejam\C-large.in";
            string outputFile = @"e:\codejam\C-large.out";
            


            string [,] lookupRaw = new string[4,4]
            {
                {"1", "i", "j", "k"},
                {"i", "-1", "k", "-j"},
                {"j","-k","-1","i"},
                {"k","j","-i", "-1"}
            };

            string [] lookupSymbol = {"1", "i","j","k"};

            Dictionary<string, int> symbolDict = new Dictionary<string,int>();
            for (int i = 0; i < lookupSymbol.Length; ++i)
                symbolDict[lookupSymbol[i]] = i+1;

            int[,] lookup = new int[5, 5];
            for (int i = 0; i < 4; ++i )
            {
                for (int j =0;j<4;++j)
                {
                    int sign = 1;
                    string symbol = lookupRaw[i, j];
                    if (lookupRaw[i,j].StartsWith("-"))
                    {
                        sign = -1;
                        symbol = lookupRaw[i, j].Substring(1, 1);
                    }
                    int num = 0;
                    for (int k =0;k<lookupSymbol.Length; ++k)
                        if (symbol ==lookupSymbol[k])
                        {
                            num = k+1;
                        }
                    lookup[i + 1, j + 1] = num * sign;
                }
            }

                using (StreamReader sr = new StreamReader(inputFile))
                {
                    using (StreamWriter sw = new StreamWriter(outputFile))
                    {
                        int T = int.Parse(sr.ReadLine());
                        for (int i1 = 1; i1 <= T; ++i1)
                        {
                            string line = sr.ReadLine();
                            long l, x;
                            l = long.Parse(line.Split(' ')[0]);
                            x = long.Parse(line.Split(' ')[1]);

                            string st = sr.ReadLine();

                            int g = 1;
                            for (int i = 0; i < st.Length; ++i )
                            {
                                int sign = Math.Sign(g);
                                int abs = Math.Abs(g);
                                g = sign * lookup[abs, symbolDict[st[i].ToString()]];
                            };

                            int g0 = 1;
                            int g1 = g;

                            long y = x;
                            while (y >= 1)
                            {
                                if (y % 2 == 1)
                                {
                                    int sign = Math.Sign(g0) * Math.Sign(g1);
                                    int abs = Math.Abs(g0);
                                    g0 = sign * lookup[abs, Math.Abs(g1)];
                                };
                                int sign1 = Math.Sign(g1) * Math.Sign(g1);
                                int abs1 = Math.Abs(g1);
                                g1 = sign1 * lookup[abs1, Math.Abs(g1)];
                                y = y / 2;
                            }

                            if (g0 != -1)
                            {
                                sw.WriteLine("Case #{0}: NO", i1);
                                continue;
                            }

                            if (x > 12) x = 12;

                            StringBuilder sb = new StringBuilder();
                            for (int i = 0; i < x; ++i)
                                sb.Append(st);


                            string r = sb.ToString();
                            int[] partial = new int[r.Length];

                            g = 1;
                            for (int i = 0; i < r.Length; ++i)
                            {
                                int sign = Math.Sign(g);
                                int abs = Math.Abs(g);

                                partial[i] = sign*lookup[abs, symbolDict[r[i].ToString()]];
                                g = partial[i];
                            };

                            bool found = false;
                            Console.WriteLine(r.Length);
                            for (int i = 0; i < r.Length; ++i)
                            {
                                if (partial[i] == 2)
                                {
                                    for (int j = i+1; j < r.Length; ++j)
                                    {
                                        if (partial[j] == lookup[2,3])
                                        {
                                            sw.WriteLine("Case #{0}: YES", i1);
                                            found = true;
                                            break;
                                        }
                                        if (found) break;
                                    }
                                }
                                if (found) break;
                            }

                            if (found) continue;
                            sw.WriteLine("Case #{0}: NO", i1);                            
                        }
                    }
                }
        }
    }
}
