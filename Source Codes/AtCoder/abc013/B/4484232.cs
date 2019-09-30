using System;

namespace ABC013B
{
    class Program
    {
        static void Main(string[] args)
        {
            var a = int.Parse(Console.ReadLine());
            var b = int.Parse(Console.ReadLine());
            int ab = Math.Abs(a - b);
            if(ab <= 5)
            {
                Console.WriteLine(ab);
            }
            else
            {
                Console.WriteLine(10 - ab);
            }
        }
    }
}