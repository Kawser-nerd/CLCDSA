using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Atcoder
{

    class Atcoderrrrrrr
    {
        static void Main(string[] args)
        {
            string N = Console.ReadLine();
            int obj = 0;
            for (int i = 0; i < N.Length; i++)
            {
                obj += int.Parse(N[i].ToString());
            }
            Console.WriteLine(
                int.Parse(N) % obj == 0?"Yes":"No"
            );
        }
    }
}