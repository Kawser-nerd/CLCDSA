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
            int X = int.Parse(input[0]);int A = int.Parse(input[1]);int B = int.Parse(input[2]);

            if(A>=B){
            Console.WriteLine("delicious");
            }else{
                Console.WriteLine(Math.Abs(A-B)<=X? "safe":"dangerous" );
            }
        }
    }
}