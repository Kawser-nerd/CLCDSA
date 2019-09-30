using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ARC048Stairway
{
    class Program
    {
        static void Main(string[] args)
        {
            int A, B;
            string[] vals = Console.ReadLine().Split(' ');
            A = int.Parse(vals[0]);
            B = int.Parse(vals[1]);

            if(A < 0 && B > 0)
            {
                Console.WriteLine(B - A - 1);
            }
            else
            {
                Console.WriteLine(B - A);
            }
        }
    }
}