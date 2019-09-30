using System;
        using System.Linq;
        using System.Collections.Generic;
        using static System.Math;

        public class Program
        {
            public static void Main(string[] args)
            {
            int count = int.Parse(Console.ReadLine());
            int num = int.Parse(Console.ReadLine());
            int answer = 1;

            for (int i = 0; i < count; i++)
            {
                int a = answer * 2;
                int b = answer + num;
                answer = a < b ? a : b;
            }

            Console.WriteLine(answer);
            }
        }