using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Atcoder
{
    class Atcoderrrrrrr
    {
        static void Main(string[] args)
        {
            string[] input = Console.ReadLine().Split(' ');

            int A = int.Parse(input[0]); int B = int.Parse(input[1]); int X = int.Parse(input[2]);

            if (A <= X)
            {
                if((A + B)>=X)
                {
                    Console.WriteLine("YES");
                }
                else
                {
                    Console.WriteLine("NO");
                }
            }
            else
            {
                Console.WriteLine("NO");
            }

        }
    }
}