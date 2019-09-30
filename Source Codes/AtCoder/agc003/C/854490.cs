using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AGC003_C
{ 
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            var a = new int[n];
            var sort = new int[n];
            int count = 0;
            for (int i = 0; i < n; i++)
            {
                int t = int.Parse(Console.ReadLine());
                a[i] = t;
                sort[i] = t;
            }
            Array.Sort(sort);
            for (int i = 0; i < n; i+=2)
            {
                if (Array.BinarySearch(sort, a[i]) % 2 == 1) count++;
            }
            Console.WriteLine(count);
        }
    }
}