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
            int answer = int.Parse(Console.ReadLine());
            int count = 0;
            while(answer > count)
            {
                count += 111;
            }

            Console.WriteLine(count);
            Console.ReadLine();

        }
    }
}