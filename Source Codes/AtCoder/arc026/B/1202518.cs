using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace arc_026_B
{
    class Program
    {
        static void Main(string[] args)
        {
            long n = long.Parse(Console.ReadLine());
            if (n == 1 ) { Console.WriteLine("Deficient"); }
            else
            {
                long ans = 0;
                for (long i = 1; i <= (long)Math.Sqrt(n); i++)
                {
                    if (n % i == 0) { ans += i + (n / i); }
                }
                if (Math.Sqrt(n) % 1 == 0) { ans -= (long)Math.Sqrt(n); }
                if (ans == 2 * n) { Console.WriteLine("Perfect"); }
                else if (ans > 2 * n) { Console.WriteLine("Abundant"); }
                else { Console.WriteLine("Deficient"); }
            }
            Console.ReadLine();
        }
    }
}