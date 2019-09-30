using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Diagnostics;
using System.Runtime.Serialization.Formatters.Binary;

namespace Marius.CodeJam.A
{
    public static class Program
    {
        public static void Main(string[] args)
        {
            if (args.Length == 2)
            {
                Console.SetIn(new StreamReader(args[0]));
                Console.SetOut(new StreamWriter(args[1]));
            }

            int[] nums;

            if (!File.Exists("nums.dat"))
            {
                nums = new int[11814486];
                nums[1] = 0x7FFFFFFF;

                for (int i = 2; i < nums.Length; i++)
                {
                    for (int j = 2; j <= 10; j++)
                    {
                        nums[i] |= ((1 << j) << 11);
                        if (IsHappy(nums, i, j))
                        {
                            nums[i] |= (1 << j);
                        }
                    }
                }

                using (var fs = new FileStream("nums.dat", FileMode.CreateNew))
                {
                    BinaryFormatter fmt = new BinaryFormatter();
                    fmt.Serialize(fs, nums);
                }
            }
            else
            {
                using (var fs = new FileStream("nums.dat", FileMode.Open))
                {
                    BinaryFormatter fmt = new BinaryFormatter();
                    nums = (int[])fmt.Deserialize(fs);
                }
            }



            int numCases = int.Parse(Console.ReadLine().Trim());
            for (int currentCase = 1; currentCase <= numCases; currentCase++)
            {
                var bases = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();

                int m = 0;
                foreach (var item in bases)
                {
                    m |= (1 << item);
                }

                Console.Write("Case #{0}: ", currentCase);
                for (int i = 2; i < nums.Length; i++)
                {
                    var item = nums[i];

                    if ((item & m) == m)
                    {
                        Console.WriteLine(i);
                        break;
                    }
                }

            }

            if (args.Length == 2)
            {
                Console.In.Close();
                Console.Out.Close();

                Console.SetIn(new StreamReader(Console.OpenStandardInput()));
                Console.SetOut(new StreamWriter(Console.OpenStandardOutput()));
            }
        }

        private static bool IsHappy(int[] nums, int number, int bas)
        {
            int t = 0;
            while (number > 0)
            {
                t += (number % bas).S();
                number /= bas;
            }

            number = t;
            if ((nums[number] & ((1 << bas) << 11)) == 0)
            {
                nums[number] |= ((1 << bas) << 11);
                bool isHappy = IsHappy(nums, number, bas);

                if (isHappy)
                    nums[number] |= (1 << bas);
            }

            return (nums[number] & (1 << bas)) != 0;
        }

        private static int S(this int n)
        {
            return n * n;
        }
    }
}
