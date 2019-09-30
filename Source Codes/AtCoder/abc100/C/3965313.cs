using System;
        using System.Linq;
        using static System.Math;

        public class Program
        {
            public static void Main(string[] args)
            {
            int input = int.Parse(Console.ReadLine());
            int[] arr = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            int answer = 0;

            foreach(int i in arr.Where(x => x % 2 == 0))
            {
                int j = i;
                while(j % 2 < 1)
                {
                    j = j / 2;
                    answer++;
                }
            }

            Console.WriteLine(answer);
            }
        }