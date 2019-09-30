using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace A.Garden
{
    class Program
    {
        static void Main(string[] args)
        {
            var A_B = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int A = A_B[0];
            int B = A_B[1];
            int ans = (A - 1) * (B - 1);

            Console.WriteLine(ans);
        }
    }
}