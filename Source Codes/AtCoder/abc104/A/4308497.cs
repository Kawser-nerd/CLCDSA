using System;

namespace A.Rated_for_Me
{
    class Program
    {
        static void Main(string[] args)
        {
            var R = int.Parse(Console.ReadLine());

            if (R >= 2800)
            {
                Console.WriteLine("AGC");
            }
            else if (R>= 1200)
            {
                Console.WriteLine("ARC");
            }else
            {
                Console.WriteLine("ABC");
            }
        }
    }
}