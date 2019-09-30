using System;
using System.Collections.Generic;
using System.Linq;

namespace WA048B
{
    class Program
    {
        static void Main(string[] args)
        {
            var N = int.Parse(Console.ReadLine());
            var line = Console.ReadLine();
            var a = line.Split(' ').Select(s => int.Parse(s)).ToArray();

            var list = new List<int>();

            list.AddRange(a);

            list.Sort((b, c) => c - b);

            var A = 0; var B = 0;
            for(var i = 0; i < N; i++)
            {
                if(i % 2 == 0)
                {
                    A += list[i];
                }
                else
                {
                    B += list[i];
                }
            }
            Console.WriteLine($"{A - B}");
        }
    }
}