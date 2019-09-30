using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Numerics;


namespace GCJ11QRQ4
{
    class Q4
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

        private static string Solve(int[] nums)
        {
            int total = 0;
            for (int i = 0; i < nums.Length; i++)
                if (nums[i] != i + 1)
                    total++;
            return total.ToString();
        }
  }
}
