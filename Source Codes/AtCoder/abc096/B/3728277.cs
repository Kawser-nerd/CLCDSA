using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace atcoder096_B
{
    class Program
    {
        static void Main(string[] args)
        {

            //???????
            string[] t_input = Console.ReadLine().Split();
            int[] input = t_input.Select(i => int.Parse(i)).ToArray();
            int K = int.Parse(Console.ReadLine());

            Array.Sort(input);
            int result = input[input.Length-1]*(int)Math.Pow(2, K);
            for (int i = 0;i < input.Length-1;i++)
            {
                result += input[i];
            }

            Console.WriteLine(result);

        }
    }
}