using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace gcj15r1c
{
    class Program
    {
        static void Main(string[] args)
        {
            {
                string root = @"C:\Users\Josiah\Downloads\";
                string problem = "B";
                //string ptype = "small-attempt0";
                string ptype = "Large";

                string[] lines = System.IO.File.ReadAllLines(string.Format("{0}{1}-{2}.in", root, problem, ptype));
                TextWriter tw = new StreamWriter(string.Format("{0}{1}-{2}.out", root, problem, ptype));

                int idx = 0;
                int t = int.Parse(lines[idx++]);
                for (int a = 0; a < t; a++)
                {
                    string[] line = lines[idx++].Split(' ');
                    int K = int.Parse(line[0]);
                    int L = int.Parse(line[1]);
                    int S = int.Parse(line[2]);
                    string keys = lines[idx++];
                    int[] kcount = new int[26];
                    for (int b = 0; b < keys.Length; b++)
                    {
                        kcount[keys[b] - 'A']++;
                    }
                    string word = lines[idx++];
                    double prob = 1;
                    for (int b = 0; b < word.Length; b++)
                    {
                        prob *= (kcount[word[b] - 'A']) / (1.0 * K);
                    }
                    prob *= (S - L +1);
                    long max = 0;
                    if (prob != 0){
                        max = calcmax(keys, S, word);
                    }
                    tw.WriteLine("Case #{0}: {1}", a + 1, max - prob);
                }

                tw.Close();
            }
        }

        private static long calcmax(string keys, int S, string word)
        {
            string maxS = word;
            long count = 1;
            int starti = 1;
            while (maxS.Length < S)
            {
                int i = starti;
                int j = 0;
                while (i < maxS.Length && maxS[i] == word[j])
                {
                    i++;
                    j++;
                }
                if (i == maxS.Length)
                {
                    if (maxS.Length + word.Length - j <= S)
                    {
                        maxS += word.Substring(j);
                        count++;
                    }
                    else
                    {
                        return count;
                    }
                }
                starti++;
            }
            return count;
        }
    }
}
