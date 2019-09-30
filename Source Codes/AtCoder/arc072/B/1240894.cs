using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AtCoderRegular
{
    class Program
    {
        static void Main(string[] args)
        {
            var input = Console.ReadLine().Split(' ');

            Console.WriteLine(Math.Abs(long.Parse(input[0])-long.Parse(input[1])) > 1 ? "Alice" : "Brown");
        }
                
    }
}