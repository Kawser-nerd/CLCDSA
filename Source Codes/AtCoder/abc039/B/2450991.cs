using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    class Class1
    {
        static void Main()
        {
            int n = int.Parse(System.Console.ReadLine());
            int i = 1;
            while (i * i * i * i < n)
            {
                i++;
            }
            System.Console.WriteLine(i);
        }
    }
}