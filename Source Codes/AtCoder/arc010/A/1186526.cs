using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace arc_010_A
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] dye = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int a = dye[0],/*???????????*/
                b = dye[1],/*??*/
              c = dye[2];/*??????*/
            int d = dye[3]/*????*/;
            int hasannisu = 0;
            Boolean hasan = false;
            for (int i = 0; i < b; i++)
            {
                int s = int.Parse(Console.ReadLine());
                if (a <= c) { a += d; }
                a -= s;
                if (a < 0&&!hasan) { hasan = true; hasannisu = i + 1; }
                if (i == b - 1 && !hasan) { Console.WriteLine("complete"); }
            }

            if (hasan) { Console.WriteLine(hasannisu); }
            Console.ReadLine();
        }
    }
}