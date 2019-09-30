using System;
using System.Collections.Generic;
using System.Linq;
    class Program
    {
        static void Main(string[] args)
        {
            var N = int.Parse(Console.ReadLine().Split(' ')[0]);
            var inputSs = new List<string>();

            for(int i = 0;i<N;i++)
            {
                inputSs.Add(Console.ReadLine());
            }

            var ans = string.Join("", inputSs.OrderBy(s => s));
            Console.WriteLine(ans);
        }
    }