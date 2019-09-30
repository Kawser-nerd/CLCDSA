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
            List<long> lucas = new List<long>();
            for (int i = 0; i < 87; i++)
            {
                if (i==0)
                {
                    lucas.Add(2);
                }else if (i ==1)
                {
                    lucas.Add(1);
                }else{
                    lucas.Add(lucas[i-1]+lucas[i-2]);
                }
            }
            Console.WriteLine(lucas[int.Parse(N)]);
        }
    }
}