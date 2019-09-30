using System;
using System.Collections.Generic;
using System.Linq;

namespace ABC120A
{
    class MainClass
    {

        static int[] s;
        static int[] n;

        public static void Main(string[] args)
        {

            s = Array.ConvertAll(Console.ReadLine().Split().ToArray(), int.Parse);
            Console.WriteLine(Math.Min(s[1] / s[0], s[2]));

        }
    }
}