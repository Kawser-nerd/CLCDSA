using System;
using System.Linq;

namespace BegginerContest_002_A
{
    class Program
    {
        static void Main(string[] args)
        {
            decimal[] nums = Console.ReadLine().Split(' ').Select(decimal.Parse).ToArray();
            Console.WriteLine(nums[0] > nums[1] ? nums[0] : nums[1]);
        }
    }
}