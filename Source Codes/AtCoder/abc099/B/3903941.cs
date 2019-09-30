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
            int c = b - a;//b place

            //b high
            int bh = 0;
            for(int i = 1; i <= c; i++)
            {
                bh += i;
            }
            Console.WriteLine(bh - b);
        }
    }
}