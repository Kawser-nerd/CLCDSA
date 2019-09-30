using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace A
{
    class Program
    {
        static void Main(string[] args)
        {
            var buff = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            var H = buff[0];
            var W = buff[1];
            Console.WriteLine((H - 1) * W + (W - 1) * H);
        }
    }
}