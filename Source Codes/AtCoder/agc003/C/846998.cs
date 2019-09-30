using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace c
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int[] a = new int[n];
            for (int i = 0; i < n; i++)
            {
                a[i] = int.Parse(Console.ReadLine());
            }
            

            var indexFromValueTable = a.Distinct()
                .OrderBy(v => v)
                .Select((value, index) => new { value, index })
                .ToDictionary(p => p.value, p => p.index);

            a = a.Select(v => indexFromValueTable[v]).ToArray();

            int ans = 0;

            for (int i = 0; i < n; i++)
            {
                if (i % 2 != a[i] % 2) ans++;
            }
            Console.WriteLine(ans/2);
        }
    }
}