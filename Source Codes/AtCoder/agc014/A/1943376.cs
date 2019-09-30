using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        int[] ABC = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int res = 0;
        if (ABC.Max() == ABC.Min() && ABC.Max() % 2 == 0)
        {
            Console.WriteLine(-1);
            return;
        }
        int halfa;
        int halfb;
        int halfc;
        while (true)
        {
            if (res < 0)
            {
                Console.WriteLine(-1);
                return;
            }
            if (ABC[0] % 2 == 0 && ABC[1] % 2 == 0 && ABC[2] % 2 == 0)
            {
                halfa = ABC[0] / 2;
                halfb = ABC[1] / 2;
                halfc = ABC[2] / 2;
                ABC[0] = halfb + halfc;
                ABC[1] = halfc + halfa;
                ABC[2] = halfa + halfb;
                res++;
            }
            else
            {
                Console.WriteLine(res);
                return;
            }
        }
    }
}