using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace arc_044_A
{
    class Program
    {
        static void Main(string[] args)
        {
            string gh = Console.ReadLine();
            int a = int.Parse(gh);
            if (IsPrime(a)) { Console.WriteLine("Prime"); }
           else  if (a % 2 != 0 && a % 5 != 0)
            {
                int kakuketa = 0;
                for (int i = 0; i < gh.Length; i++)
                {
                    kakuketa += int.Parse(gh.Substring(i, 1));
                }
                if (kakuketa % 3 == 0||a==1)
                {
                    Console.WriteLine("Not Prime");
                }
                else { Console.WriteLine("Prime"); }
            }
            else { Console.WriteLine("Not Prime"); }
            Console.ReadLine();
        }
        static bool IsPrime(int n)
        {
            if (n < 2) return false;
            if (n == 2) return true;

            for (int i = 2; i < n; i++)     // ?1
            {
                if (n % i == 0) return false;
            }
            return true;
        }
    }
}