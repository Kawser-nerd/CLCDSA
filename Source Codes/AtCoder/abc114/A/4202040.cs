using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace A._753
{
    class Program
    {
        static void Main(string[] args)
        {
            int years = int.Parse(Console.ReadLine());

            switch (years)
            {
                case 7:
                case 5:
                case 3:
                    Console.WriteLine("YES");
                    break;
                default:
                    Console.WriteLine("NO");
                    break;
            }
        }
    }
}