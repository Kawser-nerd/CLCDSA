using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Main
{
    class Program
    {
        static void Main(string[] arg)
        {

            //int[] line = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
            int d = int.Parse(Console.ReadLine());

            string ans_eve = string.Concat(Enumerable.Repeat(" Eve", 25 - d));
            Console.WriteLine("Christmas" + ans_eve);

            Console.ReadLine();

        }
    }
}