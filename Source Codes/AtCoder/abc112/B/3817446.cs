using System;
        using System.Linq;
        using System.Collections.Generic;
        using static System.Math;

        public class Program
        {
            public static void Main(string[] args)
            {
            int[] n = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            int[] input = new int[] { };
            int cost = 0;

            for(int i = 0; i < n[0]; i++)
            {
                input = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
                if (cost == 0 && input[1] <= n[1]) cost = input[0];
                else
                {
                    if(input[0] < cost && input[1] <= n[1]) cost = input[0];
                }
            }

            Console.WriteLine(cost == 0 ? "TLE" : cost.ToString());
            }
        }