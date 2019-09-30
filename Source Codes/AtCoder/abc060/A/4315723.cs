using System;

namespace atcoderA
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            string[] input = Console.ReadLine().Split(' ');
            var A = input[0];
            var B = input[1];
            var C = input[2];
            Console.WriteLine(A[A.Length - 1] == B[0] && B[B.Length - 1] == C[0] ? "YES" : "NO");
        }
    }
}