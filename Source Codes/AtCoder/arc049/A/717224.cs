using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication15
{
    class Program
    {
        static void Main(string[] args)
        {
            string S = Console.ReadLine();
            string[] input = Console.ReadLine().Split();
            int A = int.Parse(input[0]);
            int B = int.Parse(input[1]);
            int C = int.Parse(input[2]);
            int D = int.Parse(input[3]);
            S = S.Insert(A, "\"");
            S = S.Insert(B + 1, "\"");
            S = S.Insert(C + 2, "\"");
            S = S.Insert(D + 3, "\"");
            Console.WriteLine(S);
        }
    }
}