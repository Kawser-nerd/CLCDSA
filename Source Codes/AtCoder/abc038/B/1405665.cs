using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp80
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] HW1 = Console.ReadLine().Split(' ');
            string[] HW2 = Console.ReadLine().Split(' ');
            int H1 = int.Parse(HW1[0]);
            int W1 = int.Parse(HW1[1]);
            int H2 = int.Parse(HW2[0]);
            int W2 = int.Parse(HW2[1]);

            if(H1==H2 || H1 == W2 || W1==H2 || W1==W2)
            {
                Console.WriteLine("YES");
            }
            else
            {
                Console.WriteLine("NO");
            }
        }
    }
}