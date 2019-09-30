using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication3
{
    class Program
    {
        static void Main(string[] args)
        {
            int T = int.Parse(Console.In.ReadLine());

            for (int p = 1; p <= T; p++)
            {
                int[] c = Console.In.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();

                for (int i = 2;; i++)
                {
                    if (c.All(x => isHappy(x, i)))
                    {
                        Console.WriteLine("Case #{0}: {1}", p,i);
                        break;
                    }
                }
            }
        }

        const int MAX = 10000000;
        static bool[,] happy = new bool[11, MAX];
        static bool[,] calc = new bool[11, MAX];


        public static bool isHappy(int b, int n)
        {
            if (n == 1)
                return true;
            //System.Diagnostics.Debug.WriteLine(string.Format("{0} {1}", b, n));
            if (n < MAX)
            {
                if (calc[b, n])
                    return happy[b, n];
                calc[b, n] = true;
            }

            int sum = 0;
            int m = n;
            do
            {
                int a = m % b;
                sum += a * a;
                m = m / b;
            } while (m > 0);
            
            bool result = isHappy(b, sum);
            if(n < MAX)
                happy[b, n] = result;
            return result;
        }
        
    }
}
