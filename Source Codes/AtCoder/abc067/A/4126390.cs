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
            var imp = Console.ReadLine().Split(' ');//???????????????
            int A = Convert.ToInt32(imp[0]);//???????1?????
            int B = Convert.ToInt32(imp[1]);

            int AplsB = A + B;
            if (AplsB % 3 == 0)
            {
                Console.WriteLine("Possible");
            }
            else if (A % 3 == 0)
            {
                Console.WriteLine("Possible");
            }
            else if (B % 3 == 0)
            {
                Console.WriteLine("Possible");
            }
            else {
                Console.WriteLine("Impossible");
            }


            
        }
    }
}