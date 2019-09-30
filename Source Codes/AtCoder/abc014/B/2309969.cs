using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] nx = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
            int[] price = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
            int sum = 0;
            for(int i = 0; i < nx[0]; i++)
            {
                if ((nx[1] >> i & 1) == 1) sum += price[i];
            }
            Console.WriteLine(sum);
        }
    }
}