using System;

namespace ABC076_B
{
    class Program
    {
        static void Main(string[] args)
        {
            var n = int.Parse(Console.ReadLine());
            var k = int.Parse(Console.ReadLine());
            var a = 1;
            for (int i = 0; i < n; i++)
                a = a + k < a * 2 ? a + k : a * 2;
            Console.WriteLine(a);
        }
    }
}