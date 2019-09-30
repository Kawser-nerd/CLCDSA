using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace ConsoleApp7
{
    class Program
    {
        static void Main(string[] args)
        {

            int a = int.Parse(Console.ReadLine());
            int b = int.Parse(Console.ReadLine());
            double h = int.Parse(Console.ReadLine());

            double S =AreaDaikei(a, b, h);

            Console.WriteLine(S);

        }

        public static double AreaDaikei(int a, int b, double h)
        {
            return (a + b) * h / 2;
        }
    }
}