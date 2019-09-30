using System;
using System.Collections.Generic;

namespace CompetitiveProgramming
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            string[] t_a = Console.ReadLine().Split(' ');
            string[] h_list = Console.ReadLine().Split(' ');
            int t = int.Parse(t_a[0]);
            int a = int.Parse(t_a[1]);
            double diff_min = 0;
            int ans_index = 0;

            for (var i = 0; i < n;i++)
            {
                double i_temp = t - int.Parse(h_list[i])*0.006;
                double diff = Math.Abs(a - i_temp);

                if ( i == 0 || diff < diff_min) 
                {
                    diff_min = diff;
                    ans_index = i;
                }
            }

            Console.WriteLine(ans_index + 1);


        }
    }
}