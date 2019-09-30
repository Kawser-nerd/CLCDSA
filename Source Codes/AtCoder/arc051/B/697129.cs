using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace b
{
    class Program
    {
        static void Main(string[] args)
        {
            int k = int.Parse(Console.ReadLine());
            int a = 1;
            int b = 2;
            for (int i = 0; i < k - 1; i++)
            {
                //Console.WriteLine(a + " " + b);

                if (a < b) a += b;
                else b += a;

            }
            if (a < b)
            {
                int tmp = a;
                a = b;
                b = tmp;
            }
            Console.WriteLine(a + " " + b);
            //counter = 0;
            //gcd(a, b);
            //Console.WriteLine(counter);
        }

        static int counter;
        static int gcd(int a, int b)
        {
            if (b == 0) return a;
            counter++;
            return gcd(b, a % b);
        }
    }
}