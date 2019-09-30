using System;
using System.Collections.Generic;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            string N = Console.ReadLine();
            string[] strs = Console.ReadLine().Split(' ');

            List<long> nums = new List<long>();

            foreach(string s in strs)
            {
                nums.Add(long.Parse(s));
            }

            nums.Sort();
            nums.Reverse();

            long x = 0;
            long y = 0;
            bool isXfound = false;
            bool isYfound = false;

            int length = nums.Count;
            for (int i = 0; i < length - 1; i++)
            {
                if(nums[i] == nums[i + 1])
                {
                    if(!isXfound)
                    {
                        x = nums[i];
                        isXfound = true;
                        i++;
                    }
                    else{
                        y = nums[i];
                        isYfound = true;
                        break; 
                    }
                }
            }
            if(!isYfound)
            {
                Console.WriteLine(0);
                return;
            }
            else
            {
                Console.WriteLine(x * y);
                return;
            }
            
        }
    }
}