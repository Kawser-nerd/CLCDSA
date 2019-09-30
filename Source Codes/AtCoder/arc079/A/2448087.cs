using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ARC79_C
{
    class Program
    {
        static void Main(string[] args)
        {
            var s = Console.ReadLine().Split();
            int n = int.Parse(s[0]);
            int m = int.Parse(s[1]);
            var a = new int[m][];
            var c = new Dictionary<int, bool>();
            var d = new Dictionary<int, bool>();

            for (int i = 0; i < n; i++)
            {
                c[i] = false;
                d[i] = false;
            }

            for (int i = 0; i < m; i++)
            {

                a[i] = Console.ReadLine().Split().Select(int.Parse).ToArray();
                if (a[i][0] == 1) c[a[i][1]] = true;
                if (a[i][1] == n) d[a[i][0]] = true;
            }
            for (int i = 0; i < n; i++)
            {
                if (c[i] && d[i])
                {
                    Console.WriteLine("POSSIBLE");
                    return;
                }
            }
            Console.WriteLine("IMPOSSIBLE");
            
        }
    }
}