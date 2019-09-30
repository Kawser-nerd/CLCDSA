using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace atcoder096_A
{
    class Program
    {
        static void Main(string[] args)
        {
            //???????
            string[] t_input = Console.ReadLine().Split();
            int a = int.Parse(t_input[0]);
            int b = int.Parse(t_input[1]);

            int result = a - 1 + (a <= b ? 1 : 0);

            Console.WriteLine(result);
        }
    }
}