using System;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            String input = Console.ReadLine();
            String[] nums = input.Split(' ');
            int[] a = new int[4];
            for (int i=0; i < 4; i++)
            {
                a[i] = int.Parse(nums[i]);
            }

            int rect1 = a[0] * a[1];
            int rect2 = a[2] * a[3];

            if (rect1 > rect2) {
                Console.WriteLine(rect1);
            }
            else
            {
                Console.WriteLine(rect2);
            }
        }
    }
}