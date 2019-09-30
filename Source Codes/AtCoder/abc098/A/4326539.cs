using System;
using System.Linq;

namespace A.Add_Sub_Mul
{
    class Program
    {
        static void Main(string[] args)
        {
            var AB = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int A = AB[0];
            int B = AB[1];

            Console.WriteLine(Math.Max(A + B, Math.Max(A - B, A * B)));
        }
    }
}