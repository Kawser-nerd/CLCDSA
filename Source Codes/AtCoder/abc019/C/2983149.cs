using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;

namespace AtTest.C_Challenge
{
    class ABC_019
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            string[] input = Console.ReadLine().Split(' ');
            var array = new int[n];
            for (int i = 0; i < n; i++)
            {
                array[i] = int.Parse(input[i]);
            }

            for(int i = 0; i < n; i++)
            {
                while (array[i] % 2 == 0)
                {
                    array[i] /= 2;
                }
            }

            Array.Sort(array);
            int cnt = 1;
            int nowVal = array[0];
            for(int i = 1; i < n; i++)
            {
                if (array[i] == nowVal) continue;

                nowVal = array[i];
                cnt++;
            }

            Console.WriteLine(cnt);
        }
    }
}