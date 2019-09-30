using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _20180827
{
    class Program
    {
        public static void Main(string[] args)
        {
            long num = int.Parse(Console.ReadLine());

            Console.WriteLine("{0}", num % 2 == 0 ? num - 1 : num + 1);

        }
    }
}