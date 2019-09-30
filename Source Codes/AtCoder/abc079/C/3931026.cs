using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ABC_C
{
    class C079
    {
        static void Main(string[] args)
        {
            string s = Console.ReadLine();
            int[] g = s.Select(x => x - '0').ToArray();


            for (int i = 0; i < 8; i++)
            {
                int[] h = (int[])g.Clone();
                int k = i;
                for (int j = 0; j < 3; j++)
                {
                    if (k % 2 == 1)
                    {
                        h[j + 1] *= -1;
                    }
                    k /= 2;

                }

                if (h.Sum() == 7)
                {

                    string r = g[0].ToString();
                    for(int j = 0; j < 3; j++)
                    {
                        if (h[j+1] >= 0) r += "+" + h[j+1];
                        else r += h[j+1];
                    }
                    r += "=7";
                    Console.WriteLine(r);
                    break;
                }
            }
        }

    }
}