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
            int a = int.Parse(s[0]);int b = int.Parse(s[1]);int c = int.Parse(s[2]);
            
            Console.WriteLine(b-a==c-b ? "YES":"NO");
        }
    }
}