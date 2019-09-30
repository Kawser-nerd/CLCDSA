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

          

            string[] input = System.IO.File.ReadAllLines(root + "small.txt");
            StreamWriter output = new StreamWriter(root + "out.txt");
            long numCases = long.Parse(input[0]);
            long lineNum = 0;

            for(long nc = 0; nc < numCases; ++nc)
            {
                lineNum++;
                long[] data = input[lineNum].Split(' ').Select(y => long.Parse(y)).ToArray();
                int R = (int)data[0];
                int C = (int)data[1];
                char[,] grid = new char[data[0], data[1]];
                for (long r = 0; r < data[0]; ++r)
                {
                    lineNum++;
                    string s = input[lineNum].Trim();
                    for(int c = 0; c < s.Length; ++ c)
                    {
                        grid[r, c] = s[c];
                    }
                }

                int res = 0;
                bool pos = true;
                for (int i = 0; i < R; ++i)
                {
                    for (int j = 0; j < C; ++j)
                    {
                        if (grid[i, j] != '.')
                        {
                            bool hasUp = false;
                            bool hasDown = false;
                            bool hasRight = false;
                            bool hasLeft = false;
                            for (int ii = 0; ii < i; ++ii)
                            {
                                if (grid[ii, j] != '.')
                                {
                                    hasUp = true;
                                }
                            }
                            for (int ii = i + 1; ii < R; ++ii)
                            {
                                if (grid[ii, j] != '.')
                                {
                                    hasDown = true;
                                }
                            }

                            for (int jj = 0; jj < j; ++jj)
                            {
                                if (grid[i, jj] != '.')
                                {
                                    hasLeft = true;
                                }
                            }

                            for (int jj = j + 1; jj < C; ++jj)
                            {
                                if (grid[i, jj] != '.')
                                {
                                    hasRight = true;
                                }
                            }


                            if (grid[i, j] == '^')
                            {
                                if (hasUp)
                                {
                                    continue;
                                }
                                else if (hasLeft || hasDown || hasRight)
                                {
                                    res++;
                                }
                                else
                                {
                                    pos = false;
                                    break;
                                }
                            }

                            if (grid[i, j] == 'v')
                            {
                                if (hasDown)
                                {
                                    continue;
                                }
                                else if (hasLeft || hasUp || hasRight)
                                {
                                    res++;
                                }
                                else
                                {
                                    pos = false;
                                    break;
                                }
                            }


                            if (grid[i, j] == '>')
                            {
                                if (hasRight)
                                {
                                    continue;
                                }
                                else if (hasLeft || hasUp || hasDown)
                                {
                                    res++;
                                }
                                else
                                {
                                    pos = false;
                                    break;
                                }
                            }

                            if (grid[i, j] == '<')
                            {
                                if (hasLeft)
                                {
                                    continue;
                                }
                                else if (hasRight || hasUp || hasDown)
                                {
                                    res++;
                                }
                                else
                                {
                                    pos = false;
                                    break;
                                }
                            }
                        }
                    }
                }




                output.WriteLine("Case #{0}: {1}", nc + 1, !pos ? "IMPOSSIBLE" : res.ToString());
                Console.WriteLine("Case #{0}: {1}", nc + 1, !pos ? "IMPOSSIBLE" : res.ToString());
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
