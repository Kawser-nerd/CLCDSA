using System;
using System.Collections.Generic;
using System.Linq;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            //[summary]B - ????????
            int n = int.Parse(Console.ReadLine());

            var numbers = new int[n];

            for(int i = 0; i < n; i++)
            {
                switch (i)
                {
                    case 0:
                    case 1:
                        numbers[i] = 0;
                        break;
                    case 2:
                        numbers[i] = 1;
                        break;
                    default:
                        int sum = 0;

                        for(int j = i - 3; j < i; j++)
                        {
                            sum += numbers[j];
                        }

                        numbers[i] = sum % 10007;
                        break;                    
                }
            }

            Console.WriteLine(numbers[n - 1]);
        }
    }
}