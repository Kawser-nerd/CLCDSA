using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Atcoder
{
    class Atcoderrrrrr
    {
        static void Main(string[] args)
        {
            string[] s = Console.ReadLine().Split(' ');
            int a = int.Parse(s[0]);
            int b = int.Parse(s[1]);
            int c = int.Parse(s[2]);
            
            if(a == b&&a == c)
            {
                Console.WriteLine(1);
            }else if(a == b && b != c || b == c && a != b || a == c && b != c)
            {
                Console.WriteLine(2);
            }
            else
            {
                Console.WriteLine(3);
            }
        }
    }
}