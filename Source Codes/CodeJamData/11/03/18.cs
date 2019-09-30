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

                int c = int.Parse(reader.ReadLine());
                string[] parts = reader.ReadLine().Split(' ');
                int sum = 0;
                int min = int.MaxValue;
                int sum2 = 0;
                int[] cs = new int[c];
                int temp;
                for (int j = 0; j < c; j++)
                {
                    temp = int.Parse(parts[j]);
                    cs[j] = temp;
                    sum2 += temp;
                    sum ^= temp;
                    if (temp < min)
                        min = temp;
                }

                string result = "NO";

                if (sum == 0)
                    result = (sum2 - min).ToString();

                writer.WriteLine("Case #{0}: {1}", i, result);
            }
            reader.Close();
            writer.Close();
        }
    }
}
