using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ARC75_C
{
    class Program
    {
        static void Main(string[] args)
        {

            var n = int.Parse(Console.ReadLine());
            var s = new int[n];
            for (int i = 0; i < n; i++)
            {
                s[i] = int.Parse(Console.ReadLine());
            }
            Array.Sort(s);
            int sum = s.Sum();
            if (s.All(x=>x%10==0))
            {

                Console.WriteLine(0);
                return;
            }
            if (sum % 10 != 0)
            {
                Console.WriteLine(sum);
                return;
            }
            if (sum % 10 == 0)
            {
                for (int i = 0; i < n; i++)
                {
                    if (s[i] % 10 != 0)
                    {
                        sum -= s[i];
                        break;
                    }
                }
            }
            Console.WriteLine(sum);
        }
    }
}