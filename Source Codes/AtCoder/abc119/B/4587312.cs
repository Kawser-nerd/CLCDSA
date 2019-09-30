using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AtCorderStudy
{
    class Program
    {
        static void Main(string[] args)
        {
            var BTCRate = 380000.0;
            var JPY = "JPY";
            var BTC = "BTC";
            var N = int.Parse(Console.ReadLine());
            var xs = new double[N];
            var us = new string[N];
            double sum = 0;
            for (int i = 0; i < N; i++)
            {
                var r = Console.ReadLine().Split(' ');
                var x = double.Parse(r[0]);
                var u = r[1];
                if(u==JPY)
                {
                    sum += x;
                }
                else if(u == BTC)
                {
                    sum += x * BTCRate;
                }
                //xs[i] = double.Parse(r[0]);
                //us[i] = r[1];
            }
            Console.WriteLine(sum);
        }
    }
}