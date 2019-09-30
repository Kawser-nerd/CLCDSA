using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _20180502_pra
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] a = Console.ReadLine().Split(' ');
            string b =  a[0]+a[1];

            int c = int.Parse(b) * 2;

            Console.WriteLine(c);

        }
    }
}