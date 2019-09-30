using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;

namespace ConsoleApp3
{
    class Program
    {
        static void Main(string[] args)
        {
            string input = Console.ReadLine();


                int[] nums = input.Split(' ').Select(x => int.Parse(x)).ToArray();
                if (nums[1] <= nums[2] || nums[3] <= nums[0])
                {
                    Console.WriteLine("0");
                }
                else
                {
                    Console.WriteLine(Math.Min(nums[3], nums[1]) - Math.Max(nums[2], nums[0]));
                }

            return;
        }
    }
}