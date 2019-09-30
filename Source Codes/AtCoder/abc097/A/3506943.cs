using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Atcoder
{
    class _101A
    {
        static void Main(string[] args)
        {
            int[] rawinput = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            int a = rawinput[0]; int b = rawinput[1]; int c = rawinput[2];
            int d = rawinput[3];
            
            if (Math.Abs(a - c) <= d)
            {
                Console.WriteLine("Yes");
                
            }
            else if (Math.Abs(a - b) <= d && Math.Abs(b - c) <= d)
            {
                Console.WriteLine("Yes");
            }
            else
            {
                Console.WriteLine("No");
            }
        }
    }
}