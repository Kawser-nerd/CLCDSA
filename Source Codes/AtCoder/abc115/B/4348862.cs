using System;
using System.Linq;

namespace AtCoder.ABC115
{
    public class B
    {
        public static void Solve()
        {
            int N = int.Parse(Console.ReadLine());
            var a = new int[N];
            for (int i = 0; i < N; i++)
            {
                a[i] = int.Parse(Console.ReadLine());
            }

            Console.WriteLine(a.Max() / 2 + (a.Sum() - a.Max()));
        }    
    }
}

namespace AtCoder {
    class Program
    {
        static void Main(string[] args)
        {
            ABC115.B.Solve();
        }
    }
}