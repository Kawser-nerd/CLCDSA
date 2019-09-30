/*  Author: Ben Olden-Cooligan
 *  Email: blue0fish@gmail.com
 *  Google Code Jam 2009 Question C
 */

using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using Cylan.Extensions.Streaming.Text.WSV;

namespace CodeJam2009Qualification
{
    static class ProgramC
    {
        static string input = "C-large.in";
        static string output = "C-large.out";

        static string search = "welcome to code jam";

        static void Main(string[] args)
        {
            using (StreamReader sr = new StreamReader(input))
            {
                using (StreamWriter sw = new StreamWriter(output))
                {
                    int N = sr.ReadInt32WSV();
                    for (int i = 0; i < N; ++i)
                    {
                        string line = sr.ReadLine();
                        int[][] count = new int[search.Length][];

                        for (int k = 0; k < search.Length; ++k)
                        {
                            count[k] = new int[line.Length];
                            for (int j = k; j < line.Length; ++j)
                            {
                                if (k == 0)
                                {
                                    if (j == 0)
                                    {
                                        count[k][j] = line.FromEnd(j) == search.FromEnd(k) ? 1 : 0;
                                    }
                                    else
                                    {
                                        count[k][j] = count[k][j - 1] + (line.FromEnd(j) == search.FromEnd(k) ? 1 : 0);
                                    }
                                }
                                else
                                {
                                    if (j == k)
                                    {
                                        count[k][j] = count[k - 1][j - 1] * (line.FromEnd(j) == search.FromEnd(k) ? 1 : 0);
                                    }
                                    else
                                    {
                                        count[k][j] = count[k][j - 1] + count[k - 1][j - 1] * (line.FromEnd(j) == search.FromEnd(k) ? 1 : 0);
                                    }
                                }

                                count[k][j] %= 10000;
                            }
                        }

                        sw.WriteLine("Case #{0}: {1}", i + 1, count[search.Length - 1][line.Length - 1].ToString("D4"));
                    }
                }
            }
        }

        static char FromEnd(this string str, int index)
        {
            return str[str.Length - index - 1];
        }
    }
}
