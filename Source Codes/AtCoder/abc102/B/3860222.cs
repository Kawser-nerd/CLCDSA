using System;
using System.Linq;
using System.Collections.Generic;

namespace _0030
{
    
    class Program
    {

        
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            string[] str = Console.ReadLine().Split(' ');

            long max = -1;
            long min = (long)Math.Pow(10, 9);

            int tmp = 0;

            for(int i = 0; i < n; i++)
            {
                tmp = int.Parse(str[i]);

                if(tmp > max)
                {
                    max = tmp;
                }
                if(tmp < min)
                {
                    min = tmp;
                }

            }

            Console.WriteLine(max - min);

        }
    }
}