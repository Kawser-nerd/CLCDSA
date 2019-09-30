using System;
using System.Linq;

namespace practice6
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            int N = Int32.Parse(Console.ReadLine());
            int x = ((N + 1) * N) / 2;
            Console.WriteLine(x.ToString());
        }
    }
}