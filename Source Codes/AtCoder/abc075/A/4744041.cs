using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ABC
{
    class Program
    {
        static void Main(string[] args)
        {
            ABC075_A();
        }

        static void ABC075_A()
        {
            var ABC = Console.ReadLine().Split(' ').ToArray();
            var A = ABC[0];
            var B = ABC[1];
            var C = ABC[2];

            if (A == B && A != C)
                Console.WriteLine(C);

            if (A == C && A != B)
                Console.WriteLine(B);

            if (B == C && B != A)
                Console.WriteLine(A);
        }
    }
}