using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            int T = int.Parse(Console.ReadLine());
            for (int C = 1; C <= T; C++)
            {
                string line = Console.ReadLine();
                string r = "";
                foreach (var c in line)
                {
                    if (r.Length > 0 && c >= r[0])
                        r = c + r;
                    else
                        r += c;
                }
                Console.WriteLine("Case #" + C + ": " + r);
            }
        }
    }
}
