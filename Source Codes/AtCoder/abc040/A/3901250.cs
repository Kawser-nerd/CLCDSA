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
            string[] s =Console.ReadLine().Split(' ');
            int n = int.Parse(s[0]);int x = int.Parse(s[1]);
            
            Console.WriteLine(
                x>n/2 ? n-x:x-1
            );
        
        }
    }
}