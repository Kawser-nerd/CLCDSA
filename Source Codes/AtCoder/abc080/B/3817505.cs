using System;
        using System.Linq;
        using System.Collections.Generic;
        using static System.Math;

        public class Program
        {
            public static void Main(string[] args)
            {
            string input = Console.ReadLine();
            int sum = 0;

            foreach (char a in input)
            {
                sum += int.Parse(a.ToString());
            }

            Console.WriteLine(int.Parse(input) % sum == 0? "Yes":"No");
            }
        }