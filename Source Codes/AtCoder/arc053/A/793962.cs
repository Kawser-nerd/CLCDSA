using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace a
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] hw = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int h = hw[0];
            int w = hw[1];
            Console.WriteLine((h - 1) * w + h * (w - 1));
        }
    }
}