using System;
using System.Collections.Generic;
using System.Linq;
    class Program
    {
        static void Main(string[] args)
        {
            var NM = Console.ReadLine().Split(' ').Select(s=>int.Parse(s)).ToList();
            var inputs = new List<string>();
            for (var i = 0; i < NM[1]; i++)
            {
                inputs.AddRange(Console.ReadLine().Split(' '));
            }
            for (var i = 1; i <= NM[0]; i++)
            {
                Console.WriteLine(inputs.Count(s => s == i.ToString()));
            }
        }
    }