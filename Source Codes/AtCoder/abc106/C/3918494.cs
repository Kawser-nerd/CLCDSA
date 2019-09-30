using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace C044
{
    class C106
    {
        static void Main(string[] args)
        {
            string S = Console.ReadLine();
            long K = long.Parse(Console.ReadLine());
            char ot = '1';
            int counter = 1;
            foreach (char c in S)
            {
                if (counter > K) break;
                if (c != '1')
                {                    
                    ot = c;
                    break;
                }
                counter++;
            }
            Console.WriteLine(ot);
        }

    }
}