using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace test
{
    class Program
    {
        static void Main(string[] args)
        {
            String[] str = Console.ReadLine().Split(' ');
            int H = int.Parse(str[0]);
            int W = int.Parse(str[1]);

            var c = new List<String>();

            for(int i = 0; i < H; i++)
            {
                c.Add(Console.ReadLine());
            }
            for (int i = 0; i < H; i++)
            {
                Console.WriteLine(c[i]);
                Console.WriteLine(c[i]);

            }
        }
    }
}