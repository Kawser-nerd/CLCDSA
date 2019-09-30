using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace B
{
    class Program
    {
        static void Main(string[] args)
        {
            var input = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
            var a = input[0];
            var b = input[1];
            var c = input[2];

            var buff = 0;
            var flag = false;


            for (int i = 0; i < b+1; i++)
            {
                buff += a;

                if (buff % b == c)
                {
                    flag = true;
                    break;
                }
            }

            if (flag)
            {
                Console.WriteLine("YES");
            }
            else
            {
                Console.WriteLine("NO");
            }
        }
    }
}