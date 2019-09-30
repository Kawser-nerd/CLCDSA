using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ARC021B
{
    class Program
    {
        static void Main(string[] args)
        {
            int L = int.Parse(Console.ReadLine());
            int[] B = new int[L + 1];

            for(int i=1; i <= L; i++)
            {
                B[i] = int.Parse(Console.ReadLine());
            }

            int xorB = B[1];
            for (int i = 2; i <= L; i++)
                xorB ^= B[i];
            
            if(xorB != 0)
            {
                Console.WriteLine(-1);
                return;
            }
            else
            {
                int A = 0;
                for(int i=1; i <= L; i++)
                {
                    Console.WriteLine(A);
                    A = A ^ B[i];
                }
            }

        }
    }
}