using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AtCoder
{
    class Program
    {
        private const string V = "nO";

        static void Main(string[] args)
        {
            new Program().Solve();
        }

        void Solve()
        {
            var tmp = Console.ReadLine().Split();
            int a = int.Parse(tmp[0]);
            int b = int.Parse(tmp[1]);
            int c = int.Parse(tmp[2]);

            bool add = a + b == c;
            bool sub = a - b == c;

            string s = "!";
            if (add && sub)
            {
                s = "?";
            }
            else if (add)
            {
                s = "+";
            }
            else if (sub)
            {
                s = "-";
            }
            Console.WriteLine(s);


        }

    }
}