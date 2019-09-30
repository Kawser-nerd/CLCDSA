using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace B._1_Dimensional_World_s_Tale
{
    class Program
    {
        static void Main(string[] args)
        {
            var NMXY = Console.ReadLine().Split(null).Select(x => int.Parse(x)).ToList();
            var N = NMXY[0];
            var M = NMXY[1];
            var X = NMXY[2];
            var Y = NMXY[3];

            var Xn = Console.ReadLine().Split(null).Select(x => int.Parse(x)).ToList();
            var Yn = Console.ReadLine().Split(null).Select(x => int.Parse(x)).ToList();

            Xn.Add(X);
            Yn.Add(Y);

            if (Xn.Max() < Yn.Min())
                Console.WriteLine("No War");
            else
                Console.WriteLine("War");
        }
    }
}