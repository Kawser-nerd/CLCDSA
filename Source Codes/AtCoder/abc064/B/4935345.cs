using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp3
{
    class Program
    {
        static void Main(string[] args)
        {
            int L = int.Parse(Console.ReadLine());
            var imp = Console.ReadLine().Split(' ');
            Array.Sort(imp);
            
            Console.Write(int.Parse(imp[L - 1]) - int.Parse(imp[0]));
            
            //System.Threading.Thread.Sleep(1000);
        }
    }
    
}