using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;


namespace GCJ11QRQ3
{
    class Q3
    {
        static void Main(string[] args)
        {
            string[] lines = File.ReadAllLines(args[0]);
            List<string> output = new List<string>();
            int cases = int.Parse(lines[0]);
            int index = 1;
            for (int i = 0; i < cases; i++)
            {
                string[] bits = lines[index].Split(' ');
                index++;
                string[] bits2 = lines[index].Split(' ');
                int[] nums = new int[int.Parse(bits[0])];
                for (int j = 0; j < nums.Length; j++)
                {
                    nums[j] = int.Parse(bits2[j]);
                }
                output.Add(string.Format("Case #{0}: {1}", i + 1, Solve(nums)));
                index++;
            }
            File.WriteAllLines("output.txt", output.ToArray());
        }

        private static string Solve(int[] items)
        {
            if (Sum(items) != 0)
                return "NO";
            Array.Sort(items);
            int total = 0;
            for (int i = 1; i < items.Length; i++)
            {
                total += items[i];
            }
            return total.ToString();
        }

        private static int Sum(int[] items)
        {
            int[] sum = new int[25];
            for (int i = 0; i < items.Length; i++)
            {
                Add(sum, items[i]);
            }
            int total = 0;
            for (int i = 0; i < sum.Length; i++)
                total += sum[i] * (1 << i);
            return total;
        }

        private static void Add(int[] sum, int p)
        {
            for (int i = 0; i < 25; i++)
            {
                if ((p & (1 << i)) != 0)
                {
                    sum[i]++;
                    if (sum[i] > 1)
                        sum[i] = 0;
                }
            }
        }
    }
}
