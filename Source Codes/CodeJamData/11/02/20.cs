using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace BotTrust
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader reader = new StreamReader("input.txt");
            StreamWriter writer = new StreamWriter("output.txt");
            int n = int.Parse(reader.ReadLine());
            for (int i = 1; i <= n; i++)
            {

                string line = reader.ReadLine();
                string[] parts = line.Split(' ');

                int offset = 1;
                char[,] combos = new char[256, 256];

                string[] tabus = Enumerable.Repeat("", 256).ToArray();

                int segs = int.Parse(parts[0]);
                for (int j = 0; j < segs; j++)
                {
                    string comb = parts[j + offset];
                    combos[comb[0], comb[1]] = combos[comb[1], comb[0]] = comb[2];
                }
                offset += segs;

                segs = int.Parse(parts[offset]);
                offset++;
                for (int j = 0; j < segs; j++)
                {
                    string comb = parts[j + offset];
                    tabus[comb[0]] += comb[1];
                    tabus[comb[1]] += comb[0]; 
                }
                offset += segs;

                List<char> current = new List<char>();
                foreach (char c in parts[offset + 1])
                {
                    char comb = current.Count == 0 ? '\0' : combos[c, current[current.Count - 1]];
                    if (comb != '\0')
                        current[current.Count - 1] = comb;
                    else
                    {
                        string tabu = tabus[c];
                        if (current.Any(x => tabu.Contains(x)))
                            current.Clear();
                        else
                            current.Add(c);
                    }
                }

                writer.WriteLine("Case #{0}: [{1}]", i, string.Join(", ",current.Select(x => x.ToString()).ToArray()));


            }
            reader.Close();
            writer.Close();
        }
    }
}
