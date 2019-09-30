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
            int[] s = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            int k = int.Parse(Console.ReadLine());


            int sLarge = s.Max();
            Console.WriteLine(
                s.Max() * Math.Pow(2,k) + Math.Abs(s.Max() - s.Sum())
                );
        }
    }
}