using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.AllSearch
{
    class AtTemplate
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            string input = Console.ReadLine();
            int[] numbers = new int[input.Length];
            for(int i = 0;i< input.Length; i++)
            {
                numbers[i] = input[i] - '0';
            }
            int n = (int)Math.Pow(2, input.Length - 1);
            long allSum = 0;
            for (int i = 0; i < n; i++)
            {
                long sum = numbers[input.Length - 1];//?????
                long rate = 10;//?????

                for (int j = 0; j < input.Length-1; j++)
                {
                    if ((1 & i >> j) == 1)//+??
                    {
                        sum += numbers[input.Length - 2 - j];
                        rate = 10;
                    }
                    else
                    {
                        sum += numbers[input.Length - 2 - j] * rate;
                        rate *= 10;
                    }
                }
                allSum += sum;
            }
            Console.WriteLine(allSum);
        }
    }
}