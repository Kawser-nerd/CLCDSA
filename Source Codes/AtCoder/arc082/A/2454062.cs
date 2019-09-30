using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ARC82_C
{
    class Program
    {
        static void Main(string[] args)
        {

            var n = int.Parse(Console.ReadLine());

            var a = Console.ReadLine().Split().Select(int.Parse).ToArray();
            var x = new Dictionary<int, int>();

            for (int i = 0; i < n; i++)
            {
                if (!x.ContainsKey(a[i])) x[a[i]] = 0;
                if (!x.ContainsKey(a[i] + 1)) x[a[i] + 1] = 0;
                if (!x.ContainsKey(a[i] - 1)) x[a[i] - 1] = 0;

                x[a[i]]++;
                x[a[i]-1]++;
                x[a[i]+1]++;

            }


            Console.WriteLine(x.Values.Max());
        }
    }
}