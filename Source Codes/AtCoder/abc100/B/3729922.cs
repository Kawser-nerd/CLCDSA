using System;
using System.Collections.Generic;
using System.Linq;

namespace AtCoderConsole
{
    class Program
    {
        static void Main(string[] args)
        {
            // ??????1???
            string input = Console.ReadLine();

            // D?N???
            int d = int.Parse(input.Split(' ')[0]);
            int n = int.Parse(input.Split(' ')[1]);

            // ???100??????
            int[] array = new int[100];

            // ???????
            for(int i = 0; i < 100; i++)
            {
                if (d == 0)
                {
                    array[i] = (i + 1);
                }
                else if (d == 1)
                {
                    array[i] = 100 * (i + 1);
                }
                else
                {
                    array[i] = 10000 * (i + 1);
                }
            }
            if (d == 0)
            {
                // 100?0???????1?????????100?????101
                array[99] = 101;
            }
            if (d == 1)
            {
                array[99] = 10100;
            }
            if(d == 2)
            {
                array[99] = 1010000;
            }

            // ???????
            Console.WriteLine(array[n - 1]);
        }
    }
}