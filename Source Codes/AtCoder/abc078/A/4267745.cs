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
            var X = imp[0];
            var Y = imp[1];
            int x = 0;
            int y = 0;
            if ((X == "A"))
            {
               x = 10;
            }
            if ((X == "B"))
            {
                x = 11;
            }
            if ((X == "C"))
            {
               x = 12;
            }
            if ((X == "D"))
            {
                x = 13;
            }
            if ((X == "E"))
            {
                x = 14;
            }
            if ((X == "F"))
            {
                 x = 15;
            }


            if ((Y == "A"))
            {
                 y = 10;
            }
            if ((Y == "B"))
            {
                y = 11;
            }
            if ((Y == "C"))
            {
                 y = 12;
            }
            if ((Y == "D"))
            {
                 y = 13;
            }
            if ((Y == "E"))
            {
                y = 14;
            }
            if ((Y == "F"))
            {
              y = 15;
            }



            if (x < y)
            {
                Console.Write("<");

            }
            if (x > y)
            {
                Console.Write(">");
            }

            if (x == y)
            {
                Console.Write("=");
            }
        }
    }
}