using System;
using System.Linq;

namespace practice6
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            int N = Int32.Parse(Console.ReadLine());
            int K = Int32.Parse(Console.ReadLine());
            int X = Int32.Parse(Console.ReadLine());
            int Y = Int32.Parse(Console.ReadLine());
            int x;
            if (N > K)x = K * X + (N - K) * Y;
            else
                x = N * X;
            Console.WriteLine(x.ToString());
        }
    }
}