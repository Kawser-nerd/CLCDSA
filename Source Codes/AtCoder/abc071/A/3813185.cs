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
            int x = int.Parse(input[0]);int a = int.Parse(input[1]);int b = int.Parse(input[2]);

            if (Math.Abs(x - a) > Math.Abs(x - b)){
                Console.WriteLine("B");
            }else{
                Console.WriteLine("A");
            }

        }
    }
}