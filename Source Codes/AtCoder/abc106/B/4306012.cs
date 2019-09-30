using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace B._105
{
    class Program
    {
        static void Main(string[] args)
        {
            var num = int.Parse(Console.ReadLine());
            int div_cnt = 0;
            int ans = 0;

            for (int i = 1; i <= num; i++)
            {
                div_cnt = 0;

                for (int j = 1; j <= i; j++)
                    if ((i % 2 == 1) && (i % j == 0)) div_cnt++;

                if (div_cnt == 8) ans++;
            }
            Console.WriteLine(ans);
        }
    }
}