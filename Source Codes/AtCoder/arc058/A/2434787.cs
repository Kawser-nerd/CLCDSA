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
            var s = Console.ReadLine().Split();
            string n = s[0];
            int k = int.Parse(s[1]);

            var d = Console.ReadLine().Split().Select(char.Parse).ToArray();
            

            for (int i = int.Parse(n); i < 10 * int.Parse(n) + 1; i++)
            {
                bool f = true;
                foreach (var item in i.ToString())
                {
                    if(d.Contains(item))
                    {
                        f = false;
                        break;
                    }
                }
                if (f)
                {
                    Console.WriteLine(i);
                    break;
                }
            }
        }
    }
}