using System;
using System.Collections.Generic;
using System.Linq;

namespace _004B
{
    class Program
    {
        static void Main(string[] args)
        {
            int num = int.Parse(Console.ReadLine());
            List<int> points = new List<int>();
            for (int i = 0; i < num; i++)
            {
                points.Add(int.Parse(Console.ReadLine()));
            }
            int sum = points.Sum();
            int max = points.Max();
            Console.WriteLine(sum);
           int a=2*max-sum;
            if (a < 0) Console.WriteLine("0");
            else Console.WriteLine(a) ;
        }
    }
}