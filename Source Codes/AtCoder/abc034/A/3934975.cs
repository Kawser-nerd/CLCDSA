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
            int x = int.Parse(s[0]);
            int y = int.Parse(s[1]);

            Console.WriteLine(
                x>y ? "Worse" : "Better"

                );

        }
    }
}