using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            int n;
            double sum = 0;
            int[] a = new int[100];
            n = int.Parse(Console.ReadLine());
            a = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            for(int i = 0; i < n; i++)
            {
                sum += a[i];
            }
            sum /= n;
            long sum2 = 0, sum3 = 0;
            for(int i = 0; i < n; i++)
            {
                sum2 += (long)Math.Pow(a[i] - Math.Floor(sum), 2);
                sum3 += (long)Math.Pow(a[i] - Math.Ceiling(sum), 2);
            }
            if (sum3 < sum2) sum2 = sum3;
            Console.WriteLine(sum2);
        }
    }
}