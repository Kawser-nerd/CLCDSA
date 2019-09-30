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
            int[] imp = new int[3];
            var impline = Console.ReadLine().Split(' ');

            for(int i = 0; i < 3; ++i)
            {
                imp[i] = int.Parse(impline[i]);
              
            }

            Array.Sort(imp);
            if (imp[0] == 5 && imp[1] == 5 && imp[2] == 7)
            {
                Console.Write("YES");
            }
            else
            {
                Console.Write("NO");
            }
          

        }
    }
}