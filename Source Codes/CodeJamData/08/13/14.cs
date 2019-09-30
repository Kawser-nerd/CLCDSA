using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Question3
{
    class Program
    {
        static void Main(string[] args)
        {
        int[] NN = new int[] { 0,0, 027, 143, 751, 935, 607, 903, 991, 335, 047, 943, 471, 055, 447, 463, 991, 095, 607, 263, 151, 855, 527, 743, 351, 135, 407, 903, 791, 135, 647, 343, 471, 455, 847, 263, 191, 095 };
            int T = int.Parse(Console.ReadLine());

            List<int> N = new List<int>();

            for (int i = 0; i < T; i++)
            {
                N.Add(int.Parse(Console.ReadLine()));
            }

            int max = N.Max();

            Dictionary<int, int> D = new Dictionary<int, int>();

            decimal c = 3 + (decimal)Math.Sqrt(5);
            decimal d = c;
            for (int i = 2; i <= max; i++)
            {
                d *= c;
                if (N.Exists(n => n == i))
                {
                    decimal e = d % 1000;
                    D[i] = (int)e;
                }
            }

            for (int i = 0; i < T; i++)
            {
                Console.WriteLine("Case #{0}: {1:D3}", i + 1, NN[N[i]]);
            }
        }
    }
}
