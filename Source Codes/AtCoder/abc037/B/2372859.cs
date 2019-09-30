using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AtCoder
{
    class Program
    {
        public static void Main()
        {
            new Program().Solve();
        }

        void Solve()
        {
            var tmp = Console.ReadLine().Split().Select(x => int.Parse(x)).ToArray();
            int n = tmp[0];
            int q = tmp[1];
            var array = new int[n];
            for (int i = 0; i < q; i++)
            {
                tmp = Console.ReadLine().Split().Select(x => int.Parse(x)).ToArray();
                for (int j = tmp[0] - 1; j < tmp[1]; j++)
                {
                    array[j] = tmp[2];
                }
            }

            for (int i = 0; i < n; i++)
            {
                Console.WriteLine(array[i]);
            }
        }
    }
}