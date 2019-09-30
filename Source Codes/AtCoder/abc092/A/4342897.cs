using System;
using System.ComponentModel;

namespace AtCoder.ABC092
{
    public class A
    {
        public static void Solve()
        {
            int a = int.Parse(Console.ReadLine());
            int b = int.Parse(Console.ReadLine());
            int c = int.Parse(Console.ReadLine());
            int d = int.Parse(Console.ReadLine());

            var train = a;
            if (a >= b)
            {
                train = b;
            }
            var bus = c;
            if (c >= d)
            {
                bus = d;
            }

            var p = bus + train;
        
            Console.WriteLine(p);
        }    
    }
}

namespace AtCoder {
    class Program
    {
        static void Main(string[] args)
        {
            ABC092.A.Solve();
        }
    }
}