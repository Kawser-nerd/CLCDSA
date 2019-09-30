using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace test
{
    class Program
    {
        static void Main(string[] args)
        {
            var n = int.Parse(Console.ReadLine());
            var pri = PrimeList(55555);
            var ans = pri.Where(i => i % 5 == 1).Take(n).ToArray();
            Console.WriteLine(string.Join(" ", ans));
        }

        public static List<int> PrimeList(int p)
        {
            var pri = new List<int>();
            pri.Add(2);

            for(var i = 3; i <= p; i += 2)
            {
                var prime = true;
                
                for(var j = 3; j <= Math.Sqrt(i); j += 2)
                {
                    if (i % j == 0)
                    {
                        prime = false;
                        break;
                    }
                }
                if (prime) pri.Add(i);
            }

            return pri;
        }
    }
}