using System;
using System.Collections.Generic;

namespace atcoderA
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            var A = Console.ReadLine();
            var B = Console.ReadLine();

            if (A.Length > B.Length)
            {
                Console.WriteLine(A);
            }
            else if (B.Length > A.Length)
            {
                Console.WriteLine(B);
            }
        }
    }
}