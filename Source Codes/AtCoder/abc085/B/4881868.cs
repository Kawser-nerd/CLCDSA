using System;
using System.Collections.Generic;
using System.Linq;
class Program
    {
        static void Main(string[] args)
        {
            var N = int.Parse(Console.ReadLine());
            var inputs = new List<string>();
            for(var i = 0;i<N;i++)
            {
                inputs.Add(Console.ReadLine());
            }
            Console.WriteLine(inputs.Distinct().Count());
        }
    }