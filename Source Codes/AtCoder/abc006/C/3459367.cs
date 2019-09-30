using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace test1
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] input = Console.ReadLine().Split().Select(int.Parse).ToArray();

            int n = input[0];
            int m = input[1];
            string result = "-1 -1 -1";

            int otona = 0;
            int kodomo = 0;
            int rojin = 0;

            if(m < n*2 || m> n*4)
            {
                goto fin;
            }

            int remain = n * 4 - m;

            otona = remain / 2;
            rojin = remain % 2;
            kodomo = n - otona - rojin;

            result = otona.ToString() + " " + rojin.ToString() + " " + kodomo.ToString();

        fin:
            Console.WriteLine(result);
        }
    }
}