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
            string[] s = Console.ReadLine().Split(' ');

            int A = int.Parse(s[0]);
            string op = s[1];
            int B = int.Parse(s[2]);

            if (op == "+")
            {
                Console.WriteLine(A+B);
            }
            else
            {
                Console.WriteLine(A - B);
            }
        }
    }
}