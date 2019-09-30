using System;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            int a = int.Parse(Console.ReadLine());
            int b = int.Parse(Console.ReadLine());
            int n = int.Parse(Console.ReadLine());

            int GCD = GetGcd(a, b);
            int LCM = a * b / GCD;

            if (n%LCM==0)
            {
                Console.WriteLine(n);
            }
            else
            {
                Console.WriteLine(n + LCM-(n % LCM));
            }

        }

        public static int GetGcd(int a ,int b)
        {
            while (b!=0)
            {
                var r = a % b;
                a = b;
                b = r;
            }
            return a;
        }

    }
}