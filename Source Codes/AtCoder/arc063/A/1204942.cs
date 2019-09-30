using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace arc_063__A
{
    class Program
    {
        static void Main(string[] args)
        {
            string a = Console.ReadLine();
            int ans = 0;
            for (int i = 0; i < a.Length; i++)
            {
                if (i != 0)
                {
                    if (a[i] == a[i - 1]) { } else { ans++; }
                }
            }Console.WriteLine(ans);
            Console.ReadLine();
        }
    }
}