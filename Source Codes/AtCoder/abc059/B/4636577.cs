using System;
using System.Numerics;

    class Program
    {
        static void Main(string[] args)
        {
            var A = BigInteger.Parse(Console.ReadLine());
            var B = BigInteger.Parse(Console.ReadLine());
            if(A==B)
            {
                Console.WriteLine("EQUAL");
                return;
            }
                Console.WriteLine(A>B? "GREATER" : "LESS");
        }
    }