using System;

namespace ABC014A
{
    class Program
    {
        static void Main(string[] args)
        {
            var a = int.Parse(Console.ReadLine());
            var b = int.Parse(Console.ReadLine());

            if(a % b == 0)
            {
                Console.WriteLine(0);
            }
            else
            {
                Console.WriteLine(b - (a % b));
            }
        }
    }
}