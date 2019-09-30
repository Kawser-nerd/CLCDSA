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
            int W = int.Parse(s[0]);
            int H = int.Parse(s[1]);

            Console.WriteLine(
                W%16 ==0 && H%9==0 ? "16:9": "4:3"

                );

        }
    }
}