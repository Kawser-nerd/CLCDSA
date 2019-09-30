using System;

namespace ABC015A
{
    class Program
    {
        static void Main(string[] args)
        {
            var A = Console.ReadLine();
            var B = Console.ReadLine();

            if(A.Length > B.Length)
            {
                Console.WriteLine(A);
            }else
            {
                Console.WriteLine(B);
            }
        }
    }
}