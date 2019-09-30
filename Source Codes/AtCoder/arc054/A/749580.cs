using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace A
{
    class Program
    {
        static void Main(string[] args)
        {
            var buff = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            double L = buff[0], X = buff[1], Y = buff[2], S = buff[3], D = buff[4];

            var rD = D - S >= 0 ? D - S : D + L - S;
            var lD = S - D >= 0 ? S - D : S + L - D;

            var rT = rD / (X + Y);
            var lT = Y - X > 0 ? lD / (Y - X) : rT;
            Console.WriteLine(rT < lT ? rT : lT);
        }
    }
}