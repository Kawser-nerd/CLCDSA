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
            int []a = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            long ans = ((a[0] - 2) * (a[1] - 2)) * 4;
            ans += (((a[0] + a[1]) * 2) - 8) * 3;
            ans += (4 * 2);
            ans /= 2;
            Console.WriteLine(ans);
        }
    }
}