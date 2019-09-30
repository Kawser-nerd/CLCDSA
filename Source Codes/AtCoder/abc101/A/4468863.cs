using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AtCoder
{
    class Program
    {
        static void Main()
        {
            string str = Console.ReadLine();

            int a = 0;

            for (int i = 0; i < 4; i++)
            {
                if (str[i] == '+') a++;
                else a--;
            }
            Console.Write(a);

            Console.ReadKey();
        }
    }

}