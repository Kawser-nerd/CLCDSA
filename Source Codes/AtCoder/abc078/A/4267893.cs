using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace template
{
    class Program
    {
        static void Main(string[] args)
        {
            var imp = Console.ReadLine().Split(' ');
            char X = char.Parse(imp[0]);
            char Y = char.Parse(imp[1]);

            if (X < Y)
            {
                Console.Write("<");
            }
            if (X > Y)
            {
                Console.Write(">");
            }
            if (X == Y)
            {
                Console.Write("=");
            }
           
        }
    }
}