using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _014
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] input = Console.ReadLine().Split(' ');
            int n = int.Parse(input[0]);
            int k = int.Parse(input[1]);
            string[] strA = Console.ReadLine().Split(' ');
            long[] a = new long[n];

            for(int i = 0;i < n; i++)
            {
                a[i] = a[i] + int.Parse(strA[i]);
                if (i + k < n)
                {
                    a[i + k] = a[i + k] + (-1 * int.Parse(strA[i]));
                }
            }
            
            //??????
            for (int j = 1; j < n; j++)
            {
                a[j] = a[j] + a[j - 1];
            }

            long sum = a
                .Select((x, i) => new { item = x, index = i })
                .Where(c => c.index >= k - 1)
                .Select(c => c.item)
                .Sum();
                

            Console.WriteLine(sum);
            Console.ReadLine();
        }
    }
}