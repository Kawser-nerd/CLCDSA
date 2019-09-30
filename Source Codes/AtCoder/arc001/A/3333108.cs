using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ARC001_A
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            string vc = Console.ReadLine();

            List<char> vcc = vc.ToList();

            int correctMax = vcc.GroupBy(c => c).Max(c => c.Count());

            int correctMin = 0;
            if (vcc.GroupBy(c => c).Count() == 4)
                correctMin = vcc.GroupBy(c => c).Min(c => c.Count());


            Console.WriteLine("{0} {1}", correctMax, correctMin);
            Console.ReadLine();
        }
    }
}