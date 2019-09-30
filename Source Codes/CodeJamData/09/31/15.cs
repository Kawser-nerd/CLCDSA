using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace A
{
    class Program
    {
        static void Main(string[] args)
        {
            const string inputFileName = "A-large.in";
            const string outputFileName = "A-large.out.txt";
            var input = new StreamReader(inputFileName);
            var output = new StreamWriter(outputFileName);
            var tc = int.Parse(input.ReadLine());
            for (int t = 0; t < tc; t++)
            {
                var s = input.ReadLine();
                var symbol = new Dictionary<char, int>();
                for (int i = 0; i < s.Length; i++)
                {
                    if (!symbol.ContainsKey(s[i]))
                    {
                        symbol.Add(s[i], -1);
                    }
                }
                var b = symbol.Count + (symbol.Count == 1 ? 1 : 0);
                var n = new List<int>();
                var first = true;
                var second = false;
                var d = 2;
                for (int i = 0; i < s.Length; i++)
                {
                    if (symbol[s[i]] == -1)
                    {
                        if (first)
                        {
                            first = false;
                            second = true;
                            symbol[s[i]] = 1;
                        }
                        else if (second)
                        {
                            second = false;
                            symbol[s[i]] = 0;
                        }
                        else
                        {
                            symbol[s[i]] = d;
                            ++d;
                        }
                    }
                    n.Add(symbol[s[i]]);
                }
                long a = 0, c = 1;
                for (int i = n.Count - 1; i >= 0; --i)
                {
                    a += n[i]*c;
                    c *= b;
                }
                output.WriteLine("Case #{0}: {1}", t + 1, a);
            }
            output.Close();
        }
    }
}
