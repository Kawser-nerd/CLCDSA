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
            int N = int.Parse(Console.ReadLine());

            int[] As = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();

            Console.WriteLine(Math.Abs(As.Max() - As.Min()));
        }
    }
}