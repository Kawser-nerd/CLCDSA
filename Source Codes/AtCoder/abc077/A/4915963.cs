using System;
using System.Linq;

namespace A___Rotation
{
    class Program
    {
        static void Main(string[] args)
        {
            var C1 = Console.ReadLine();
            var C2 = Console.ReadLine();

            Console.WriteLine(string.Compare(C1, string.Join("", C2.Reverse())) == 0 ? "YES" : "NO");
        }
    }
}