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
            int r = int.Parse(input[0]);int g = int.Parse(input[1]);int b = int.Parse(input[2]);
            int s = r*100 +g*10 + b;
            Console.WriteLine(s%4==0?"YES":"NO");
        }
    }
}