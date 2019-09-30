using System;
using System.Collections.Generic;
using System.IO;

namespace ProblemC
{
    class Program
    {
        static int[] max = new int[1000001];

        static void Preprocess()
        {
            max[1] = 2;
            for (int i = 2; i < max.Length; i++)
            {
                int index = Array.BinarySearch(max, 1, i - 1, i);
                if (index < 0)
                    index = ~index - 1;
                max[i] = index + i + 1;
            }
        }

        static long Count(int maxA, int maxB)
        {
            if (maxA > maxB)
            {
                return Count(maxB, maxA);
            }

            long result = 0;
            for (int i = 1; i <= maxA; i++)
            {
                if (maxB < max[i] - i)
                {
                    result += maxB;
                }
                else if (maxB < max[i])
                {
                    result += max[i] - i - 1;
                }
                else
                {
                    result += maxB - i;
                }
            }
            return result;
        }

        static void Main(string[] args)
        {
            Preprocess();

            using (StreamWriter writer = new StreamWriter("..\\..\\output.txt"))
            {
                using (StreamReader reader = new StreamReader("..\\..\\input.txt"))
                {
                    int total = Int32.Parse(reader.ReadLine());
                    for (int i = 0; i < total; i++)
                    {
                        string[] temp = reader.ReadLine().Split();
                        int a1 = Int32.Parse(temp[0]);
                        int a2 = Int32.Parse(temp[1]);
                        int b1 = Int32.Parse(temp[2]);
                        int b2 = Int32.Parse(temp[3]);
                        long res = Count(a1 - 1, b1 - 1) + Count(a2, b2) - Count(a1 - 1, b2) - Count(a2, b1 - 1);
                        writer.Write("Case #" + (i + 1) + ": ");
                        writer.WriteLine(res);
                    }
                }
            }
        }
    }
}
