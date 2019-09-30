using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            var imp = Console.ReadLine().Split(' ');
            int plus = (int.Parse(imp[0])) + (int.Parse(imp[1]));
            int minus1 = (int.Parse(imp[0])) - (int.Parse(imp[1]));
            //  int minus2 = (int.Parse(imp[1])) - (int.Parse(imp[0]));
            int ast = (int.Parse(imp[0])) * (int.Parse(imp[1]));

            int[] ans = { plus, minus1, /*minus2 ,*/ ast };
            Array.Sort(ans);

            Console.Write(ans[2]);
        }
    }
}