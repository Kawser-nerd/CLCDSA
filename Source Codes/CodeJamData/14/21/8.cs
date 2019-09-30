using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace _1ba
{
    class Program
    {
        static void Main(string[] args)
        {
            string file = "A-large";
            string inputFile = file + ".in";
            string outputFile = file + ".out";

            using (StreamWriter writer = new StreamWriter(outputFile))
            {


                using (StreamReader reader = new StreamReader(inputFile))
                {
                    int t = int.Parse(reader.ReadLine());
                    for (int i = 0; i < t; i++)
                    {
                        int n = int.Parse(reader.ReadLine());
                        List<List<Element>> strings = new List<List<Element>>(n);
                        for (int j = 0; j < n; j++)
                        {
                            strings.Add(ReadString(reader.ReadLine()));
                        }
                        int nbChar = strings[0].Count;
                        bool possible = strings.All(o => o.Count == nbChar);
                        int res = 0;
                        if (possible)
                        {
                            for (int j = 0; j < nbChar; j++)
                            {
                                possible = possible && strings.Select(o => o[j].c).Distinct().Count() == 1;
                                if (possible)
                                {

                                    var allNb = strings.Select(o => o[j].nb).ToArray();
                                    int min = allNb.Min();
                                    int max = allNb.Max();
                                    int temp = -1;
                                    for (int k = min; k <= max; k++)
                                    {
                                        int current = allNb.Sum(o => Math.Abs(o - k));
                                        if (temp == -1 || temp > current)
                                        {
                                            temp = current;
                                        }
                                    }
                                    res += temp;
                                }
                            }
                        }

                        writer.WriteLine("Case #{0}: {1}", i + 1, possible ? res.ToString() : "Fegla Won");
                    }
                }
            }
        }
        private static List<Element> ReadString(string s)
        {
            List<Element> res = new List<Element>();
            Element lastElt = null;
            int i = 0;
            while (i < s.Length)
            {
                if (lastElt == null || lastElt.c != s[i])
                {
                    lastElt = new Element();
                    res.Add(lastElt);
                    lastElt.c = s[i];
                }
                lastElt.nb++;
                i++;
            }
            return res;
        }

        class Element
        {
            public char c { get; set; }
            public int nb { get; set; }
        }



    }
}
