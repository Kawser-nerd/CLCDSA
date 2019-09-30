using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace program
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] list = new string[12];
            int counter = 0;
            for (int i = 0; i < 12; i++)
            {
                list[i] = Console.ReadLine();
                if(list[i].Contains("r"))
                {
                    counter++;
                }
            }
            Console.WriteLine(counter);
        }
    }
}