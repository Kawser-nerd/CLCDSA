using System;
namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            var a = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
            Console.WriteLine((a[2] - a[1]) % 2 == 0 ? "Alice" : "Borys");
        }
    }
}