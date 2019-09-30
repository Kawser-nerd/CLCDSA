using System;
using System.Collections.Generic;
using System.Text;

namespace t33
{
    class Program
    {

        static double pow(int index)
        {
            if (index == 0) return 1;
            if (index == 1) return 3 + Math.Sqrt(5.0);
            else
            {
                double p = pow(index / 2);
                p *= p;
                if ( index % 2==1)
                    p *= 3 + Math.Sqrt(5.0);
                int pi = (int)p / 10000;
                p -= pi * 10000;
                return p;
            }
        }

        static void Main(string[] args)
        {
            //double p = 234224242.234824924;
            //Console.WriteLine(p % 10000);
            int T;
            T = int.Parse(Console.ReadLine());

            for (int c = 1; c <= T; c++)
            {
                int n = int.Parse(Console.ReadLine());


                //double x = pow(n);
                
                decimal x = 1;
                decimal a = (decimal)(3 + Math.Sqrt(5.0));
                a = 5.2360679774997896964091736687313m;
                //Console.WriteLine(a);
                for (int i = 1; i <= n; i++) x = x * a;

           //   Console.WriteLine(x);
                string xs = string.Format("{0:g}", x);
           //     Console.WriteLine(xs);
                string ans = xs.Substring(0,xs.IndexOf('.'));
                while (ans.Length > 3) ans = ans.Substring(1);
                while (ans.Length < 3) ans = "0" + ans;
               Console.WriteLine("Case #{0}: {1}", c, ans);
           //    Console.WriteLine("{0:f}",Math.Pow(3 + Math.Sqrt(5.0), n));

            }

        }
    }
}
