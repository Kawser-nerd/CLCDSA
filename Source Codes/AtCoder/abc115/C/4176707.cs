using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] input = Console.ReadLine().Split(' ');
            int N = int.Parse(input[0]);
            int K = int.Parse(input[1]);

            int[] height = new int[N];
            for (int i = 0; i < N; i++)
            {
                height[i] = int.Parse(Console.ReadLine());
            }
            Array.Sort(height);

            int answer=0;

            for (int i = 0; i < N-K+1; i++)
            {
                int X = height[i + K - 1] - height[i];

                if (i == 0)
                {
                    answer = X;
                }
                else if (answer > X)
                {
                    answer = X;
                }
            }

            Console.WriteLine(answer);

        }
    }
}