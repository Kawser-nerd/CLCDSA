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
            string[] imp = Console.ReadLine().Split(' ');
            Array.Sort(imp);
            
            int A=int.Parse(imp[2]);
            int B=int.Parse(imp[1]);
            int C=int.Parse(imp[0]);
            Console.WriteLine(A*10+B+C);
            
            
        }
    }
}