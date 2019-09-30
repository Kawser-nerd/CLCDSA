using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

namespace MyProgram
{
    public class Program
    {	
        public static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int[] nums = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
            
            Array.Sort(nums);
            
            Console.WriteLine(Math.Abs(nums[nums.Count()-1]-nums[0]));
        }
    }
}