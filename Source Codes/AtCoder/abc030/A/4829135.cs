using System;
using System.Collections.Generic;

namespace Test
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            string s = Console.ReadLine();
            string[] ss = s.Split(' ');
            double a = 0;
            double b = 0;
            List<double> list = new List<double>();

            foreach (var item in ss)
            {
                list.Add(double.Parse(item));
            }
            a= list[0] / list[1];
            b = list[2] / list[3];

            if (a.Equals(b))
            {
                Console.WriteLine("DRAW");
            }else if (a>b)
            {
                Console.WriteLine("AOKI");
            }
            else
            {
                Console.WriteLine("TAKAHASHI");
            }
        }
    }
}