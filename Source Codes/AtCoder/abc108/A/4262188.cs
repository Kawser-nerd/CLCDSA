using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace A.Pair
{
    class Program
    {
        static void Main(string[] args)
        {
            var K = int.Parse(Console.ReadLine());
            int Odd = 0;
            int Even = 0;
            int ans = 0;

            for (int i = 1; i <= K; i++)
            {
                if (i % 2 == 1)
                    Odd++;
                else
                    Even++;
            }

            ans = Odd * Even;
            Console.WriteLine(ans);
        }
    }
}