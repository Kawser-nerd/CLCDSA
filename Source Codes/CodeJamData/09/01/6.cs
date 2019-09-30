using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;

namespace GCJ
{
    class Program
    {
        static void Main(string[] args)
        {
            int N, D, L;
            List<string> words = new List<string>();
            List<string> tests = new List<string>();

            string filePath = @"C:\A-large.in";
            
            using(StreamReader reader = new StreamReader(filePath))
            {
                var numbers = reader.ReadLine().Split(' ');
                L = int.Parse(numbers[0]);
                D = int.Parse(numbers[1]);
                N = int.Parse(numbers[2]);

                for (int i = 0; i < D; i++)
                    words.Add(reader.ReadLine());

                for (int i = 0; i < N; i++)
                    tests.Add(reader.ReadLine());
            }

            using (StreamWriter writer = new StreamWriter(@"C:\result.txt"))
            {
                for (int i = 0; i < tests.Count; i++)
                {
                    string rx = string.Format("^{0}$", tests[i].Replace('(', '[').Replace(')', ']'));
                    var matches = words.Count(w => Regex.IsMatch(w, rx));
                    writer.WriteLine(string.Format("Case #{0}: {1}", i + 1, matches));
                }
            }
        }
    }
}
