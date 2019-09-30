using System;
using System.Collections.Generic;

namespace CompetitiveProgramming
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] abc = Console.ReadLine().Split();
            int[] list = {0,0,0};
            int max = 0;
            int max_index = 0;

            for (var i = 0; i < abc.Length; i++)
            {
                list[i] = int.Parse(abc[i]);
            }
            for (var i = 0; i < list.Length;i++)
            {
                if(list[i]>max)
                {
                    max = list[i];
                    max_index = i;
                }
            }
            list[max_index] = list[0];
            list[0] = max;
            Console.WriteLine(list[0] * 10 + list[1] + list[2]);
        }
    }
}