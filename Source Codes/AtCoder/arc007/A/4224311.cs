using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp5
{
    class Program
    {
        static void Main(string[] args)
        {
            string b = Convert.ToChar(Console.Read()).ToString();
            Console.ReadLine();
            string a = Console.ReadLine();
            a = a.Replace(b, "");
            Console.WriteLine(a);
        }
    }
}