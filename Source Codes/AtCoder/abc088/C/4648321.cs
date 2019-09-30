using System;
using System.Collections.Generic;
using System.Linq;

    class Program
    {
        static void Main(string[] args)
        {
            var C = new List<List<int>>();
            for(int i=0;i<3;i++)
                C.Add(Console.ReadLine().Split(' ').Select(s=>int.Parse(s)).ToList());

            if((C[0][0]- C[1][0]== C[0][1] - C[1][1]&& C[0][1] - C[1][1] == C[0][2] - C[1][2]) &&
               (C[0][0] - C[2][0] == C[0][1] - C[2][1] && C[0][1] - C[2][1] == C[0][2] - C[2][2])
                )
            {
                Console.WriteLine("Yes");
                return;
            }

            Console.WriteLine("No");
        }
    }