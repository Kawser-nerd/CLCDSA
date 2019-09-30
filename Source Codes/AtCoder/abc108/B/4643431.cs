using System;
using System.Collections.Generic;
using System.Linq;

namespace CompetitiveProgramming
{
    class Program
    {
        static void Main(string[] args)
        {
            MainStream();
        }

        static void MainStream()
        {
            //??????????
            string[] x1_y1_x2_y2 = Console.ReadLine().Split(' ');
            int x1 = int.Parse(x1_y1_x2_y2[0]);
            int y1 = int.Parse(x1_y1_x2_y2[1]);
            int x2 = int.Parse(x1_y1_x2_y2[2]);
            int y2 = int.Parse(x1_y1_x2_y2[3]);

            int x_distance = x1 - x2;
            int y_distance = y1 - y2;

            int x3 = x2 + y_distance;
            int y3 = y2 - x_distance;
            int x4 = x1 + y_distance;
            int y4 = y1 - x_distance;

            Console.WriteLine($"{x3} {y3} {x4} {y4}");
        }



    }
}