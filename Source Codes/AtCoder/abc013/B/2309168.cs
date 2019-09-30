using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            int a = int.Parse(Console.ReadLine());
            int b = int.Parse(Console.ReadLine());
            int tmp = 0;
            if(a < b)
            {
                tmp = a;
                a = b;
                b = tmp;
            }
            tmp = Math.Min(a - b, b - a + 10);
            Console.WriteLine(tmp);
        }
    }
}