using System;
using System.Linq;

namespace A.Add_Sub_Mul
{
    class Program
    {
        static void Main(string[] args)
        {
            var abcd = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int a = abcd[0];
            int b = abcd[1];
            int c = abcd[2];
            int d = abcd[3];

            bool flg1 = Math.Abs(a - c) <= d;
            bool flg2 = Math.Abs(a - b) <= d && Math.Abs(b - c) <= d;

            Console.WriteLine(flg1 || flg2 ? "Yes" : "No");

        }
    }
}