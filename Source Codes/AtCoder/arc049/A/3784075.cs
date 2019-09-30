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
            string S = Console.ReadLine();
            int[] inputs = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            int A = inputs[0]; int B = inputs[1]; int C = inputs[2]; int D = inputs[3];

            string ans = S.Insert(A, "\"");
            ans = ans.Insert(B+1, "\"");
            ans = ans.Insert(C+2, "\"");
            ans = ans.Insert(D+3, "\"");
            Console.WriteLine(ans);

        }
    }
}