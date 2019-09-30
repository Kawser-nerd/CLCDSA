using System;
using System.Collections.Generic;
using System.Linq;
    class Program
    {
        static void Main(string[] args)
        {
            var HW = Console.ReadLine().Split(' ').Select(s=>int.Parse(s)).ToArray();
            var H = HW[0];

            var array = new List<string>();

            for (var i=0;i<H;i++)
            {
                array.Add(Console.ReadLine());
            }

            foreach(var item in array)
            {
                Console.WriteLine(item);
                Console.WriteLine(item);
            }

        }
    }