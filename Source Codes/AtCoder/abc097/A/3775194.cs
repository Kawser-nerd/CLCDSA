using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace atcoder097_A
{
    class Program
    {
        static void Main(string[] args)
        {
            //???????
            int[] t_input = Console.ReadLine().Split().Select(i => int.Parse(i)).ToArray();
            int a = t_input[0];
            int b = t_input[1];
            int c = t_input[2];
            int d = t_input[3];
            string result = "No";

            if ((Math.Abs(a - b) <= d) && (Math.Abs(b - c) <= d)) result = "Yes";
            if (Math.Abs(a - c) <= d) result = "Yes";

            Console.WriteLine(result);
            
        }
    }
}