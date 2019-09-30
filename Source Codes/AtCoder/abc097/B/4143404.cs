using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Atcoder
{
    class Atcoderrrrrr
    {
        static void Main(string[] args)
        {
            int x = int.Parse(Console.ReadLine());
            double ans = 0;
            for (int b = 1; b <= x; b++)
            {
                for (int p = 2; p < 10; p++)
                {
                    double obj = Math.Pow(b, p);
                    if (ans<=obj && obj<=x)
                    {
                        ans = obj;
                    }
                }
            }
            Console.WriteLine(ans);
        }
    }
}