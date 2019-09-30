using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace ACprac
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] num1 = Console.ReadLine().Split(' ');
            string[] num2 = Console.ReadLine().Split(' ');

            int[] HW = new int[2];
            int[] hw = new int[2];

            HW[0] = int.Parse(num1[0]);
            HW[1] = int.Parse(num1[1]);
            hw[0] = int.Parse(num2[0]);
            hw[1] = int.Parse(num2[1]);

            int ANS1 = (HW[0] - hw[0]);
            int ANS2 = (HW[1] - hw[1]);
            int ANS = ANS1 * ANS2;

            Console.WriteLine(ANS);

        }
    }
}