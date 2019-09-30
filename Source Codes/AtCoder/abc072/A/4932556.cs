using System;
using System.Linq;

namespace A___Sandglass2
{
    class Program
    {
        static void Main(string[] args)
        {
            var X_t = Console.ReadLine().Split().Select(int.Parse).ToArray();
            var X = X_t[0];
            var t = X_t[1];

            Console.WriteLine(Math.Max(X - t, 0));
        }
    }
}