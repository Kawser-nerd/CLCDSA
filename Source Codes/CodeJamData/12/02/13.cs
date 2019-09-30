using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;


namespace ConsoleApplication2
{
    class Program
    {
        static void Main(string[] args)
        {
            using (StreamWriter writer = new StreamWriter(@"d:\output.txt"))
            {
                using (StreamReader reader = new StreamReader(@"d:\input.txt"))
                {
                    int count = int.Parse(reader.ReadLine());
                    for (int i = 0; i < count; i++)
                    {
                        Process(i + 1, reader.ReadLine(), writer);
                    }
                }
            }
        }

        private static void Process(int line, string input, StreamWriter writer)
        {
            var row = input.Split(' ');
            var N = int.Parse(row[0]);
            var S = int.Parse(row[1]);
            var p = int.Parse(row[2]);
            var totalPoints = new List<int>();
            for (int i = 0; i < N; i++)
            {
                totalPoints.Add(int.Parse(row[3 + i]));
            }

            var surprising = p + Math.Max(0, (p - 2)) * 2;
            var not_surprising = p + Math.Max(0, (p - 1)) * 2;

            int max_surprising = 0;
            int max_not_surprising = 0;
            foreach (var total in totalPoints)
            {
                if (total >= surprising)
                {
                    max_surprising++;
                }
                if (total >= not_surprising)
                {
                    max_not_surprising++;
                }
            }

            var added = Math.Min(max_surprising - max_not_surprising, S);

            var result = max_not_surprising + added;

            writer.WriteLine("Case #{0}: {1}", line, result);
        }
    }

}