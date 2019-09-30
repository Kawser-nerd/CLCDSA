using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;


namespace ConsoleApplication3
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
            var A = int.Parse(row[0]);
            var B = int.Parse(row[1]);
            var AStr = A.ToString();
            var BStr = B.ToString();

            var countA = AStr.Length;
            var countB = BStr.Length;

            int count = 0;
            HashSet<int> ms = new HashSet<int>();
            for (int n = A; n <= B; n++)
            {
                ms.Clear();
                int len = (int)Math.Floor(Math.Log10(n)) + 1;
                for (var j = 1; j < len; j++)
                {
                    int m = M(len, n, j);
                    if (m > n && m <= B)
                        ms.Add(m);
                }
                count += ms.Count;
            }
            writer.WriteLine("Case #{0}: {1}", line, count);
        }

        private static int M(int len, int n, int j)
        {
            int power = (int)Math.Pow(10, j);
            int m = (n % power) * (int)Math.Pow(10, (len - j));
            m += (n / power);
            return m;
        }
    }

}