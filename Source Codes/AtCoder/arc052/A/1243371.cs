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
            string a = Console.ReadLine();
            string h = "";
            for(int i = 0; i < a.Length; i++)
            {
                if (a[i] >= '0' && a[i] <= '9')
                    h += a[i];
            }
            Console.WriteLine(h);
        }
    }
}