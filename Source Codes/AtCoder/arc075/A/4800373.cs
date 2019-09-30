using System;
using System.Collections.Generic;
using System.Linq;

    class Program
    {
        static void Main(string[] args)
        {
            var N = int.Parse(Console.ReadLine());
            var input = new List<int>();
            for(var i = 0;i<N;i++)
            {
                input.Add(int.Parse(Console.ReadLine()));
            }
            var sum = input.Sum();
            if(sum%10!=0)
            {
                Console.WriteLine(sum);
                return;
            }
            var noZero = input.Where(x => x % 10 != 0).ToList();
            if(!noZero.Any())
            {
                Console.WriteLine(0);
                return;
            }
            Console.WriteLine(sum-noZero.Min());
        }
    }