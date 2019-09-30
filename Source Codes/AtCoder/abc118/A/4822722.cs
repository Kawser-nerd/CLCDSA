using System;

namespace Test
{
    class Program
    {
        static void Main(string[] args)
        {
            string s = Console.ReadLine();
            string[] x = s.Split(' ');
            int a, b;
            a = int.Parse(x[0]);
            b = int.Parse(x[1]);

            if(b%a == 0)
            {
                Console.WriteLine(a + b);
            }

            else
            {
                Console.WriteLine(b - a);
            }
        }
    }
}