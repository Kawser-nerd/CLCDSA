using System;

namespace BC006_B
{

    class Program
    {
        static int Tribo(int n)
        {
            int a = 0, b = 0, c = 1;
            if (n == 1) return a;
            else if (n == 2) return b;
            else if (n == 3) return c;

            int x = 0;
            for (int i = 3; i < n; i++)
            {
                x = a + b + c;
                x %= 10007;
                a = b;
                b = c;
                c = x;
            }
            return x;
        }

        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            Console.WriteLine(Tribo(n) % 10007);
        }
    }

}