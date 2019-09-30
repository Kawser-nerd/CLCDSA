/*  Author: Ben Olden-Cooligan
 *  Email: blue0fish@gmail.com
 *  Google Code Jam 2009 Question A
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
    class ProgramA
    {
        static string input = "A-large.in";
        static string output = "A-large.out";

        static void Main(string[] args)
        {
            using (StreamReader sr = new StreamReader(input))
            {
                using (StreamWriter sw = new StreamWriter(output))
                {
                    int L, D, N;
                    L = sr.ReadInt32WSV();
                    D = sr.ReadInt32WSV();
                    N = sr.ReadInt32WSV();
                    List<string> words = new List<string>();
                    for (int i = 0; i < D; ++i)
                    {
                        words.Add(sr.ReadWSV());
                    }
                    for (int i = 0; i < N; ++i)
                    {
                        string pattern = sr.ReadWSV().Replace("(", "[").Replace(")", "]");
                        int count = words.Count(new Func<string, bool>(w => Regex.IsMatch(w, pattern)));
                        sw.WriteLine("Case #{0}: {1}", i + 1, count);
                    }
                }
            }
        }
    }
}
