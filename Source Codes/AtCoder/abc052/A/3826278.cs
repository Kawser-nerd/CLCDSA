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
            string[]s = Console.ReadLine().Split(' ');
            int a = int.Parse(s[0]);int b = int.Parse(s[1]);int c = int.Parse(s[2]);int d = int.Parse(s[3]);
        
            Console.WriteLine(
                a*b>=c*d? a*b:c*d
            );
        }
    }
}