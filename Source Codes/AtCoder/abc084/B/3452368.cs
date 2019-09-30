using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace test
{
    class Program
    {
        static void Main(string[] args)
        {
            var input = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
            var A = input[0];
            var B = input[1];
            var S = Console.ReadLine();
            var suc = true;

            if (S[A] != '-') suc = false;
            for (int i = 0; i < A; i++)
            {
                if (S[i] == '-') suc = false;
            }
            for (int i = A + 1; i < A + B; i++)
            {
                if (S[i] == '-') suc = false;
            }

            Console.WriteLine(suc ? "Yes" : "No");
        }
    }
}