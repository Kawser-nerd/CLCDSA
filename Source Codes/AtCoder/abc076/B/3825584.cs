using System;

        public class Program
        {
            public static void Main(string[] args)
            {
            int count = int.Parse(Console.ReadLine());
            int num = int.Parse(Console.ReadLine());
            int answer = 1;

            for (int i = 0; i < count; i++)
            {
                answer = Math.Min(answer * 2, answer + num);
            }

            Console.WriteLine(answer);
            }
        }