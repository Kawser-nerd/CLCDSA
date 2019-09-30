using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
 
namespace arc_034_B
{
    class Program
    {
        static void Main(string[] args)
        {
            long n = long.Parse(Console.ReadLine());
            long ans = 0;
            List<string> a = new List<string> { };
            long d1 = n - 158;
            if (d1 < 0) { d1 = 0; }
            for (long i = d1; i < n; i++)
            {
                string d = "" + i + "";
                long keta = 0;
                for (long k = 0; k < d.Length; k++)
                {
                    keta += long.Parse(d.Substring((int)k, 1));
                }
                if (keta + i == n)
                {
                    a.Add(d);
                    ans++;
                }
            }
            Console.WriteLine(ans);
            if (ans > 0)
            {
                for (long i = 0; i < a.Count; i++)
                {
                    Console.WriteLine(a[(int)i]);
                }
                Console.ReadLine();
            }
        }
    }
}