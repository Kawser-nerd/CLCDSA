using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace A.Programming_Education
{
    class Program
    {
        static void Main(string[] args)
        {
            int age = int.Parse(Console.ReadLine());

            switch (age)
            {
                case 1:
                    Console.WriteLine("Hello World");
                    break;
                case 2:
                    var a = int.Parse(Console.ReadLine());
                    var b = int.Parse(Console.ReadLine());

                    Console.WriteLine(a + b);
                    break;
                default:
                    break;
            }
        }
    }
}