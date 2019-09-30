using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Mirrored
{
    class Program
    {
        static void Main(string[] args)
        {
            decimal ans = 0;
            decimal D = decimal.Parse(Console.ReadLine());
            if (D % 9 != 0)
            {
                Console.WriteLine(0);
                Console.ReadLine();
                return;
            }
            int ketaD = D.ToString().Length;
            D /= 9;

            for (int i = ketaD; i <= 2 * ketaD; i++)
            {
                ans += chkNumber(i, D);
            }

            Console.WriteLine(ans);
            Console.ReadLine();
        }

        static decimal chkNumber(int keta, decimal target)
        {
            decimal ans = 0;
            bool ret = false;
            List<decimal> insu = new List<decimal>();
            int n = keta / 2;
            bool arbitrary = keta % 2 == 0 ? false : true;

            for (int i = 0; i < n; i++)
            {
                insu.Add(((decimal)Math.Pow(10, keta - (i + 1)) - (decimal)Math.Pow(10, i)) / 9);
            }

            List<decimal> corr = new List<decimal>();

            for (int i = 0; i < insu.Count; i++)
            {
                corr.Add(target / (decimal)Math.Pow(10, i) % 10);
                target = target - corr[i] * insu[i];
                if (target == 0)
                {
                    ret = true;
                    //break;
                }
            }

            if (ret)
            {
                for (int i = 0; i < corr.Count; i++)
                {
                    if (i == 0) ans = 9 - corr[i];
                    else
                    {
                        ans *= 10 - (decimal)Math.Abs(corr[i]);
                    }
                }
                if (arbitrary) ans *= 10;
            }
            else ans = 0;
            return ans;
        }
    }
}