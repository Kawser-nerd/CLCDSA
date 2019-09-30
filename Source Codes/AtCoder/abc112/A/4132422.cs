using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SoloLearn
{
    class Program
    {
        static void Main(string[] args)
        {
            if(Console.ReadLine()=="1")
            {
                Console.WriteLine("Hello World");
            }
            else
            {
                Console.WriteLine(int.Parse(Console.ReadLine()) + int.Parse(Console.ReadLine()));
            }
            
        }
    }
}