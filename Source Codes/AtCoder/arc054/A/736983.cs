using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace a
{
    class Program
    {
        static void Main(string[] args)
        {
            double[] lxysd = Console.ReadLine().Split().Select(double.Parse).ToArray();
            double l = lxysd[0];
            double x = lxysd[1];
            double y = lxysd[2];
            double s = lxysd[3];
            double d = lxysd[4];
            double jun, gyaku, ans;
            if (s < d)
            {
                jun = d - s;
                gyaku = l + s - d;
            }
            else
            {
                jun = l + d - s;
                gyaku = s - d;
            }
            if (y <= x) ans = jun / (x + y);
            else ans = Math.Min(jun / (x + y), gyaku / (y - x));
            

            Console.WriteLine(ans);
        }
    }
}