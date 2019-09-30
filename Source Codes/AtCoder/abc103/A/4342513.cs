using System;
using System.Numerics;

namespace Atcoder.ABC103
{
    public class A
    {
        public static void Solve()
        {
            string[] input = Console.ReadLine().Split(' ');
            int a = int.Parse(input[0]);
            int b = int.Parse(input[1]);
            int c = int.Parse(input[2]);

            int max = 0;

            int x, y, z;
            x = Math.Abs(a - b);
            y = Math.Abs(b - c);
            z = Math.Abs(a - c);
//        
//            Console.WriteLine(x);
//            Console.WriteLine(y);
//            Console.WriteLine(z);
            max = Math.Max(x, y);
            max = Math.Max(max, z);
            Console.WriteLine(max);
        }    
    }
}

namespace Atcoder {
    class Program
    {
        static void Main(string[] args)
        {
            ABC103.A.Solve();
        }
    }
}