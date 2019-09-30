using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
 
namespace Atcoder
{
    class aaaa
    {
        static void Main(string[] args)
        {
            string[] input = Console.ReadLine().Split(' ');
            int N = int.Parse(input[0]);int A = int.Parse(input[1]);int B = int.Parse(input[2]);

            int planA = N * A;
            if (planA > B) {
                Console.WriteLine(B);
            }else{
                Console.WriteLine(planA);
            }

        }
    }
}