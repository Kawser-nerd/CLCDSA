using System;
using System.Linq;

namespace AtCoder
{
    class Program
    {
        static void Main()
        {
            string a = Console.ReadLine();
            string b = Console.ReadLine();
            Console.WriteLine(a == string.Join("", b.Reverse()) ? "YES" : "NO");
        }
    }
}