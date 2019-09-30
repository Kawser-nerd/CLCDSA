using System;
using System.Collections.Generic;
using System.Linq;

    class Program
    {
        static void Main(string[] args)
        {
            var NK = Console.ReadLine().Split(' ').Select(s=> int.Parse(s)).ToArray();
            var N = NK[0];
            var K = NK[1];

            var inputs = new List<int>();
            for(var i = 0;i<N;i++)
            {
                inputs.Add(int.Parse(Console.ReadLine()));
            }
            inputs.Sort();
            var min = int.MaxValue;
            for(int i =0;i<=N-K;i++)
            {
                var tmp = inputs[i + K - 1] - inputs[i];
                if (tmp < min) min = tmp;
            }
            Console.WriteLine(min);
        }
    }