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
            string a = "1";
            int n = int.Parse(Console.ReadLine());
            for (int i = 0; i < n - 1; i++)
                a += '0';
            a += '7';
            Console.WriteLine(a);
        }
    }
}