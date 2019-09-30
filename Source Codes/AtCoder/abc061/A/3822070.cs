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
            int[] s = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            int A =s[0]; int B = s[1];int C = s[2];

            Console.WriteLine(C>=A && C<=B ? "Yes":"No");
            

        }
    }
}