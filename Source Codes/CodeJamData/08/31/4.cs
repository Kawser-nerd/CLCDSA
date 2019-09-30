using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace R1c._1
{
    class Program
    {
        static void Main(string[] args)
        {
            using (StreamReader reader = new StreamReader(args[0]))
            {
                using (StreamWriter writer = new StreamWriter(args[1]))
                {
                    int casesCount = int.Parse(reader.ReadLine());
                    for (int i = 0; i < casesCount; i++)
                    {
                        int[] parameters = reader.ReadLine().Split().Select(s => int.Parse(s)).ToArray();
                        List<int> frequencies = reader.ReadLine().Split().Select(s => int.Parse(s)).ToList();

                        long result = FindResult(parameters[0], parameters[1], frequencies);

                        writer.WriteLine("Case #{0}: {1}", i + 1, result);
                    }
                }
            }
        }

        private static long FindResult(int lettersOnKey, int keys, List<int> frequencies)
        {
            long result = 0;
            frequencies.Sort((a, b) => (b - a));
            for (int i = 0; i < frequencies.Count; i++)
            {
                result += frequencies[i] * (i / keys + 1);
            }
            return result;
        }

    }
}
