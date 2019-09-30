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
            string[] ary = Console.ReadLine().Split(' ').ToArray();
            for (int i = 0; i < 3; i++)
            {
                string ARY = ary[i].ToUpper();
                Console.Write(ARY[0]);
            }
        }
    }
}