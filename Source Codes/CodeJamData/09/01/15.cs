using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GoogleCodeJam2009
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] input = File.ReadAllLines("A-large.in");
            string output = "";
            int lineAt = 0;
            string[] cases = input[lineAt++].Split(' ');
            int L = int.Parse(cases[0]);
            int D = int.Parse(cases[1]);
            int N = int.Parse(cases[2]);
            List<string> words = new List<string>();
            for (int i = 0; i < D; i++)
            {
                words.Add(input[lineAt++]);
            }
            for (int i = 0; i < N; i++)
            {
                string res = input[lineAt++];
                List<string> blah = new List<string>();
                int at = 0;
                for (int j = 0; j < L; j++)
                {
                    if (res[at] == '(')
                    {
                        int end = res.IndexOf(')', at);
                        blah.Add(res.Substring(at, end - at));
                        at = end + 1;
                    }
                    else
                    {
                        blah.Add("" + res[at]);
                        at++;
                    }
                }
                int possible = D;
                bool[] bad = new bool[D];
                for (int j = 0; j < L; j++)
                {
                    for (int k = 0; k < D; k++)
                    {
                        if (!bad[k])
                        {
                            if (!blah[j].Contains(words[k][j]))
                            {
                                bad[k] = true;
                                possible--;
                            }
                        }
                    }
                }
                output += "Case #" + (i + 1) + ": " + possible + Environment.NewLine;
            }
            File.WriteAllText("output.txt", output);
            Console.WriteLine(output);
        }
    }
}
