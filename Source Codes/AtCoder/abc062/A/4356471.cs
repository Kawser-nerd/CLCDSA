using System;
using System.Collections.Generic;

namespace atcoderA
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            int[] input = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
            int x = input[0];
            int y = input[1];

            var list1 = new List<int> { 1, 3, 5, 7, 8, 10, 12 };
            var list2 = new List<int> { 4, 6, 9, 11 };
            var list3 = new List<int> { 2 };

            if (list1.Contains(x) && list1.Contains(y))
            {
                Console.WriteLine("Yes");
            }
            else if(list2.Contains(x) && list2.Contains(y))
            {
                Console.WriteLine("Yes");
            }
            else if (list3.Contains(x) && list3.Contains(y))
            {
                Console.WriteLine("Yes");
            }
            else
            {
                Console.WriteLine("No");
            }
        }
    }
}