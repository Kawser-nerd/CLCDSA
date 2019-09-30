using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ09R2Q1
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] file = File.ReadAllLines(args[0]);
            List<string> output = new List<string>();
            int count = int.Parse(file[0]);
            int offset = 1;
            for (int counter = 0; counter < count; counter++)
            {
                int N = int.Parse(file[offset]);
                offset++;
                int[] offsets = new int[N];
                for (int i = 0; i < N; i++)
                {
                    int greatest = -1;
                    for (int j = 0; j < N; j++)
                    {
                        if (file[offset][j] == '1')
                            greatest = j;
                    }
                    offsets[i] = greatest;
                    offset++;
                }
                output.Add(string.Format("Case #{0}: {1}", counter + 1, Solve(offsets)));
            }
            File.WriteAllLines("output.txt", output.ToArray());

        }

        private static int Solve(int[] offsets)
        {
            // number of adjacent swaps such that each number in offsets is less than or equal to its index.
            // 3
            // 2
            // 1
            // 0
            int swaps = 0;
            for (int i = 0; i < offsets.Length - 1; i++)
            {
                if (offsets[i] <= i)
                    continue;
                int j = i + 1;
                while (j < offsets.Length && offsets[j] > i)
                    j++;
                for (int k = j; k > i; k--)
                {
                    int temp = offsets[k];
                    offsets[k] = offsets[k-1];
                    offsets[k-1] = temp;
                    swaps++;
                }
            }
            return swaps;
        }
    }
}
