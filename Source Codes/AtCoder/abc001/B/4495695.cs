using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _20190307
{
    class Program
    {
        static void Main(string[] args)
        {
            double dis = double.Parse(Console.ReadLine()) / 1000;
            if (0.1 <= dis && dis <= 5) { Console.WriteLine("{0:00}", dis * 10); }
            else if (6 <= dis && dis <= 30) { Console.WriteLine("{0:00}", dis + 50); }
            else if (35 <= dis && dis <= 70) { Console.WriteLine("{0:00}", (dis - 30) / 5 + 80); }
            else if (dis > 70) { Console.WriteLine("89"); }
            else Console.WriteLine("00");
        }
    }
}