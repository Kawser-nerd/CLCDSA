using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ09R1AQ1
{
    class Program
    {
        static void Main(string[] args)
        {
            Dictionary<int, int> blah = MakeHappys();
            string[] file = File.ReadAllLines(args[0]);
            List<string> output = new List<string>();
            int count = int.Parse(file[0]);
            int offset = 1;
            for (int counter=0;counter < count; counter++)
            {
                string[] bits = file[offset].Split(' ');
                int[] bases = new int[bits.Length];
                for (int i = 0; i < bits.Length; i++)
                {
                    bases[i] = int.Parse(bits[i]);
                }
                offset++;
                output.Add(string.Format("Case #{0}: {1}", counter + 1, Solve(bases, blah)));
            }
            File.WriteAllLines("output.txt", output.ToArray());
        }

        private static Dictionary<int, int> MakeHappys()
        {
            Dictionary<int, int> blah = new Dictionary<int, int>();
            int[,] array = new int[11, 2000];
            int offset = 2;
            while (blah.Count < 256)
            {
                int powerset = 0;
                for (int i = 3; i <= 10; i++)
                {
                    int res = Calc(array, i, offset);
                    if (res == 1)
                        powerset |= 1 << i;
                }
                if (!blah.ContainsKey(powerset))
                {
                    for (int j = 0; j <= powerset; j++)
                    {
                        if ((j & powerset) == j)
                            if (!blah.ContainsKey(j))
                            {
                                blah[j] = offset;
                            }
                    }
                }
                offset++;
            }
            return blah;
        }

        private static int Calc(int[,] array, int i, int offset)
        {
            if (offset == 1)
                return 1;
            if (offset < 2000)
            {
                if (array[i, offset] != 0)
                    return array[i, offset];
                array[i, offset] = -1;
            }
            int sum = Sum(offset, i);
            int res = Calc(array, i, sum);
            if (offset < 2000)
            {
                if (array[i, offset] == -1)
                    array[i, offset] = res;
            }
            return res;
        }

        private static int Sum(int offset, int i)
        {
            int sum = 0;
            while (offset != 0)
            {
                int part = offset % i;
                sum += part * part;
                offset /= i;
            }
            return sum;
        }

        private static long Solve(int[] bases, Dictionary<int, int> lookup)
        {
            int offset = 0;
            for (int i = 0; i < bases.Length; i++)
            {
                if (bases[i] != 2)
                {
                    offset |= 1 << bases[i];
                }
            }
            return lookup[offset];
        }
    }
}
