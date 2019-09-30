using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ARC050_A
{
    class Program
    {
        static void Main(string[] args)
        {
            var t = Console.ReadLine().Split();
            if (t[0] == t[1].ToUpper()) Console.WriteLine("Yes");
            else
            {
                Console.WriteLine("No");
            }
        }
    }
}