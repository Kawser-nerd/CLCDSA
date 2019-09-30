using System;
        using System.Linq;

        public class Program
        {
            public static void Main(string[] args)
            {
            int[] input = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            int answer = 0;

            for(int i = input[0]; i <= input[1]; i++)
            {
                string stock ="";
                
                for(int j = i.ToString().Length - 1; 0 <= j; j--)
                {
                    stock += i.ToString().Substring(j, 1);
                }

                if(int.Parse(stock) == i)
                {
                    answer++;
                }
            }

            Console.WriteLine(answer);
            }
        }