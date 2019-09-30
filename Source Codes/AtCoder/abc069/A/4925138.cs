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
           
                Console.Write((int.Parse(ary[0])-1)*(int.Parse(ary[1])-1));
            
        }
    }
}